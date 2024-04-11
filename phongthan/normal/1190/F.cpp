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
 
namespace Pollard {
    template<typename num_t>
    num_t mulmod(num_t a, num_t b, num_t p) {
        a %= p; b %= p;
        num_t q = (num_t) ((long double) a * b / p);
        num_t r = a * b - q * p;
        while (r < 0) r += p;
        while (r >= p) r -= p;
        return r;
        /*
        num_t r = 0;
        int block = 1;
        num_t base = 1LL << block;
        for (; b; b >>= block) {
            r = (r + a * (b & (base - 1))) % p;
            a = a * base % p;
        }
        return r;
        */
    }
    template<typename num_t>
    num_t powmod(num_t n, num_t k, num_t p) {
        num_t r = 1;
        for (; k; k >>= 1) {
            if (k & 1) r = mulmod(r, n, p);
            n = mulmod(n, n, p);
        }
        return r;
    }
    template<typename num_t>
    int rabin(num_t n) {
        if (n == 2) return 1;
        if (n < 2 || !(n & 1)) return 0;
        const num_t p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        num_t a, d = n - 1, mx = 9;
        int i, r, s = 0;
        while (!(d & 1)) {++s; d >>= 1;}
        for (i = 0; i < mx; i++) {
            if (n == p[i]) return 1;
            if (!(n % p[i])) return 0;
            a = powmod(p[i], d, n);
            if (a != 1) {
                for (r = 0; r < s && a != n - 1; r++) a = mulmod(a, a, n);
                if (r == s) return 0;
            }
        }
        return 1;
    }
    template<typename num_t>
    inline num_t f(num_t a, num_t b, num_t n) {
        return (mulmod(a, a, n) + b) % n;
    }
    template<typename num_t>
    void factorize(num_t n, vector<num_t>& facs) {
        static int init_seed = 0;
        if (!init_seed) {
            init_seed = 1;
            srand(2311);
        }
        if (n == 1) {
            return;
        }
        if (rabin(n)) {
            facs.push_back(n);
            return;
        }
        if (n == 4) {
            facs.push_back(2);
            facs.push_back(2);
            return;
        }
        while (1) {
            num_t a = rand() & 63, x = 2, y = 2;
            while (1) {
                x = f(x, a, n), y = f(f(y, a, n), a, n);
                if (x == y) break;
                num_t p = __gcd(n, y <= x ? x - y : y - x);
                if (p > 1) {
                    factorize(p, facs), factorize(n / p, facs);
                    return;
                }
            }
        }
    }
}
 
void solve() {
    int n;
    long long m, p; cin >> n >> m >> p;
    long long mm = m;
    if (1 < __gcd(p, m)) {
        vector<long long> res;
        FOR(i, 0, min(mm, (long long) INF)) if (i ^ 1) {
            if (sz(res) == n) {
                break;
            }
            if (__gcd((long long) i, m) == 1) {
                res.pb(i);
            }
        }
        if (sz(res) < n) {
            cout << -1 << "\n";
            return;
        }
        FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
        return;
    }
    int k = 0;
    for (int i = 2; (long long) i * i * i <= m; i++) {
        if (m % i == 0) {
            while (m % i == 0) {
                m /= i;
                k++;
            }
            m = i;
            break;
        }
    }
    if (!k) {
        long long x = isqrt(m);
        if (x * x == m) {
            m = x;
            k = 2;
        }
        else {
            k = 1;
        }
    }
    if (m == 2) {
        if (mm <= 1e7) {
            vi use(mm);
            int t = 1;
            FOR(i, 0, mm / 2) {
                t = mult(t, p, mm);
                use[t] = 1;
            }
            vector<long long> res;
            FOR(i, 0, mm) {
                if (sz(res) == n) {
                    break;
                }
                if (!use[i] && i % 2 == 1) {
                    res.pb(i);
                }
            }
            if (sz(res) < n) {
                cout << -1 << "\n";
                return;
            }
            FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
            return;
        }
        vi use(8);
        FOR(i, 0, 10) {
            int x = Pollard::powmod(p % 8LL, (long long) i, 8LL);
            use[x] = 1;
        }
        vector<long long> res;
        for (int i = 0; i < mm; i++) {
            if (sz(res) == n) {
                break;
            }
            if (!use[i % 8] && i % 2 == 1) {
                res.pb(i);
            }
        }
        if (sz(res) < n) {
            cout << -1 << "\n";
            return;
        }
        FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
        return;
    }
    long long phi = m - 1;
    FOR(i, 0, k - 1) phi *= m;
    vector<long long> facs;
    Pollard::factorize(m - 1, facs);
    map<long long, int> hs;
    for (long long x : facs) {
        hs[x]++;
    }
    FOR(i, 0, k - 1) {
        hs[m]++;
    }
    vector<pair<long long, int>> vals;
    for (auto e : hs) {
        vals.pb(e);
    }
    vector<long long> dvs;
    function<void(long long, int, int)> rec = [&] (long long t, int k, int new_) {
        if (new_) {
            dvs.pb(t);
        }
        if (k == sz(vals)) {
            return;
        }
        rec(t, k + 1, 0);
        FOR(i, 0, vals[k].se) {
            t *= vals[k].fi;
            rec(t, k + 1, 1);
        }
    };
    rec(1, 0, 1);
    sort(all(dvs)), uni(dvs);
    auto find_order = [&] (long long k) {
        FOR(i, 0, sz(dvs)) {
            if (Pollard::powmod(k, dvs[i], mm) == 1) {
                return dvs[i];
            }
        }
        assert(0);
        return -1LL;
    };
    long long w = -1;
    FOR(i, 2, 1e5) if (__gcd((long long) i , m) == 1) {
        if (find_order(i) == dvs.back()) {
            w = i;
            break;
        }
    }
    assert(w != -1);
    long long t = phi / find_order(p);
    if (t == 1) {
        cout << -1 << "\n";
        return;
    }
    vector<long long> res;
    for (int i = 0; i < phi; i++) {
        if (sz(res) == n) {
            break;
        }
        if (i % t) {
            res.pb(Pollard::powmod(w, (long long) i, mm));
        }
    }
    if (sz(res) < n) {
        cout << -1 << "\n";
        return;
    }
    FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
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