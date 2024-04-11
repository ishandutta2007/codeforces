#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n); for (auto& x : a) cin >> x, --x;
    set<int> s;
    for (int i = 0; i < 2 * n; i++) s.insert(i);

    vector<int> blocks;
    int r = 2*n-1;
    while (sz(s)) {
        int c = *s.rbegin();
        int l = r;
        while (a[l] != c) l--;

        blocks.push_back(r - l + 1);
        for (int i = l; i <= r; i++) s.erase(a[i]);
        r = l - 1;
    }

    vector<bool> dp(n + 1);
    dp[0] = 1;
    for (int x : blocks) {
        for (int i = n; i >= x; i--)
            dp[i] = dp[i] || dp[i-x];
    }
    cout << (dp[n] ? "YES\n" : "NO\n");
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}