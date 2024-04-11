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
const int MOD = (int) 1e6 + 3;
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
    vi a(n), b(n);
    vi id(n + n + 1);
    FOR(i, 0, n) cin >> a[i] >> b[i];
    int res = 0;
    FOR(it, 0, 2) {
        vii vals;
        FOR(i, 0, n) {
            if (a[i] < b[i]) {
                vals.pb(mp(a[i], b[i]));
            }
        }
        sort(all(vals), [&] (pi a, pi b) {
                int fa = a.se > b.fi;
                int fb = b.se > a.fi;
                if (fa && fb) {
                return (int) (a.se < b.se);
                }
                else {
                return fa;
                }
                }
            );
        vi fen(n + n + 5);
        auto upd = [&] (int p, int val) {
            p++;
            for (; p < sz(fen); p += p & -p) {
                chkmax(fen[p], val);
            }
        };
        auto query = [&] (int p) {
            p++;
            int res = 0;
            for (; p > 0; p -= p & -p) {
                chkmax(res, fen[p]);
            }
            return res;
        };
        FORd(i, sz(vals), 0) {
            int mx = query(vals[i].se);
            upd(vals[i].fi, mx + 1);
            chkmax(res, mx + 1);
        }
        FOR(i, 0, n) a[i] = n + n + 1 - a[i], b[i] = n + n + 1 - b[i];
    }
    cout << res << "\n";
    FOR(it, 0, 2) {
        FOR(i, 0, n) id[a[i]] = i;
        vii vals;
        FOR(i, 0, n) {
            if (a[i] < b[i]) {
                vals.pb(mp(a[i], b[i]));
            }
        }
        sort(all(vals), [&] (pi a, pi b) {
                int fa = a.se > b.fi;
                int fb = b.se > a.fi;
                if (fa && fb) {
                return (int) (a.se < b.se);
                }
                else {
                return fa;
                }
                }
            );
        vii fen(n + n + 5, mp(0, -1));
        auto upd = [&] (int p, pi val) {
            p++;
            for (; p < sz(fen); p += p & -p) {
                chkmax(fen[p], val);
            }
        };
        auto query = [&] (int p) {
            p++;
            pi res = mp(0, -1);
            for (; p > 0; p -= p & -p) {
                chkmax(res, fen[p]);
            }
            return res;
        };
        vi nxt(n, -1);
        FORd(i, sz(vals), 0) {
            pi mx = query(vals[i].se);
            nxt[i] = mx.se;
            upd(vals[i].fi, mp(mx.fi + 1, i));
            if (mx.fi + 1 == res) {
                vi res;
                int ptr = i;
                while (ptr != -1) {
                    res.pb(id[vals[ptr].fi]);
                    ptr = nxt[ptr];
                }
                FOR(i, 0, sz(res)) {
                    cout << res[i] + 1 << " \n"[i == sz(res) - 1];
                }
                return;
            }
        }
        FOR(i, 0, n) a[i] = n + n + 1 - a[i], b[i] = n + n + 1 - b[i];
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