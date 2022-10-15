// ./e-phoenix-and-computers.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ll MOD;
ll fix(ll &&x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fix(ll &x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return fpow(x * x % mod, y >> 1, mod) * ((y & 1) ? x : 1LL) % mod;
}
ll inv(ll x, ll mod = MOD) { return fpow(x, mod - 2, mod); }
// N choose R
vector<ll> fact, invf;
void init_nchooser(int MN) {
    fact.resize(MN + 1); invf.resize(MN + 1);
    fact[0] = 1LL;
    for (int i = 1; i <= MN; i++) fact[i] = fix(fact[i - 1] * i);
    invf[MN] = inv(fact[MN]);
    for (auto i = MN-1; i >= 0; i--) invf[i] = fix(invf[i + 1] * (i + 1));
}
ll choose(ll N, ll K) { return fix(fact[N] * fix(invf[K] * invf[N - K])); }
ll permute(ll N, ll K) { return fix(fact[N] * invf[N - K]); }

const int MN = 401;
int N;
ll dp[MN][MN];

ll comb[MN]; // number of ways to arrange sequence of K computers in a row s.t. no computers autoturnon

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> MOD;
    init_nchooser(N);

    for (auto i = 1; i <= N; i++) {
        for (auto j = 1; j <= i; j++) {
            comb[i] += choose(i-1, j-1);
            fix(comb[i]);
        }
    }

    for (auto i = 1; i <= N; i++)
        dp[i][i] = fix(comb[i] * invf[i]);
    for (auto i = 1; i <= N; i++) {
        for (auto j = 1; j <= i; j++) {
            for (auto k = i+2; k <= N; k++) {
                int addComp = k-i-1;
                dp[k][j+addComp] += dp[i][j] * fix(comb[addComp] * invf[addComp]);
                fix(dp[k][j+addComp]);
            }

            // printf("i=%d j=%d dp=%lld\n", i,j,dp[i][j]);
        }
    }

    ll ans = 0;
    for (auto i = 1; i <= N; i++) {
        // ans += fix(dp[N][i] * fact[i]);
        // fix(ans);
        ans += fix(dp[N][i] * fact[i]);
        fix(ans);
    }

    cout << ans << '\n';

    return 0;
}