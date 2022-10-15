#pragma region
#include <bits/stdc++.h>
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
#define finline __attribute__((always_inline))
// Shorthand Function Macros
#define sz(x) ((int)((x).size()))
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

const ll MOD = 1e9 + 7;
ll madd(ll a, ll b) { return (a + b) % MOD; }
ll msub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mmul(ll a, ll b) { return (a * b) % MOD; }
ll fpow(ll x, ll y) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x), y >> 1), (y & 1) ? x : 1LL);
}
ll mdiv(ll x, ll y) { return mmul(x, fpow(y, MOD - 2)); }

const int MN = 1e5 + 1;
int N;
ll dp[MN];

// prime factor
int jmp[MN];
bool isPrime[MN];

// find number of X such that gcd(from, X) = to and 1<=X<=N.  Assume that to|from
ll cntTo(int from, int to) { // expected value of repeating something forever
    assert(from % to == 0);
    from /= to;

    // get primes
    vi primes;
    int tmp = from;
    while (tmp > 1) {
        // db(tmp); db(jmp[tmp]); db(primes); dbln;
        primes.pb(jmp[tmp]);
        tmp /= jmp[tmp];
    }
    sort(all(primes));
    primes.resize(unique(all(primes)) - primes.begin());

    // inclusion/exclusion on primes
    int tot = 0, sz = primes.size(), msub = 1 << sz, RB = N / to;
    repi(1, msub) {
        int prod = 1;
        repj(0, sz)
            if ((i >> j) & 1)
                prod *= primes[j];
        
        if (popcount(i) & 1)
            tot += RB - RB / prod;
        else
            tot -= RB - RB / prod;
    }

    return tot;
}

/*
for all j, that j<i, dp[i] = 1/N * dp[i] + (... j) + 1
(1-1/N)dp[i] = (... j) + 1
dp[i] = ((... j) + 1) / (1-1/N)
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N);

    // init sieve
    memset(isPrime, true, sizeof isPrime); isPrime[0] = isPrime[1] = false;
    repi(2, N + 1) {
        if (isPrime[i]) {
            jmp[i] = i;
            for (int j = i * 2; j <= N; j += i) {
                isPrime[j] = false;
                jmp[j] = i;
            }
        }
    }

    // db(N); db(cntTo(6, 2)); db(cntTo(6, 3)); dbln;

    // calc dp
    dp[1] = 1LL;
    repi(2, N + 1) {
        vi facs;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                facs.pb(j);
                if (j * j != i && j != 1) facs.pb(i / j);
            }
        }

        int left = N;
        dp[i] = 1LL;
        for (auto factor : facs) {
            int cnt = cntTo(i, factor);
            // db(i); db(factor); db(cnt); db(dp[factor]); dbln;
            dp[i] = madd(dp[i], mmul(dp[factor], mdiv(cnt, N)));
            left -= cnt;
        }
        // db(i); db(dp[i]);
        dp[i] = mdiv(dp[i], msub(1, mdiv(left, N)));
        // db(dp[i]); dbln;
    }

    // get ans
    ll ans = 0;
    repi(1, N + 1) 
        ans = madd(ans, dp[i]);
    ans = mdiv(ans, N);
    println(ans);

    return 0;
}