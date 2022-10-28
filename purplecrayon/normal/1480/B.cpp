#include <bits/stdc++.h>
using namespace std;
 
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<vector<int>>;
using VVL = vector<vector<ll>>;
using PII = pair<int,int>;
using PLL = pair<ll, ll>;
 
#define REP(i, _, __) for (int i = (_); i < (__); ++i)
#define PER(i, _, __) for (int i = (_-1); i >= (__); --i)
#define FOR(i, _, __) for (int i = (_); i <= (__); ++i)
#define ROF(i, _, __) for (int i = (_); i >= (__); --i)
#define FC(v, V) for (const auto& v: V)
#define FE(v, V) for (auto& v: V)

#define EB emplace_back
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(),(x).end()
#define LLA(x) (x).rbegin(),(x).rend()
#define pf printf

const double PI = acos(-1.0);

template<typename T>
T MIN(T a, T b) { return min(a, b); }

template<typename First, typename... Rest>
First MIN(First f, Rest... r) { return min(f, MIN(r...)); }

template<typename T>
T MAX(T a, T b) { return max(a, b); }

template<typename First, typename... Rest>
First MAX(First f, Rest... r) { return max(f, MAX(r...)); }

template<typename T>
inline void umin(T& a, const T& b) { if (a > b) a = b; }

template<typename T>
inline void umax(T& a, const T& b) { if (a < b) a = b; }

ll FIRSTTRUE (ll l, ll r, function<bool(ll)> f) {
    ll res = l - 1, mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if (f(mid)) r = mid - 1, res = mid;
        else l = mid + 1;
    }
    return res;
}

ll LASTTRUE (ll l, ll r, function<bool(ll)> f) {
    ll res = l - 1, mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if (f(mid)) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    return res;
}

const int __BUFFER_SIZE__ = 1 << 20;
bool NEOF = 1;
int __top;
char __buf[__BUFFER_SIZE__], *__p1 = __buf, *__p2 = __buf, __stk[996];
inline char nc() {
    return __p1 == __p2 && NEOF && (__p2 = (__p1 = __buf) + fread(__buf, 1, __BUFFER_SIZE__, stdin), __p1 == __p2) ? (NEOF = 0, EOF) : *__p1++;
}

#define rd read
template<typename T>
inline bool read(T &x) {
    char c = nc();
    bool f = 0; x = 0;
    while (!isdigit(c)) c == '-' && (f = 1), c = nc();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = nc();
    if (f) x = -x;
    return NEOF;
}

inline bool need(char c) { return (c != '\n') && (c != ' '); }

inline bool read(char& a) {
    while ((a = nc()) && need(a) && NEOF) ;
    return NEOF;
}

inline bool read(char *a) {
    while ((*a = nc()) && need(*a) && NEOF) ++a; 
    *a = '\0';
    return NEOF;
}

inline bool read(double &x) {
    bool f = 0; char c = nc(); x = 0;
    while (!isdigit(c))  { f |= (c == '-'); c = nc(); }
    while (isdigit(c)) { x = x * 10.0 + (c ^ 48); c = nc(); }
    if (c == '.') {
        double temp = 1; c = nc();
        while (isdigit(c)) { temp = temp / 10.0; x = x + temp * (c ^ 48); c = nc(); }
    }
    if (f) x = -x;
    return NEOF;
}

template<typename First, typename... Rest>
inline bool read(First &f, Rest &... r) {
    read(f);
    return read(r...);
}

#define pr print
#define pln println
template<typename T>
inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x == 0) { putchar('0'); return; }
    __top = 0;
    while(x) {
        __stk[++__top] = x % 10 + '0';
        x /= 10;
    }
    while(__top) {
        putchar(__stk[__top]);
        --__top;
    }
}

template<typename First, typename... Rest>
inline void print(First f, Rest... r) {
    print(f); putchar(' ');
    print(r...);
}

template<typename T>
inline void println(T x) {
    print(x); 
    putchar('\n');
}

template<typename First, typename... Rest>
inline void println(First f, Rest... r) {
    print(f); putchar(' ');
    println(r...);
}

template<typename T>
void println(const vector<T>& V) {
    for(const auto& v: V) print(v), putchar(' ');
    putchar('\n');
}

#ifdef BACKLIGHT
#include "debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return l + rng() % (r - l + 1); }

const int N = 5e5 + 5;
const int M = 3e6 + 5;
const int K = 1e7 + 5;
const int MOD = 1e9 + 7;              // 998244353 1e9 + 7
const int INF = 0x3f3f3f3f;             // 1e9 + 7 0x3f3f3f3f
const ll LLINF = 0x3f3f3f3f3f3f3f3f;    // 1e18 + 9 0x3f3f3f3f3f3f3f3f
const double eps = 1e-8;

ll qp(ll a, ll b, ll p = MOD) { ll r = 1; while(b) { if (b & 1) r = r * a % p; a = a * a % p; b>>= 1; } return r; }

int n;
ll A, B;
struct monster {
    ll a, b;
    bool operator < (const monster& m) const {
        if (a == m.a) return b < m.b;
        return a < m.a;
    }
} a[N];
void solve(int Case) { // printf("Case #%d: ", Case);
    rd(A, B, n);
    FOR(i, 1, n) rd(a[i].a);
    FOR(i, 1, n) rd(a[i].b);
    sort(a + 1, a + 1 + n);

    int cnt = 0;
    FOR(i, 1, n) {
        int t1 = (a[i].b + A - 1) / A;
        int t2 = (B + a[i].a - 1) / a[i].a;
        if (t2 < t1) break;
        ++cnt;
        B -= a[i].a * t1;
        if (B < 0) break;
    }
    puts(cnt == n ? "YES" : "NO");
}

int main() {
#ifdef BACKLIGHT
    freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    auto begin = std::chrono::steady_clock::now();
#endif

    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    rd(T);
    for (int _ = 1; _ <= T; _++) solve(_);

#ifdef BACKLIGHT
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cerr << "\033[32mTime Elasped: " << duration.count() << " ms\033[0m" << endl;
#endif
    return 0;
}