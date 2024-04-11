#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, adb, bdb;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> s;
        n=a+b;
        adb=bdb=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='?') {
                if (s[n-i-1]!='?') {
                    s[i]=s[n-i-1];
                }
            }
            if (s[i]=='0') {
                adb++;
            }
            if (s[i]=='1') {
                bdb++;
            }
        }
        if (n%2 && s[n/2]=='?') {
            if (a%2) {
                s[n/2]='0';
                adb++;
            } else {
                s[n/2]='1';
                bdb++;
            }
        }
        for (int i=0; i<n; i++) {
            if (s[i]=='?') {
                if (adb<a) {
                    s[i]='0';
                    s[n-i-1]='0';
                    adb+=2;
                } else {
                    s[i]='1';
                    s[n-i-1]='1';
                    bdb+=2;
                }
            }
        }
        bool baj=0;
        if (a!=adb || b!=bdb) {
            baj=1;
        }
        for (int i=0; i<n; i++) {
            if (s[i]!=s[n-i-1]) {
                baj=1;
            }
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            cout << s << "\n";
        }
    }
    return 0;
}
/*
1
0 3
1?1
*/