#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first 
#define se second
#define all(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())
#define mid ((l + r) / 2)
#define lc o * 2
#define rc o * 2 + 1
#define lch l, mid, lc
#define rch mid + 1, r, rc
#define cmi(a, b) (a = min(a, b))
#define cma(a, b) (a = max(a, b))
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define pop __builtin_popcount
#define llpop __builtin_popcountll
#define ctz __builtin_ctz
#define llctz __builtin_ctzll
#define clz __builtin_clz
#define llclz __builtin_clzll
#define par __builtin_parity
#define llpar __builtin_parityll

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned ll;
using lf = double;
// using P = pair<int, int>;
using V = vector<int>;
// using cmp = complex<lf>;

const int N = 2e5 + 5, M = 4e5;
const ll P = 998244353;

int n, m;
int rt, sz, ls[N], rs[N], c[N], t[N], s[N];
ll J[N * 2], iJ[N * 2];
ll Pow(ll a, int n, ll r = 1) {
    for(; n; n /= 2, a = a * a % P)
    if(n & 1) r = r * a % P;
    return r;
}
int C(int n, int m) { return J[n] * iJ[m] % P * iJ[n - m] % P; }
ll gen(ll x) {
    const ll k = 0x9ddfea08eb382d69ull;
    rep(i, 1, 3) x *= k, x ^= x >> 47;
    return x * k;
}
int rnd() {
    static ll s = 2;
    return (s += gen(s)) & INT_MAX;
}
int pu(int o) { s[o] = s[ls[o]] + s[rs[o]] + 1; return o; }
void put(int o, int v) { c[o] += v, t[o] += v; }
void pd(int o) { if(t[o]) put(ls[o], t[o]), put(rs[o], t[o]), t[o] = 0; }
void spt(int o, int x, int& u, int& v) {
    if(!o) return void(u = v = 0);
    pd(o);
    if(x < c[o]) spt(ls[v = o], x, u, ls[o]), pu(o);
    else spt(rs[u = o], x, rs[o], v), pu(o);
}
int mrg(int u, int v) {
    if(!u || !v) return u + v;
    pd(u), pd(v);
    if(rnd() % (s[u] + s[v]) < s[u])
        return rs[u] = mrg(rs[u], v), pu(u);
    return ls[v] = mrg(u, ls[v]), pu(v);
}

void solve() {
    scanf("%d%d", &n, &m);
    int x, y;
    while(m--) {
        scanf("%d%d", &x, &y);
        int u, v, mi, f = 0;
        spt(rt, y - 1, u, v);
        if(v) {
	        for(mi = v; ls[mi]; pd(mi), mi = ls[mi]);
	        f = c[mi] > y;
	    } else f = 1;
	    put(v, 1);
	    if(f) sz++, c[sz] = y + 1, s[sz] = 1, rt = mrg(u, mrg(sz, v));
	    else rt = mrg(u, v);
    }
    printf("%d\n", C(n * 2 - 1 - sz, n));
    rep(i, 1, sz) ls[i] = rs[i] = t[i] = 0;
    sz = rt = 0;
}
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    rep(i, 0, M) J[i] = i ? J[i - 1] * i % P : 1;
    per(i, M + 1, 1) iJ[i - 1] = i > M ? Pow(J[M], P - 2) : iJ[i] * i % P;
    int T;
    for(cin >> T; T--; solve());
}