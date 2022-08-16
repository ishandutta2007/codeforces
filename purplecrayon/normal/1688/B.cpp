#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int mn = MOD;
    for (int x : a) {
        int cnt = 0;
        while (x % 2 == 0) cnt++, x /= 2;
        mn = min(mn, cnt);
    }
    int ans = 0;
    for (int x : a) if (x % 2 == 0) ans++;
    ans += max(0, mn - 1);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}