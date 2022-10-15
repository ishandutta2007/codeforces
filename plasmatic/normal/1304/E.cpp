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

const int MN = 1e5 + 1, LG = 17;
int N, Q,
    lv[MN], par[LG][MN];
vi g[MN];
void dfs(int c, int p, int clv) {
    lv[c] = clv;
    par[0][c] = p;
    for (auto to : g[c])
        if (to ^ p)
            dfs(to, c, clv + 1);
}
void init() {
    dfs(1, -1, 0);
    repi(1, LG) {
        repj(1, N + 1) {
            int pp = par[i - 1][j];
            par[i][j] = pp == -1 ? -1 : par[i - 1][pp];
        }
    }
}
int lca(int a, int b) {
    if (a == b) return a;
    if (lv[a] > lv[b]) swap(a, b);
    int delta = lv[b] - lv[a];
    repi(0, LG)
        if ((delta >> i) & 1)
            b = par[i][b];
    if (a == b) return a;
    reprev(i, LG - 1, -1) {
        if (par[i][a] != par[i][b]) {
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}
int qdis(int a, int b) {
    // db(a); db(b); db(dis[a]); db(dis[b]); db(lca(a, b)); db(dis[lca(a, b)]); dbln;
    return lv[a] + lv[b] - 2 * lv[lca(a, b)];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N);
    repi(1, N) {
        int a, b;
        scan(a, b);
        g[a].pb(b);
        g[b].pb(a);
    }
    init();

    scan(Q);
    while (Q--) {
        int x, y, a, b;
        ll k;
        scan(x, y, a, b, k);

        int d1 = qdis(a, b), d2 = min(qdis(a, x) + qdis(y, b), qdis(a, y) + qdis(x, b)) + 1;
        bool p1 = d1 & 1, p2 = d2 & 1;

        // db(x); db(y); db(a); db(b); db(k); dbln;
        // db(d1); db(d2); db(p1); db(p2); dba("pk", k & 1); dbln;

        if (p1 == p2) {
            bool pk = k & 1;
            if (min(d1, d2) <= k && pk == p1)
                println("YES");
            else
                println("NO");
        }
        else {
            bool pk = k & 1;
            if ((d1 <= k && pk == p1) || (d2 <= k && pk == p2))
                println("YES");
            else
                println("NO");
        }
    }

    return 0;
}