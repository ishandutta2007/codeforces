#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int ans = 0;
    for (int l : a) {
        int cur = 0;
        for (int r : a) if (l <= r && r <= l + d) cur++;
        ans = max(ans, cur);
    }
    cout << n - ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}