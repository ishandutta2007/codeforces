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

const int maxn = 1e6 + 5;
int st[maxn << 2];
int lz[maxn << 2];

void push(int p, int L, int R) {
    if (lz[p]) {
        st[p] += lz[p];
        if (L < R) {
            FOR(i, p << 1, p + 1 << 1) {
                lz[i] += lz[p];
            }
        }
        lz[p] = 0;
    }
}

void upd(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[p] = val;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = max(st[p << 1], st[p << 1 | 1]);
}

int query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (R < l || r < L) return -INF;
    if (l <= L && R <= r) return st[p];
    return max(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    FOR(i, 0, n) cin >> a[i], upd(1, 0, a[i], 0, maxn - 1, +1);
    FOR(i, 0, m) cin >> b[i], upd(1, 0, b[i], 0, maxn - 1, -1);
    int q; cin >> q;
    while (q--) {
        int op, u, x; cin >> op >> u >> x; u--;
        if (op == 1) {
            upd(1, 0, a[u], 0, maxn - 1, -1);
            a[u] = x;
            upd(1, 0, a[u], 0, maxn - 1, +1);
        }
        else {
            upd(1, 0, b[u], 0, maxn - 1, +1);
            b[u] = x;
            upd(1, 0, b[u], 0, maxn - 1, -1);
        }
        int lo = 0, hi = maxn - 1;
        while (lo < hi) {
            int mi = lo + hi + 1 >> 1;
            if (0 < query(1, mi, maxn - 1, 0, maxn - 1)) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        int res = lo + hi >> 1;
        if (!res) res = -1;
        cout << res << "\n";
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