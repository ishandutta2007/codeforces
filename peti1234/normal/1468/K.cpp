#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int w, n, a, b, ua, ub, blx[c], bly[c], ans;
bool jo;
string s;
int main()
{
    cin >> w;
    while(w--) {
        jo=0;
        cin >> s, n=s.size();
        a=0, b=0;
        for (int i=0; i<n; i++) {
            char c=s[i];
            if (c=='U') {
                b++;
            }
            if (c=='D') {
                b--;
            }
            if (c=='L') {
                a--;
            }
            if (c=='R') {
                a++;
            }
            blx[i]=a, bly[i]=b;
        }
        for (int bl=0; bl<n; bl++) {
            a=0, b=0;
            for (int i=0; i<n; i++) {
                ua=a, ub=b;
                char c=s[i];
                if (c=='U') {
                    ub++;
                }
                if (c=='D') {
                    ub--;
                }
                if (c=='L') {
                    ua--;
                }
                if (c=='R') {
                    ua++;
                }
                if (ua!=blx[bl] || ub!=bly[bl]) {
                    a=ua, b=ub;
                }
            }
            if (!a && !b) {
                jo=1, ans=bl;
                break;
            }
        }
        if (!jo) {
            cout << 0 << " " << 0 << "\n";
        } else {
            cout << blx[ans] << " " << bly[ans] << "\n";
        }
    }
    return 0;
}
/*
1
LU
*/