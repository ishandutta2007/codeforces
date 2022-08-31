#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    if (std::is_sorted(a.begin(), a.end())) {
        cout << 1 << '\n';
        return;
    }

    vector<bool> use(n);
    vector<int> pre(n);

    int best = -1;
    int start = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, a[i]);
        pre[i] = best;
        if (best == a[i]) {
            use[i] = 1;
            start++;
        }
    }
    pair<int, int> ans{-1, -1};
    for (int i = 0; i < n; i++) if (!use[i]) {
        ans = max(ans, {start, -a[i]});
    }
    for (int i = 0; i < n; i++) if (use[i]) {
        int cur = start - 1;
        int me = (i ? pre[i - 1] : -1);
        for (int j = i+1; j < n && !use[j]; j++) {
            me = max(me, a[j]);
            if (a[j] == me)
                cur++;
        }
        ans = max(ans, {cur, -a[i]});
    }
    cout << -ans.second + 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}