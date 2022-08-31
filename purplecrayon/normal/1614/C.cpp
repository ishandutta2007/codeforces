#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

const int B = 30;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> ps[B];
    for (int i = 0; i < B; i++) ps[i].assign(n+1, 0);
    for (int i = 0; i < m; i++) {
        int l, r, x; cin >> l >> r >> x, --l, --r;
        for (int j = 0; j < B; j++) if ((x>>j)&1^1) {
            ps[j][l]++;
            ps[j][r+1]--;
        }
    }
    int p[B]={};
    int cnt[B]={};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < B; j++) {
            p[j] += ps[j][i];
            if (p[j] == 0) {
                cnt[j]++;
            }
        }
    }
    vector<ll> po2(max(B + 1, n + 1), 1);
    for (int i = 1; i < sz(po2); i++) po2[i] = 2*po2[i-1]%MOD;
    
    // number of ways to choose a subseq with odd # of values
    ll ans = 0;
    for (int i = 0; i < B; i++) if (cnt[i]) {
        ans += po2[n - 1] * po2[i] % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}