#include <bits/stdc++.h>

using namespace std;
int n, m, p;
char c;
string s;
int main()
{
    cin >> n >> m >> s;
    for (int i=0; i<n; i++) {
        if (i>=m) {
            p=s[i-m];
            if (s[i]=='.') {
                if (p=='1') s[i]='0';
                else s[i]=='1';
            }
            if (s[i]!=p) c=1;
        }
        if (i+m<n) {
            p=s[i+m];
            if (s[i]=='.') {
                if (p=='1') s[i]='0';
                else s[i]=='1';
            }
            if (s[i]!=p) c=1;
        }
        if (s[i]=='.') s[i]='1';
    }
    if (!c) cout << "No";
    else cout << s << "\n";
    return 0;
}