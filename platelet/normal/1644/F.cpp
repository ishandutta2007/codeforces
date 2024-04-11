#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define ymm __m256i

using namespace std;
using ll = uint64_t;

const int N = 2e5 + 5, P = 998244353;

int n, k, pid, mu[N], prm[18000];
int p[N], q[N];
int pw[N], fac[N], ifac[N], B[N];

int Pow(int a, int n, int r = 1) {
    for(; n; n >>= 1, a = (ll)a * a % P) if(n & 1) r = (ll)r * a % P;
    return r;
}
int calc(int n) {
    k = min(n, k);
    pw[1] = 1;
    for(int i = 1; i <= pid && prm[i] <= k; i++) pw[prm[i]] = Pow(prm[i], n);
    rep(i, 1, k) if(p[i]) pw[i] = (ll)pw[p[i]] * pw[q[i]] % P;
    __int128 res = P - 1;
    rep(i, 0, k) res += (ll)pw[i] * ifac[i] % P * B[k - i];
    return res % P;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    if(n == 1 || k == 1) cout << 1, exit(0);
    mu[1] = 1;
    rep(i, 2, n) {
        if(!p[i]) prm[++pid] = i, mu[i] = -1;
        for(int j = 1; i * prm[j] <= n; j++) {
            p[i * prm[j]] = prm[j], q[i * prm[j]] = i;
            if(i % prm[j] == 0) break;
            mu[i * prm[j]] = -mu[i];
        }
    }
    rep(i, 0, n) fac[i] = i ? (ll)fac[i - 1] * i % P : 1;
    per(i, n + 1, 1) ifac[i - 1] = i > n ? Pow(fac[n], P - 2) : (ll)ifac[i] * i % P;
    rep(i, 0, k) B[i] = i & 1 ? P - ifac[i] : ifac[i];
    rep(i, 1, k) if((B[i] += B[i - 1]) >= P) B[i] -= P;
    int ans = 0, ls = 0, val = 0;
    rep(i, 1, n) {
        int v = (n + i - 1) / i;
        if(v != ls) val = calc(v), ls = v;
        if(mu[i] == 1) if((ans += val) >= P) ans -= P;
        if(mu[i] == -1) if((ans -= val) < 0) ans += P;
    }
    cout << ans;
}