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

const int MN = 5001;
int N, M,
    ns[3], clr[MN], ans[MN], dp[MN][MN];
vi g[MN];
vec<array<vi, 2>> comps;

bool bad = false;
void dfs(int c, int cclr, array<vi, 2> &ccomp) {
    if (bad) return;
    if (clr[c] != -1 && cclr != clr[c]) {
        bad = true;
        return;
    }
    if (clr[c] != -1) return;
    clr[c] = cclr;
    ccomp[cclr].pb(c);
    for (int to : g[c])
        dfs(to, !cclr, ccomp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    scan(N, M);
    repi(0, 3) scan(ns[i]);
    repi(0, M) {
        scn(int, a, b);
        g[a].pb(b);
        g[b].pb(a);
    }
    memset(clr, -1, sizeof clr);

    repi(1, N + 1) {
        if (clr[i] == -1) {
            array<vi, 2> comp;
            dfs(i, false, comp);
            comps.pb(comp);
        }
    }
    if (bad) {
        println("NO");
        return 0;
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = -2;
    repi(1, sz(comps) + 1) {
        auto &c = comps[i - 1];
        repj(0, 2) {
            repk(sz(c[j]), N + 1) {
                if (dp[i - 1][k - sz(c[j])] != -1)
                    dp[i][k] = j;
            }
        }
    }
    
    if (dp[sz(comps)][ns[1]] != -1) {
        int c = sz(comps), curN = ns[1];
        while (c > 0) {
            auto &comp = comps[c - 1];
            bool compNo = dp[c][curN];
            
            for (auto &v : comp[compNo])
                ans[v] = 2;
            for (auto &v : comp[!compNo]) {
                if (ns[0] > 0) {
                    ns[0]--;
                    ans[v] = 1;
                }
                else ans[v] = 3;
            }

            c--;
            curN -= sz(comp[compNo]);
        }

        println("YES");
        repi(1, N + 1) print(ans[i]);
        print('\n');
    }
    else
        println("NO");

    return 0;
}