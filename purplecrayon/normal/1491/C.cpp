#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

// always start from 1
void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    vector<ll> has(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll need = max(has[i], a[i] - 1);
        ans += need - has[i];
        has[i] = need;
        ll L = a[i] - has[i] + 1;
        int R = min((long long) n - i - 1, a[i]);
        for (int j = max(1LL, L); j <= R; j++) {
            if (j == 1) has[i + j] += j - L + 1;
            else has[i + j]++;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}