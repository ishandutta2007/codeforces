#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 998244353;

int n, k, m;
ar<ll, 3> a[MAXN], b[MAXN];

ll get() {
    vector<int> delta(n);
    for (int i = 0; i < m; i++) {
        if (b[i][2]) {
            delta[b[i][0]]++;
            if (b[i][1] < n-1) delta[b[i][1]+1]--;
        }
    }

    vector<int> lr(n, -1);
    for (int i = 0; i < m; i++) {
        if (b[i][2]^1) {
            lr[b[i][1]] = max<int>(lr[b[i][1]], b[i][0]);
        }
    }
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (mx >= lr[i]) lr[i] = -1;
        else mx = lr[i];
    }

    vector<int> rng_l, rng_r;
    for (int i = 0; i < n; i++) if (lr[i] != -1) {
        rng_l.push_back(lr[i]);
        rng_r.push_back(i);
    }
    int c = sz(rng_l) | sz(rng_r);

    if (!c) {
        ll ans=1;
        int in_seg = 0;
        for (int i = 0; i < n; i++) {
            in_seg += delta[i];
            if (!in_seg) ans *= 2, ans %= MOD;
        }
        return ans;
    }

    vector<vector<int>> cover(c);
    ll ans = 1;

    int in_seg = 0, pl = 0, pr = 0;
    for (int i = 0; i < n; i++) {
        in_seg += delta[i];
        if (!in_seg) {

            while (pl < c && rng_r[pl] < i) pl++;
            while (pr < c && rng_l[pr] <= i) pr++;

            int l = pl;
            int r = pr-1;
            if (l > r) { ans = ans*2%MOD; continue; }

            cover[r].push_back(l);
        }
    }

    vector<ll> dp(c), ps(c);
    for (int i = 0; i < c; i++) {
        for (auto l : cover[i]) {
            dp[i] += dp[i], dp[i] %= MOD;
            if (!i && !l) {
                dp[i]++, dp[i] %= MOD;
                continue;
            }

            dp[i] += ps[i-1]-(l?ps[l-1]:0);
            if (!l) dp[i]++;
            else dp[i] += dp[l-1];
            dp[i] %= MOD, dp[i] += MOD, dp[i] %= MOD;
        }
        ps[i] = dp[i]+(i?ps[i-1]:0), ps[i] %= MOD;
    }
    return dp[c-1]*ans%MOD;
}
void solve(){
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2], --a[i][0], --a[i][1];
    }
    ll ans=1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            b[j] = a[j];
            b[j][2] = (a[j][2]>>i)&1;
        }
        ll cur = get();
        ans *= cur, ans %= MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}