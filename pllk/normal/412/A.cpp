#include <iostream>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;
    if (m-1 < n-m) {
        while (m > 1) {cout << "LEFT\n"; m--;}
        for (int i = 0; i < n; i++) {
            cout << "PRINT " << s[i] << "\n";
            if (i != n-1) cout << "RIGHT\n";
        }
    } else {
        while (m < n) {cout << "RIGHT\n"; m++;}
        for (int i = n-1; i >= 0; i--) {
            cout << "PRINT " << s[i] << "\n";
            if (i != 0) cout << "LEFT\n";
        }
    }
}