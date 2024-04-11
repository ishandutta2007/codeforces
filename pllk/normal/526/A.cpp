#include <iostream>

using namespace std;

int n;
string s;

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int d = 1; d < n; d++) {
            int c = 0;
            for (int j = 0; j < 5; j++) {
                if (i+j*d < n && s[i+j*d] == '*') c++;
            }
            if (c == 5) {
                cout << "yes\n";
                return 0;
            }
        }
    }
    cout << "no\n";
}