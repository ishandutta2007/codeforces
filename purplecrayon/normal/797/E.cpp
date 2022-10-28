#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

const int B = 300;

int n, q;
int a[MAXN];
int ans[B][MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int k = 1; k < B; k++) {
        for (int i = n-1; i >= 0; i--) {
            int nxt = i + k + a[i];
            if (nxt >= n) ans[k][i] = 1;
            else ans[k][i] = 1 + ans[k][nxt];
        }
    }
    cin >> q;
    while (q--) {
        int p, k; cin >> p >> k, --p;
        if (k < B) {
            cout << ans[k][p] << '\n';
        } else {
            int c = p;
            int cur = 0;
            while (c < n) {
                c = c + k + a[c];
                cur++;
            }
            cout << cur << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}