#include <bits/stdc++.h>

using namespace std;
int n;
string s, p;

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<10; i++) {
        s+="0";
    }
    cin >> n >> p;
    for (int i=0; i<n; i++) {
        char c=p[i];
        if ('0'<=c && c<='9') s[(c-'0')]='0';
        if (c=='L') {
            for (int i=0; i<10; i++) {
                if (s[i]=='0') {
                    s[i]='1';
                    break;
                }
            }
        }
        if (c=='R') {
            for (int i=9; i>=0; i--) {
                if (s[i]=='0') {
                    s[i]='1';
                    break;
                }
            }
        }
    }
    cout << s << "\n";
    return 0;
}