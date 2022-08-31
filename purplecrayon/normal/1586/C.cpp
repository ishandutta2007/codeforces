#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;
 
int n, m;
string g[MAXN];
int has[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    // .X
    // X.
    //
    for (int j = 0; j < m-1; j++) {
        for (int i = 1; i < n; i++) {
            if (g[i][j] == 'X' && g[i-1][j+1] == 'X') {
                has[j] = 1;
            }
        }
        if (j) has[j] += has[j-1];
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r, --l, --r;
        if (l == r) {
            cout << "YES\n";
        } else {
            int x = has[r-1] - (l ? has[l-1] : 0);
            if (x) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}