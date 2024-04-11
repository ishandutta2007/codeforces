#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;

    if (n == 1) {
        cout << -1 << '\n';
        return;
    }

    set<int> s;
    for (int i = 0; i < n; i++) s.insert(i);

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (sz(s) == 1 || *s.begin() != a[i]) {
            ans[i] = *s.begin();
        } else {
            ans[i] = *next(s.begin());
        }
        s.erase(ans[i]);
    }
    if (ans[n-1] == a[n-1]) swap(ans[n-1], ans[n-2]);

    for (int x : ans) cout << x+1 << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}