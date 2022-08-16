#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

// go from the back, if a[i] >= q: q++ else: keep

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int c = 0;
    string ans(n, '0');
    for (int i = n-1; i >= 0; i--) {
        if (a[i] > c) {
            if (c < q) {
                c++;
                ans[i] = '1';
            }
        } else {
            ans[i] = '1';
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