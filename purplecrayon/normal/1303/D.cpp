#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;
const int B = 61;

void solve() {
    ll n; int m; cin >> n >> m;
    vector<ll> a(B+1);
    ll sum = 0;
    while (m--) {
        ll x; cin >> x;
        a[63 - __builtin_clzll(x)]++;
        sum += x;
    }
    if (sum < n) {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;
    for (int i = 0; i < B; i++) {
        if ((n >> i) & 1) {
            if (a[i]) a[i]--;
            else {
                int j = i;
                for (; a[j] == 0; j++) ans++;
                a[j]--;
                i = j-1;
                continue;
            }
        }
        a[i+1] += a[i] / 2;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}