#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<bool> use(n);
    for (int i = n; i >= 1; i--) {
        bool done = 0;
        for (int j = 0; j < n && !done; j++) if (!use[j]) {
            bool bad = 1;
            int x = a[j];
            while (x) {
                if (x == i) {
                    bad = 0;
                    break;
                }
                x /= 2;
            }
            if (!bad) {
                use[j] = 1;
                done = 1;
            }
        }
        if (!done) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}