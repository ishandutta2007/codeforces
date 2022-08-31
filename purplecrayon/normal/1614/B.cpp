#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> p(n); iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) { return a[x] > a[y]; });
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[p[i]] = (i / 2 + 1) * (i % 2 == 0 ? 1 : -1);
    }
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        tot += 2LL * abs(ans[i]) * a[i];
    }
    cout << tot << '\n';

    cout << 0 << ' ';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}