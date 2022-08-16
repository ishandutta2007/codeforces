#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    ll x; cin >> x;
    for (auto& c : a) c -= x;

    ll mx = -MOD;
    ll sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mx == -MOD) {
            sum += a[i];
            mx = 0;
            ans++;
        } else {
            if (sum + a[i] - mx < 0) {
                sum = 0;
                mx = -MOD;
            } else {
                mx = max(mx, sum);
                sum += a[i];
                ans++;
            }
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