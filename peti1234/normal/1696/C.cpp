#include <bits/stdc++.h>

using namespace std;
long long n, db;
vector<pair<long long, long long> > sz[2];

void solve() {
    cin >> n >> db;
    for (int j=0; j<2; j++) {
        sz[j].push_back({0, 0});
        for (int i=0; i<n; i++) {
            long long x, cnt=1;
            cin >> x;
            while (x%db==0) {
                x/=db, cnt*=db;
            }
            if (sz[j].back().first!=x) {
                sz[j].push_back({x, 0});
            }
            sz[j].back().second+=cnt;
        }
        if (j==0) {
            cin >> n;
        }
    }
    cout << (sz[0]==sz[1] ? "Yes" : "No") << "\n";
    sz[0].clear(), sz[1].clear();
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
5 2
1 2 2 4 2
4
1 4 4 2
*/