#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    // n - i - a[i]
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> p(n); std::iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](auto x, auto y) {
        return make_pair(n - x - a[x], x) < make_pair(n - y - a[y], y);
    });
    vector<bool> hit(n);
    for (int i = 0; i < k; i++) hit[p[i]] = 1;
    ll ans = 0;
    ll base = 0;
    for (int i = 0; i < n; i++) {
        if (!hit[i])
            ans += base + a[i];
        else
            base++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}