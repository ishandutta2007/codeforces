#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& c : a) cin >> c;
    ll ans = std::accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < n; i++) {
        vector<ll> b = a;
        ll cnt = 0, sum = 0;
        for (int j = 0; j < n; j++) if (j != i) {
            while (b[j] % 2 == 0) b[j] /= 2, cnt++;
            sum += b[j];
        }
        ans = max(ans, sum + (a[i] << cnt));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}