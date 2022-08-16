#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    ll n, k; cin >> n >> k;

    ll has = 1;
    const int STEPS = 70;
    ll ans = 0;
    for (int i = 0; i < STEPS && has < n; i++) {
        has += min(has, k);
        ans++;
    }
    ans += (n - has + k - 1) / k;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}