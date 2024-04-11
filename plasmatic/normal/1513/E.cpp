// ./e-cost-equilibrium1.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 1e9 + 7;
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

const int MN = 1e5 + 1;
int N;
ll A[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ll target = 0;
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
        target += A[i];
    }
    if (target % N != 0) return cout << "0\n", 0;
    target /= N;

    map<int, int> overFre, underFre;
    int overCnt = 0, underCnt = 0, atCnt = 0;
    for (auto i = 1; i <= N; i++) {
        if (A[i] > target) overCnt++, overFre[A[i]]++;
        else if (A[i] < target) underCnt++, underFre[A[i]]++;
        else atCnt++;
    }

    init_nchooser(N);
    if (atCnt == N) cout << "1\n";
    else if (overCnt == 1 || underCnt == 1) {
        ll ans = fact[N-atCnt];
        for (auto [_, v] : overFre) ans = fix(ans * invf[v]);
        for (auto [_, v] : underFre) ans = fix(ans * invf[v]);
        cout << fix(ans * choose(N, atCnt)) << '\n';
    }
    else {
        ll overAns = fact[overCnt], underAns = fact[underCnt];
        for (auto [_, v] : overFre) overAns = fix(overAns * invf[v]);
        for (auto [_, v] : underFre) underAns = fix(underAns * invf[v]);

        ll ans = fix(2 * fix(overAns * underAns) * choose(N, atCnt));
        cout << ans << '\n';
    }

    return 0;
}