#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i <= 8; i++) {
        cout << i << "??<>" << (i+1) << "\n";
    }
    cout << "9??>>??0" << endl;
    cout << "??<>1" << endl;
    for (int i = 0; i <= 9; i++) {
        cout << "?" << i << ">>" << i << "?\n";
    }
    for (int i = 0; i <= 8; i++) {
        cout << i << "?<>" << (i+1) << "\n";
    }
    cout << "9?>>9??" << "\n";
    for (int i = 0; i <= 9; i++) {
        cout << i << ">>?" << i << "\n";
    }
}