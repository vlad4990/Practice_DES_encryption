#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <bitset>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_encrypt_clicked();

    void on_pushButton_decrypt_clicked();

    void on_actionClear_Plain_Text_clicked();

    void on_actionClear_Encrypted_Text_clicked();

private:
    Ui::MainWindow *ui;
    QString key = "";
    QString ewIDES(QString plainText, std::string key);
    QString dwIDES(QString encryptedText, std::string key);
    std::vector<std::string> keyPreparation(std::string key);
    std::vector< std::string > textToBinaryAscii(std::string str);
    std::string binaryAsciiToText(std::string str);
    QString DESEncryption(std::string dataBlock, std::vector< std::string > keys);
    std::string charToBinaryAscii(char ch);
    char binaryAsciiToChar(std::string binaryAscii);
    std::string apply_func_E(std::string str);
    std::string apply_func_F(std::string str1, std::string str2);
    std::string apply_xor(std::string str1, std::string str2);
};
#endif // MAINWINDOW_H
