#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int c1 = 0, c2 = 0, flag = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            c1 += 1;
            c2 = 0;
        }
        else if (s[i] == '1') {
            c1 = 0;
            c2 += 1;
        }
        if (c1 == 7 or c2 == 7) {
            cout << "YES";
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "NO";
    return 0;
}