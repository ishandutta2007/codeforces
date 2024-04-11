#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, c;
string s, t;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> a >> b >> c >> s;
        t.clear();
        for (int i=0; i<n; i++) {
            t+='0';
        }
        int db=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='S' && a>0) {
                t[i]='R';
                a--;
                db++;
            }
            if (s[i]=='R' && b>0) {
                t[i]='P';
                b--;
                db++;
            }
            if (s[i]=='P' && c>0) {
                t[i]='S';
                c--;
                db++;
            }
        }
        if (2*db<n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=0; i<n; i++) {
                if (t[i]=='0') {
                    if (a) {
                        t[i]='R';
                        a--;
                    } else if (b) {
                        t[i]='P';
                        b--;
                    } else if (c) {
                        t[i]='S';
                        c--;
                    }
                }
                cout << t[i];
            }
            cout << "\n";
        }
    }
    return 0;
}