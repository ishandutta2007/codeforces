#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, a[c], b[c], ert;
map<int, int> m;
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=29; i>=0; i--) {
        int val=ert+(1<<i);
        for (int i=1; i<=n; i++) {
            int x=a[i]&val, y=(b[i]&val)^val;
            m[x]++;
            m[y]--;
        }
        bool jo=1;
        for (auto p:m) {
            if (p.second) {
                jo=0;
            }
        }
        if (jo) {
            ert=val;
        }
        m.clear();
    }
    cout << ert << "\n";
    ert=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
5
1 0 0 3 3
2 3 2 1 0
*/