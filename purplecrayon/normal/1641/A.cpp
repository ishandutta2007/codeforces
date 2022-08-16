#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, x; cin >> n >> x;
    vector<ll> a(n); for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());

    set<pair<ll, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert({a[i], i});
    }
    for (int i = 0; i < n; i++) if (s.count({a[i], i})) {
        auto it = s.lower_bound({a[i] * x, -1});
        if (it == s.end() || it->first != a[i] * x) continue;
        s.erase(it);
        s.erase({a[i], i});
    }
    cout << sz(s) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}