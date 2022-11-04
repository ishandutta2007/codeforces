#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

int k[4], t[4];

int c[MAXN + 1];

multiset <ll> mst[4];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> k[1] >> k[2] >> k[3];
    cin >> t[1] >> t[2] >> t[3];
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> c[i];
    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= min(n, k[i]); j++)
            mst[i].insert(0);
    }
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        ll val = c[i];
        for(j = 1; j <= 3; j++) {
            val = max(val, *mst[j].begin()) + t[j];
            mst[j].erase(mst[j].begin());
            mst[j].insert(val);
        }
        ans = max(ans, val - c[i]);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}