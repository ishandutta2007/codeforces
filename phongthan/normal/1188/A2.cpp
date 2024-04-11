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
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void solve() {
    int n; cin >> n;
    vector<vii> adj(n);
    vi ws(n);
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v >> ws[i]; u--, v--;
        adj[u].pb(mp(v, i)), adj[v].pb(mp(u, i));
    }
    FOR(u, 0, n) if (sz(adj[u]) == 2) {
        cout << "NO\n";
        return;
    }
    function<int(int, int)> find = [&] (int u, int p) {
        if (sz(adj[u]) == 1) return u;
        for (auto e : adj[u]) {
            int v = e.fi;
            if (v ^ p) {
                return find(v, u);
            }
        }
        assert(0);
        return -1;
    };
    function<int(int, int, int, int)> upd = [&] (int u, int p, int v, int w) {
        if (u == v) {
            return 1;
        }
        FOR(i, 0, sz(adj[u])) {
            int nu = adj[u][i].fi;
            int ix = adj[u][i].se;
            if (nu != p && upd(nu, u, v, w)) {
                ws[ix] -= w;
                return 1;
            }
        }
        return 0;
    };
    vector<tuple<int, int, int>> res;
    function<void(int, int)> dfs = [&] (int u, int p) {
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].fi;
            int ix = adj[u][i].se;
            if (v ^ p) {
                vi ver;
                for (auto e2 : adj[u]) {
                    int v2 = e2.fi;
                    if (v2 != v) {
                        ver.pb(v2);
                    }
                }
                int x = ver[0];
                int y = ver[1];
                int t1 = find(v, u);
                int t2 = find(x, u);
                int t3 = find(y, u);
                int t = ws[ix];
                res.pb(make_tuple(t1, t2, t / 2));
                res.pb(make_tuple(t1, t3, t / 2));
                res.pb(make_tuple(t2, t3, -t / 2));
                assert(upd(t1, -1, t2, t / 2));
                assert(upd(t1, -1, t3, t / 2));
                assert(upd(t2, -1, t3, -t / 2));
                dfs(v, u);
            }
        }
    };
    if (n == 2) {
        res.pb(make_tuple(0, 1, ws[adj[0][0].se]));
    }
    else {
        FOR(rt, 0, n) if (3 <= sz(adj[rt])) {
            dfs(rt, -1);
            break;
        }
    }
    cout << "YES\n";
    cout << sz(res) << "\n";
    for (auto e : res) {
        int u, v, w; tie(u, v, w) = e;
        cout << u + 1 << " " << v + 1 << " " << w << "\n";
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}