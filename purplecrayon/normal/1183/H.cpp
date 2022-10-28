#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;

int n; ll k;
string s;
ll dp[MAXN][MAXN];

ll add(ll a, ll b) {
    return min(k, a + b);
}
void solve() {
    cin >> n >> k >> s;
    vector<ar<int, 26>> nxt(n+1);
    nxt[n].fill(-1);
    for (int i = n-1; i >= 0; i--) {
        nxt[i] = nxt[i+1];
        nxt[i][s[i] - 'a'] = i;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int l = 0; l <= n; l++) {
            if (dp[i][l] == 0) continue;
            for (int me = 0; me < 26; me++) {
                int x = nxt[i][me];
                if (x == -1) continue;
                dp[x+1][l+1] = add(dp[x+1][l+1], dp[i][l]);
            }
        }
    }
    ll ans = 0;
    for (int l = n; l >= 0; l--) {
        for (int i = 0; i <= n; i++) {
            ll take = min(k, dp[i][l]);
            ans += take * (n - l);
            k -= take;
        }
    }
    if (k) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}