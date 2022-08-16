#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int flag = 0;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] < 'A' or s[i] > 'Z') {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' and s[i] <= 'Z')
                s[i] = s[i] + 'a' - 'A';
            else
                s[i] = s[i] + 'A' - 'a';
        }
    }
    cout << s;
}