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

struct point_t {
    int x, y;
    point_t(int x = 0, int y = 0) : x(x), y(y) {}
    point_t operator - (const point_t& rhs) {
        return point_t(x - rhs.x, y - rhs.y);
    }
};

long long cross(point_t a, point_t b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}
int scross(point_t a, point_t b) {
    long long cr = cross(a, b);
    return cr < 0 ? -1 : cr > 0;
}
int insect(point_t a, point_t b, point_t c, point_t d) {
    int s1 = scross(c - a, d - a) * scross(c - b, d - b);
    int s2 = scross(a - c, b - c) * scross(a - d, b - d);
    return s1 <= 0 && s2 <= 0;
}
long long area(point_t a, point_t b, point_t c) {
    return abs(cross(a, b) + cross(b, c) + cross(c, a));
}
int inside(point_t q, point_t a, point_t b, point_t c, point_t d) {
    return area(q, a, b) + area(q, b, c) + area(q, c, d) + area(q, d, a) == area(a, b, d) + area(c, b, d);
}

void phongthan() {
    point_t a[4], b[4];
    FOR(i, 0, 4) cin >> a[i].x >> a[i].y;
    FOR(i, 0, 4) cin >> b[i].x >> b[i].y;
    FOR(i, 0, 4) {
        if (inside(a[i], b[0], b[1], b[2], b[3])) {
            cout << "YES\n";
            return;
        }
        if (inside(b[i], a[0], a[1], a[2], a[3])) {
            cout << "YES\n";
            return;
        }
    }
    FOR(i, 0, 4) FOR(j, 0, 4) {
        int ii = (i + 1) % 4;
        int jj = (j + 1) % 4;
        if (insect(a[i], a[ii], b[j], b[jj])) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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