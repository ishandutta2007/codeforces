#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    ll mx = *max_element(a.begin(), a.end());
    ll g = 0;
    for (int i = 1; i < n-1; i++) {
        g = std::gcd(g, abs(a[i+1] + a[i-1] - 2*a[i]));
    }
    if (g == 0) {
        cout << 0 << '\n'; // special case
        return;
    }
    if (g < mx) {
        cout << -1 << '\n';
        return;
    }
    cout << g << ' ' << (a[1] - a[0] + g) % g << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}