#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e6+10, MOD = 1e9+7;

int n, a[MAXN];
int x[MAXN], c[MAXN];

int mp[MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < MAXN; i++) mp[i] = MOD;

    int ans = 0;
    for (int b = 21; b >= 0; b--) {
        for (int i = 0; i < n; i++) {
            c[i] = (a[i] >> b) & 1;
            x[i] = a[i] & (~((1 << b) - 1));
        }

        for (int i = 0; i < n; i++) if (c[i] == 1) {
            int j = i;
            while (j < n && c[j] == 1) j++;
            j--;

            for (int k = i+1; k <= j; k++) x[k] ^= x[k-1];

            mp[0] = i-1;
            for (int k = i; k <= j; k++) {
                if (mp[x[k]] != MOD) {
                    ans = max(ans, k - mp[x[k]]);
                }
                if (mp[x[k]] == MOD) {
                    mp[x[k]] = k;
                }
            }
            for (int k = i; k <= j; k++) mp[x[k]] = MOD;

            i = j;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}