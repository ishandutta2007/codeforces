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
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
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
#define db(x) cout << (#x) << ": " << x << ", "
#define dblb(s) cout << "[" << s << "] "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion
 
vl factor(ll x) {
    ld sqx = sqrt(x) + 100;
    vl ret;
    repi(1, sqx + 1) {
        if (x % i == 0) {
            ret.pb(i);
            ret.pb(x / i);
        }
    }
 
    sort(ret.begin(), ret.end());
    ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
    return ret;
}
 
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
 
using pll = pair<ll, ll>;
const int MN = 1001, MF = 7001; // Max factors
int n,
    par[MN][MF];
pll dp[MN][MF];
ll k;
struct p {
    int i; ll v, gv;
    Cmplt(p) { return v < o.v; }
} num[MN];
vl kfactors; // factors for k
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // input and setup factors
    scan(n, k);
    kfactors = factor(k); // first factor is definitely 1
    int fsz = kfactors.size(); 
    assert(fsz < MF);
 
    // input nums
    repi(1, n + 1) {
        scan(num[i].v);
        num[i].gv = gcd(num[i].v, k);
        num[i].i = i;
    }sort(num + 1, num + n + 1);
 
    // edge case
    if (k == 1) {
        
        println(1);
        println(num[1].i);
        return 0;
    }
 
    // dp
    pll invalid = mpr(LLINF, LLINF);
    dp[0][0] = {0LL, 0LL};
    repi(1, fsz)
        dp[0][i] = invalid;
    repi(1, n + 1) { 
        repj(1, fsz) {
            dp[i][j] = min(invalid, dp[i - 1][j]);
            par[i][j] = j;
 
            ll from = kfactors[j] / gcd(num[i].gv, kfactors[j]);
            int fromid = lower_bound(all(kfactors), from) - kfactors.begin();
 
            auto alt = dp[i - 1][fromid];
            alt.first++;
            alt.second += num[i].v;
 
            if (alt < dp[i][j]) {
                dp[i][j] = alt;
                par[i][j] = fromid;
            }
            
            // db(i); db(j); db(kfactors[j]); db(num[i].gv); db(gcd(num[i].gv, kfactors[j])); db(from); db(fromid); db(dp[i-1][fromid].first); db(dp[i-1][j].first); db(dp[i][j].first); dbln;
        }
    }
 
    if (dp[n][fsz - 1].first == LLINF) {
        println(-1);
        return 0;
    }
 
    // output and backtrack
    println(dp[n][fsz - 1].first);
 
    vi seq;
    int ci = n, cj = fsz - 1;
    while (ci > 0 && cj > 0) {
        auto cpar = par[ci][cj];
        if (cj > cpar)
            seq.pb(num[ci].i);
 
        ci--; cj = cpar;
    }
    sort(seq.begin(), seq.end());
    for (auto x : seq)
        print(x, ' ');
    print('\n');
 
    return 0;
}