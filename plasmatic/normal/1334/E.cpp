#pragma region
#include "bits/stdc++.h"
using namespace std;
// Common Type shorteners and int128
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
#ifdef __SIZEOF_INT128__
using int128 = __int128_t; using uint128 = __uint128_t;
#endif
template<typename I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define mtup make_tuple
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define popcountll __builtin_popcountll
#define clzll __builtin_clzll
#define ctzll __builtin_ctzll
#define finline __attribute__((always_inline))
// Shorthand Function Macros
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (__typeof(a) i = a; i < b; i++)
#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)
#define repi(a, b) rep(i, a, b)
#define repj(a, b) rep(j, a, b)
#define repk(a, b) rep(k, a, b)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(name, type) bool name(const type &a, const type &b)
#define Inop(type) istream& operator>>(istream& in, type &o)
#define Outop(type) ostream& operator<<(ostream& out, type o)
#define Pow2(x) (1LL << (x))
#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__) // scn -> Short for SCan New
// Shorthand Functions
template<typename T> inline int sz(const T &x) { return x.size(); }
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> string arrayStr(T *arr,int sz){string ret = "[";for(int i=0;i<sz;i++){ret+=to_string(arr[i])+", "; } return ret + "]";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
#define db(x) cout << (#x) << ": " << (x) << ", "
#define dblb(s) cout << "[" << (s) << "] "
#define dba(alias, x) cout << (alias) << ": " << (x) << ", "
template<typename F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return ss.str(); }
template<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}
template<typename F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f) + ", " + __join_comma(r...); }
#define dbp(alias, ...) cout << (alias) << ": (" << __join_comma(__VA_ARGS__) << "), "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

/*
idea: go from smallest to largest

Note that the number of steps is always the same.

Additionally, path = shortest path.  This is because an edge represents a change in the # of factors (taking an edge increases the # of factors by some number), which means going from x->y has the weight of factors(y)-factors(x)
*/

const ll MOD = 998244353;
ll madd(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod = MOD) { return mmul(x, fpow(y, mod - 2, mod), mod); }

const int MN = 1e6 + 1, LG = 51;
ll D, Q,
    res1[LG], res2[LG], resLCA[LG];
vl primes, fact, invf;

void initCnt(ll x, ll res[LG]) {
    fill(res, res + sz(primes), 0);
    repi(0, sz(primes)) {
        while (x % primes[i] == 0) {
            x /= primes[i];
            res[i]++;
        }
    }
}
ll cnt(ll res1[LG], ll res2[LG]) {
    int fc = 0;
    ll denom = 1;
    repi(0, sz(primes)) {
        int d = abs(res2[i] - res1[i]);
        fc += d;
        denom = mmul(denom, invf[d]);
    }
    return mmul(fact[fc], denom);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(D, Q);

    fact.resize(LG + 1);
    invf.resize(LG + 1);
    fact[0] = invf[0] = 1;
    repi(1, LG + 1) {
        fact[i] = mmul(fact[i - 1], i);
        invf[i] = mdiv(1, fact[i]);
    }

    // get factors and prime factors
    ll tmp = D;
    for (ll i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            // db(i); db(tmp); dbln;
            while (tmp % i == 0)
                tmp /= i;
            primes.pb(i);
        }
    }
    if (tmp > 1) primes.pb(tmp);

    // db(primes); dbln;
    
    // Think of it like traversing a multidimensional AxBxCx...xZ box from bottom left corner to top right
    while (Q--) {
        scn(ll, x, y);
        initCnt(x, res1);
        initCnt(y, res2);
        repi(0, sz(primes)) resLCA[i] = min(res1[i], res2[i]);

        // db(x); db(y); db(fc); dbln;
        ll ans = mmul(cnt(res1, resLCA), cnt(res2, resLCA));
        println(ans);
    }

    return 0;
}