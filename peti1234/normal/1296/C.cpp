#include <bits/stdc++.h>

using namespace std;
int w, n, x, y, bal, jobb;
string s;
map<pair<int, int>, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        x=0, y=0, bal=-1, jobb=1e9;
        m.clear();
        m[{x, y}]=0;
        for (int i=1; i<=n; i++) {
            char c=(s[i-1]);
            if (c=='U') {
                x--;
            }
            if (c=='D') {
                x++;
            }
            if (c=='L') {
                y--;
            }
            if (c=='R') {
                y++;
            }
            if (m.find({x, y})!=m.end()) {
                int el=m[{x, y}];
                if (i-el<jobb-bal) {
                    bal=el, jobb=i;
                }
            }
            m[{x, y}]=i;
        }
        if (bal==-1) {
            cout << -1 << "\n";
        } else {
            cout << bal+1 << " " << jobb << "\n";
        }
    }
    return 0;
}