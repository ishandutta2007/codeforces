#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> a(s.length(), 0);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'W' and s[i+1] == 'U' and s[i+2] == 'B') {
            a[i] = a[i+1] = a[i+2] = 1;
            i += 2;
        }
    }

    int flag = 0, flag1 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (a[i] == 0) {
            cout << s[i];
            flag = 0;
            flag1 = 1;
        }
        if (a[i] == 1 and flag == 0 and flag1 == 1) {
            cout << " ";
            flag = 1;
        }
    }
    return 0;
}