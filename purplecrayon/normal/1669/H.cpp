#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(31);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        for (int j = 0; j < 31; j++) cnt[j] += (x >> j) & 1;
    }
    ll ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (n - cnt[i] <= k) {
            ans |= 1LL << i;
            k -= n - cnt[i];
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}