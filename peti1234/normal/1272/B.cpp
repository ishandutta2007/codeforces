#include <bits/stdc++.h>

using namespace std;
int w, n, l, r, u, d;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        l=r=u=d=0;
        for (int i=0; i<n; i++) {
            char c=s[i];
            if (c=='L') {
                l++;
            }
            if (c=='R') {
                r++;
            }
            if (c=='U') {
                u++;
            }
            if (c=='D') {
                d++;
            }
        }
        if (min(l, r)==0) {
            d=min(d, 1), u=min(u, 1);
        }
        if (min(d, u)==0) {
            r=min(r, 1), l=min(l, 1);
        }
        d=min(d, u), u=min(d, u);
        l=min(l, r), r=min(l, r);
        cout << l+r+u+d << "\n";
        for (int i=0; i<l; i++) {
            cout << "L";
        }
        for (int i=0; i<d; i++) {
            cout << "D";
        }
        for (int i=0; i<r; i++) {
            cout << "R";
        }
        for (int i=0; i<u; i++) {
            cout << "U";
        }
        cout << "\n";
    }
    return 0;
}