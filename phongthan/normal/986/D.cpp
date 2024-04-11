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

//#define double long double
const int MAXF = 1 << 20;
struct cp {
    double x, y;
    cp(double x = 0, double y = 0) : x(x), y(y) {}
    cp operator + (const cp& rhs) const {
        return cp(x + rhs.x, y + rhs.y);
    }
    cp operator - (const cp& rhs) const {
        return cp(x - rhs.x, y - rhs.y);
    }
    cp operator * (const cp& rhs) const {
        return cp(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
    }
    cp operator !() const {
        return cp(x, -y);
    }
} rts[MAXF + 1];
cp fa[MAXF], fb[MAXF];
cp fc[MAXF], fd[MAXF];

int bitrev[MAXF];
void fftinit() {
    int k = 0; while ((1 << k) < MAXF) k++;
    bitrev[0] = 0;
    for (int i = 1; i < MAXF; i++) {
        bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
    }
    double PI = acos((double) -1.0);
    cp w = cp(cos(2 * PI / MAXF), sin(2 * PI / MAXF));
    rts[0] = rts[MAXF] = cp(1, 0);
    for (int i = 1; i + i <= MAXF; i++) {
        rts[i] = rts[i - 1] * w;
    }
    for (int i = MAXF / 2 + 1; i < MAXF; i++) {
        rts[i] = !rts[MAXF - i];
    }
}
void dft(cp a[], int n, int sign) {
    int d = 0; while ((1 << d) * n != MAXF) d++;
    for (int i = 0; i < n; i++) {
        if (i < (bitrev[i] >> d)) {
            swap(a[i], a[bitrev[i] >> d]);
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        int delta = MAXF / len * sign;
        for (int i = 0; i < n; i += len) {
            cp *x = a + i,*y = a + i + (len >> 1), *w = sign > 0 ? rts : rts + MAXF;
            for (int k = 0; k + k < len; k++) {
                cp z = *y * *w;
                *y = *x - z, *x = *x + z;
                x++, y++, w += delta;
            }
        }
    }
    if (sign < 0) {
        for (int i = 0; i < n; i++) {
            a[i].x /= n;
            a[i].y /= n;
        }
    }
}
void multiply(int a[], int b[], int na, int nb, long long c[]) {
    int n = na + nb - 1; while (n != (n & -n)) n += n & -n;
    for (int i = 0; i < n; i++) fa[i] = fb[i] = cp();
    for (int i = 0; i < na; i++) fa[i] = cp(a[i]);
    for (int i = 0; i < nb; i++) fb[i] = cp(b[i]);
    dft(fa, n, 1);
    for (int i = 0; i < n; i++) fa[i] = fa[i] * fa[i];
    dft(fa, n, -1);
    for (int i = 0; i < n; i++) c[i] = (long long) floor(fa[i].x + 0.5);
}
vector<long long> multiply(vector<int> a, vector<int> b, int mod = (int) 1e9 + 7) {
    static int fa[MAXF], fb[MAXF];
    long long fc[MAXF];
    int na = a.size(), nb = b.size();
    for (int i = 0; i < na; i++) fa[i] = a[i];
    for (int i = 0; i < nb; i++) fb[i] = b[i];
    multiply(fa, fb, na, nb, fc);
    int k = na + nb - 1;
    vector<long long> res(k);
    for (int i = 0; i < k; i++) res[i] = fc[i];
    return res;
}

int isless(vi& a, vi& b) {
    if (sz(a) != sz(b)) return sz(a) < sz(b);
    FORd(i, sz(a), 0) {
        if (a[i] < b[i]) return 1;
        if (a[i] > b[i]) return 0;
    }
    return 0;
}

void mult(vi& num, int k, int base) {
    int carry = 0;
    for (int& x : num) {
        long long nx = (long long) x * k + carry;
        carry = nx / base;
        x = nx % base;
    }
    if (carry) num.pb(carry);
}

vi p3(int k, int base) {
    if (!k) {
        return vi(1, 1);
    }
    if (k & 1) {
        vi res = p3(k - 1, base);
        mult(res, 3, base);
        return res;
    }
    vi res = p3(k >> 1, base);
    vector<long long> v = multiply(res, res, base);
    vi v2;
    long long carry = 0;
    for (long long x : v) {
        long long nx = x + carry;
        v2.pb(nx % base);
        carry = nx / base;
    }
    while (carry) {
        v2.pb(carry % base);
        carry /= base;
    }
    return v2;
}

void phongthan() {
    fftinit();
    const int block = 2;
    string s; cin >> s;
    if (s == "1") {
        cout << 1 << "\n";
        return;
    }
    int st = (sz(s) - 1) * (logl(10) / logl(3));
    st = max(0, st - 1);
    reverse(all(s));
    while (sz(s) % block) s.pb('0');
    vi num;
    for (int i = 0; i < sz(s); i += block) {
        int k = 0;
        for (int j = 0; j < block; j++) {
            k = k * 10 + s[i + block - j - 1] - '0';
        }
        num.pb(k);
    }
    int base = fpow(10, block);
    vi A = p3(st, base);
    int res = INF, cnt = st;
    while (isless(A, num)) {
        vi T = A;
        FOR(i, 0, 3 + 1) {
            if (!isless(T, num)) {
                chkmin(res, 3 * cnt + 2 * i);
            }
            mult(T, 2, base);
        }
        mult(A, 3, base);
        cnt++;
    }
    chkmin(res, 3 * cnt);
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