#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    int one = 1, two = 1;
    for (int x = (n - 1) / 7; x > 0; x /= 7)
        one++;

    for (int x = (m - 1) / 7; x > 0; x /= 7)
        two++;

    if (one + two <= 7) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt[7]={};
                for (int x = i, c = 0; c < one; x /= 7, c++) {
                    cnt[x % 7]++;
                }
                for (int x = j, c = 0; c < two; x /= 7, c++) {
                    cnt[x % 7]++;
                }
                bool bad = 0;
                for (int k = 0; k < 7; k++) {
                    if (cnt[k] >= 2)
                        bad = 1;
                }
                ans += !bad;
            }
        }
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
        return;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}