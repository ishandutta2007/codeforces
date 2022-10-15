#include <iostream>

using namespace std;

int k;

int main() {
    cin >> k;
    if (k%2 == 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int n = (k-1)*4+2;
    int m = (n*k)/2;
    cout << n << " " << m << "\n";
        for (int a = 0; a < k-1; a++) {
            for (int b = 0; b < k-1; b++) {
                cout << 1+a << " " << k+b << "\n";
            }
        }
        for (int a = 0; a < k-1; a++) {
            for (int b = 0; b < k-1; b++) {
                cout << (k-1)*2+1+a << " " << (k-1)*2+k+b << "\n";
            }
        }
        for (int a = 0; a < k-1; a++) {
            cout << (k-1)*4+1 << " " << a+1 << "\n";
        }
        for (int a = 0; a < k-1; a++) {
            cout << (k-1)*4+2 << " " << (k-1)*2+a+1 << "\n";
        }
        for (int a = 0; a < k-1; a += 2){
            cout << k+a << " " << k+a+1 << "\n";
        }
        for (int a = 0; a < k-1; a += 2){
            cout << (k-1)*2+k+a << " " << (k-1)*2+k+a+1 << "\n";
        }
        cout << (k-1)*4+1 << " " << (k-1)*4+2 << "\n";
}