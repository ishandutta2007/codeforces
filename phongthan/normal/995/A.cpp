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

const int maxn = 100 + 5;
int n, k;
int a[4][maxn];
vector<pair<int, pi> > moves;

void phongthan() {
    cin >> n >> k;
    FOR(i, 0, 4) FOR(j, 0, n) cin >> a[i][j];
    if (k == n + n) {
        FOR(i, 0, n) {
            if (a[0][i] && a[0][i] == a[1][i]) {
                moves.pb(mp(a[1][i], mp(0, i)));
                a[0][i] = a[1][i] = 0;
            }
            if (a[3][i] && a[3][i] == a[2][i]) {
                moves.pb(mp(a[2][i], mp(3, i)));
                a[3][i] = a[2][i] = 0;
            }
        }
        if (!sz(moves)) {
            cout << -1 << "\n";
            return;
        }
    }
    while (1) {
        int sum = 0;
        FOR(i, 1, 3) FOR(j, 0, n) {
            sum += a[i][j];
        }
        if (!sum) break;
        FOR(i, 0, n) {
            if (a[0][i] && a[0][i] == a[1][i]) {
                moves.pb(mp(a[1][i], mp(0, i)));
                a[0][i] = a[1][i] = 0;
            }
            if (a[3][i] && a[3][i] == a[2][i]) {
                moves.pb(mp(a[2][i], mp(3, i)));
                a[3][i] = a[2][i] = 0;
            }
        }
        vii chain;
        FOR(i, 0, n) chain.pb(mp(1, i));
        FORd(i, n, 0) chain.pb(mp(2, i));
        FOR(i, 0, sz(chain)) {
            int u = chain[i].fi;
            int v = chain[i].se;
            if (!a[u][v]) {
                FOR(j, 0, sz(chain) - 1) {
                    int k = (i + j) % sz(chain);
                    int l = (k + 1) % sz(chain);
                    int x = chain[k].fi;
                    int y = chain[k].se;
                    int z = chain[l].fi;
                    int t = chain[l].se;
                    if (a[z][t]) {
                        moves.pb(mp(a[z][t], mp(x, y)));
                        swap(a[x][y], a[z][t]);
                    }
                }
                break;
            }
        }
    }
    cout << sz(moves) << "\n";
    for (auto it : moves) {
        cout << it.fi << " " << it.se.fi + 1 << " " << it.se.se + 1 << "\n";
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
    phongthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}