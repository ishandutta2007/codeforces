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

template<class T> struct ChineseRemainder {
    static const int MAXN = 1e5 + 5;
    int n;
    T p[MAXN], r[MAXN];
    T b[MAXN], x[MAXN];

    void init() {
        n = 0;
    }
    void add(T pr, T rm) {
        p[n] = pr, r[n++] = rm;
    }
    T mulmod(T a, T b, T p) {
    	a %= p, b %= p;
    	T q = (T) ((long double) a * b / p);
        T r = a * b - q * p;
        while (r < 0) r += p;
        while (r >= p) r -= p;
        return r;
    }
    pair<T, T> euclid(T a, T b) {
    	if (!b) return make_pair(1, 0);
    	pair<T, T> r = euclid(b, a % b);
    	return make_pair(r.second, r.first - a / b * r.second);
    }
    T calc() {
    	T M = 1;
    	for (int i = 0; i < n; i++) M *= p[i];
    	T N = 0;
    	for (int i = 0; i < n; i++) {
    		b[i] = M / p[i];
    		x[i] = (euclid(b[i], p[i]).first % p[i] + p[i]) % p[i];
    		N += mulmod(r[i] * b[i], x[i], M);
    		if (N >= M) N -= M;
    	}
    	return N;
    }
};
ChineseRemainder<long long> crt;

const int pr[3] = {1004535809, 1007681537, 1012924417}; //2 ^ 20 * {958, 961, 966} + 1
const int pw[3] = {3, 3, 5}; //primitive roots
struct NTT {
    static const int MAXF = 1 << 20;
    int pr;
    int rts[MAXF + 1];
    int bitrev[MAXF];
    int iv[MAXF + 1];

    int fpow(int a, int k, int p) {
        if (!k) return 1;
        int res = a, tmp = a;
        k--;
        while (k) {
            if (k & 1) {
                res = (long long) res * tmp % p;
            }
            tmp = (long long) tmp * tmp % p;
            k >>= 1;
        }
        return res;
    }
    void init(int pr, int pw) {
        this->pr = pr;
        int k = 0; while ((1 << k) < MAXF) k++;
        bitrev[0] = 0;
        for (int i = 1; i < MAXF; i++) {
            bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
        }
        pw = fpow(pw, (pr - 1) / MAXF, pr);
        rts[0] = 1;
        for (int i = 1; i <= MAXF; i++) {
            rts[i] = (long long) rts[i - 1] * pw % pr;
        }
        for (int i = 1; i <= MAXF; i <<= 1) {
            iv[i] = fpow(i, pr - 2, pr);
        }
    }
    void dft(int a[], int n, int sign) {
        int d = 0; while ((1 << d) * n != MAXF) d++;
        for (int i = 0; i < n; i++) {
            if (i < (bitrev[i] >> d)) {
                swap(a[i], a[bitrev[i] >> d]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int delta = MAXF / len * sign;
            for (int i = 0; i < n; i += len) {
                int *w = sign > 0 ? rts : rts + MAXF;
                for (int k = 0; k + k < len; k++) {
                    int &a1 = a[i + k + (len >> 1)], &a2 = a[i + k];
                    int t = (long long) *w * a1 % pr;
                    a1 = a2 - t;
                    a2 = a2 + t;
                    a1 += a1 < 0 ? pr : 0;
                    a2 -= a2 >= pr ? pr : 0;
                    w += delta;
                }
            }
        }
        if (sign < 0) {
            int in = iv[n];
            for (int i = 0; i < n; i++) {
                a[i] = (long long) a[i] * in % pr;
            }
        }
    }
    void multiply(int a[], int b[], int na, int nb, int c[]) {
        static int fa[MAXF], fb[MAXF];
        int n = na + nb - 1; while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = 0;
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        dft(fa, n, 1), dft(fb, n, 1);
        for (int i = 0; i < n; i++) fa[i] = (long long) fa[i] * fb[i] % pr;
        dft(fa, n, -1);
        for (int i = 0; i < n; i++) c[i] = fa[i];
    }
    vector<int> multiply(vector<int> a, vector<int> b) {
        static int fa[MAXF], fb[MAXF], fc[MAXF];
        int na = a.size(), nb = b.size();
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        multiply(fa, fb, na, nb, fc);
        int k = na + nb - 1;
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = fc[i];
        return res;
    }
} ntt;

const int maxn = 2e5 + 5;
int n, x;
int a[maxn];

vi work(int t) {
    ntt.init(pr[t], pw[t]);
    vi v1; v1.pb(0);
    FOR(i, 0, n) if (a[i]) v1.pb(i + 1);
    v1.pb(n + 1);
    vi v2 = v1; reverse(all(v2));
    vi r = ntt.multiply(v1, v2);
    int m = sz(v1);
    vi res(m - 1);
    FOR(k, 1, m - 1) {
        addmod(res[k], r[m - k - 1], pr[t]);
        submod(res[k], mult(v1[0], v1[k], pr[t]), pr[t]);
        addmod(res[k], r[m - k - 1], pr[t]);
        submod(res[k], mult(v1[m - k - 1], v1[m - 1], pr[t]), pr[t]);
        submod(res[k], r[m - k - 2], pr[t]);
        submod(res[k], r[m - k], pr[t]);
        addmod(res[k], mult(v1[0], v1[k - 1], pr[t]), pr[t]);
        addmod(res[k], mult(v1[m - k], v1[m - 1], pr[t]), pr[t]);

    }
    return res;
}

void phongthan() {
    cin >> n >> x;
    FOR(i, 0, n) {
        cin >> a[i], a[i] = a[i] < x;
    }
    static int f[2][maxn];
    FOR(i, 0, 2) {
        vi res = work(i);
        int sum = (long long) n * (n + 1) / 2 % pr[i];
        FOR(j, 1, sz(res)) {
            f[i][j] = res[j];
            submod(sum, res[j], pr[i]);
        }
        f[i][0] = sum;
    }
    FOR(i, 0, n + 1) {
        crt.init();
        crt.add(pr[0], f[0][i]);
        crt.add(pr[1], f[1][i]);
        cout << crt.calc() << " \n"[i == n];
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