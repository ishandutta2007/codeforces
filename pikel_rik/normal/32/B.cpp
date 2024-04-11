#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    string temp;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.')
            temp.push_back('0');
        else if (i + 1 < n and s[i] == '-' and s[i+1] == '.') {
            temp.push_back('1');
            i += 1;
        }
        else if (i + 1 < n and s[i] == '-' and s[i+1] == '-') {
            temp.push_back('2');
            i += 1;
        }
    }

    cout << temp;
    return 0;
}