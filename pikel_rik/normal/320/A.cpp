#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (i+2 < n and s[i] == '1' and s[i+1] == '4' and s[i+2] == '4')
            i += 2;
        else if (i+1 < n and s[i] == '1' and s[i+1] == '4')
            i += 1;
        else if (s[i] == '4' or (s[i] != '1' and s[i] != '4')) {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}