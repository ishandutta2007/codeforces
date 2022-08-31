#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;
const ll INF = 1e18+10;

void solve() {
    int n; cin >> n;
    vector<ar<ll, 2>> a(n); for (auto& [x, y] : a) cin >> x >> y;

    vector<ll> cost(n);
    for (int i = 0; i < n; i++) {
        cost[i] = max(0LL, (long long) a[i][0] - a[(i + n - 1) % n][1]);
    }
    ll sum = 0;
    for (ll x : cost)
        sum += x;

    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, sum - cost[i] + a[i][0]);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}