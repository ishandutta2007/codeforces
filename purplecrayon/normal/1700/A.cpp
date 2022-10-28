#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

ll sum(ll start, ll diff, ll n) {
    return start * n + diff * n * (n - 1) / 2;
}
void solve() {
    ll n, m; cin >> n >> m;
    ll ans = sum(1, 1, m - 1) + sum(m, m, n);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}