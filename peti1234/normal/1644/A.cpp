#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        bool jo=1;
        for (int i=0; i<6; i++) {
            if (s[i]=='R') jo=0;
            if (s[i]=='r') break;
        }
        for (int i=0; i<6; i++) {
            if (s[i]=='G') jo=0;
            if (s[i]=='g') break;
        }
        for (int i=0; i<6; i++) {
            if (s[i]=='B') jo=0;
            if (s[i]=='b') break;
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}