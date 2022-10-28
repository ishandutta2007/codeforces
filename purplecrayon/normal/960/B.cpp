#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    int k1, k2; cin >> k1 >> k2;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (auto& x : a) {
        int y; cin >> y;
        x -= y;
        x = abs(x);
    }
    int k = k1 + k2;
    while (k--) {
        sort(a.begin(), a.end());
        if (a[n-1] > 0) {
            a[n-1]--;
        } else {
            a[n-1]++;
        }
    }
    ll ans = 0;
    for (auto& x : a) ans += (long long) x * x;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}