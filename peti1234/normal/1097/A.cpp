#include <bits/stdc++.h>

using namespace std;
string s[6];
int main()
{
    for (int i=0; i<6; i++) {
        cin >> s[i];
    }
    for (int i=1; i<6; i++) {
        if (s[0][0]==s[i][0] || s[0][1]==s[i][1]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}