#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
//const int MOD = (int) 1e9 + 7;
const int MOD = 998244353;
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 4000 + 1;
const int maxk = 75 + 1;
int c[maxk][maxk];
int m[2], k;
vi adj[maxn];
int dp[maxn][maxk];
int f[2][maxk];

vi ff(vi a) {
    vi res(maxk);
    res[0] = 1;
    FOR(i, 0, maxk) {
        FOR(j, 0, maxk - i) {
            addmod(res[i + j], mult(res[i], a[j]));
        }
    }
    return res;
}

void dfs(int u, int p) {
    vi g(maxk);
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            FOR(i, 0, maxk - 2) {
                addmod(g[i + 2], dp[v][i]);
            }
        }
    }
    g = ff(g);
    FOR(i, 0, maxk) {
        dp[u][i] = g[i];
    }
}

void u_dfs(int u, int p, vi g, int it) {
    FORd(i, sz(g), 2) g[i] = g[i - 2];
    g[0] = g[1] = 0;
    for (int v : adj[u]) {
        if (v != p) {
            FOR(i, 0, maxk - 2) {
                addmod(g[i + 2], dp[v][i]);
            }
        }
    }
    for (int v : adj[u]) {
        if (v != p) {
            FOR(i, 0, maxk - 2) {
                submod(g[i + 2], dp[v][i]);
            }
            vi ng = ff(g);
            u_dfs(v, u, ng, it);
            FOR(i, 0, maxk - 2) {
                addmod(g[i + 2], dp[v][i]);
            }
        }
    }
    g = ff(g);
    FOR(i, 0, maxk) addmod(f[it][i], g[i]);
}

void phongthan() {
    FOR(i, 0, maxk) c[0][i] = 1;
    FOR(i, 1, maxk) FOR(j, 1, maxk) c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % MOD;
    cin >> m[0] >> m[1] >> k;
    FOR(it, 0, 2) {
        int n = m[it];
        FOR(i, 0, n) adj[i].clear();
        FOR(i, 0, n - 1) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v), adj[v].pb(u);
        }
        dfs(0, -1);
        u_dfs(0, -1, vi(maxk), it);
    }
    int res = 0;
    FOR(i, 0, k + 1) FOR(j, 0, k + 1) if (i + j == k) {
        addmod(res, mult(c[i][i + j], mult(f[0][i], f[1][j])));
    }
    cout << res << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    phongthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}