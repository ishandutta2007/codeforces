#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
const int MAXN = 1e3+10, MOD = 1e9+7;

int n, m;
ar<int, 3> qs[MAXN];
bool must[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t, l, r; cin >> t >> l >> r, --l, --r;
        qs[i] = {t, l, r};
        if (t == 1) {
            for (int i = l; i < r; i++) {
                must[i] = 1;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        auto [t, l, r] = qs[i];
        if (t == 0) {
            bool bad = 1;
            for (int i = l; i < r; i++) {
                if (!must[i]) bad = 0;
            }
            if (bad) {
                cout << "NO\n";
                return;
            }
        }
    }
    int M = int(1e9);
    cout << "YES\n";
    cout << M;
    for (int i = 0; i < n-1; i++) {
        cout << ' ';
        if (must[i]) cout << M;
        else cout << (--M);
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}