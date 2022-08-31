#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    ar<int, 2> last{-1, -1};
    bool bad = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (last[x % 2] > x) {
            bad = 1;
        }
        last[x % 2] = x;
    }
    if (bad) cout << "NO\n";
    else cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}