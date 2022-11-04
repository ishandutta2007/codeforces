#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;


const int MAXN = (int) 1e5;
const int MOD = (int) 1e9 + 7;

pair <int, int> seg[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> x >> y;
    for(i = 1; i <= n; i++) {
        cin >> seg[i].first >> seg[i].second;
    }
    sort(seg + 1, seg + n + 1);
    multiset <int> mst;
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        multiset <int> :: iterator it = mst.lower_bound(seg[i].first);
        if(it == mst.begin()) {
            ans += x + 1LL * y * (seg[i].second - seg[i].first);
        }
        else {
            it--;
            if(1LL * y * (seg[i].second - *it) < x + 1LL * y * (seg[i].second - seg[i].first)) {
                ans += 1LL * y * (seg[i].second - *it);
                mst.erase(it);
            }
            else {
                ans += x + 1LL * y * (seg[i].second - seg[i].first);
            }
        }
        mst.insert(seg[i].second);
        ans %= MOD;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}