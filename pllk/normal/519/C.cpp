#include <iostream>

using namespace std;

int n, m;
int c;

int main() {
    cin >> n >> m;
    while (true) {
        if (n > m) {
            if (m >= 1) {n -= 2; m -= 1; c++;}
            else break;
        } else if (n < m) {
            if (n >= 1) {m -= 2; n -= 1; c++;}
            else break;
        } else {
            if (n >= 2) {n -= 2; m -= 1; c++;}
            else break;
        }
    }
    cout << c << "\n";
}