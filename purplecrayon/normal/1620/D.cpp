#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int ans = MOD;
    for (int x = 0; x <= 1; x++) {
        for (int y = 0; y <= 2; y++) {
            int cans = 0;
            for (int i = 0; i < n; i++) {
                int cur = MOD;
                for (int ux = 0; ux <= x; ux++) {
                    for (int uy = 0; uy <= y; uy++) {
                        int need = a[i] - 1 * ux - 2 * uy;
                        if (need % 3 || need < 0) continue;
                        cur = min(cur, need / 3);
                    }
                }
                cans = max(cans, cur);
            }
            ans = min(ans, cans + x + y);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}