#include <iostream>

using namespace std;

string s;

int main() {
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            i += 2;
            b = 1;
        } else {
            if (b) {
                if (a) cout << " ";
                b = 0;
            }
            cout << s[i];
            a = 1;
        }
    }
    cout << endl;
}