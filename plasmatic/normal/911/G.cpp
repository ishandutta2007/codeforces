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

const int MN = 2e5 + 1, MV = 101;
int N, Q,
    val[MN];
char seg[MN * 4][MV], lazy[MN * 4][MV];

void comb(char f[MV], char g[MV], char to[MV]) { // f(g(x))
    static char tmp[MV];
    repi(1, MV)
        tmp[i] = f[g[i]];
    copy(tmp + 1, tmp + MV, to + 1);
}
void reset(char f[MV]) {
    iota(f + 1, f + MV, 1);
}

void build(int i = 1, int l = 1, int r = N) {
    reset(seg[i]);
    reset(lazy[i]);
    if (l == r) return;
    int mid = (l + r) / 2;
    build(i * 2, l, mid); build(i * 2 + 1, mid + 1, r);
}

void push(int i, int l, int r) {
    bool id = true;
    repj(1, MV)
        id &= lazy[i][j] == j;
    if (!id) {
        if (l == r) comb(lazy[i], seg[i], seg[i]);
        if (i * 2 < MN * 4) comb(lazy[i], lazy[i * 2], lazy[i * 2]);
        if (i * 2 + 1 < MN * 4) comb(lazy[i], lazy[i * 2 + 1], lazy[i * 2 + 1]);
        reset(lazy[i]);
    }
}

void update(int ql, int qr, int x, int y, int i = 1, int l = 1, int r = N) {
    if (l > qr || r < ql) return;
    push(i, l, r);
    if (l >= ql && r <= qr) {
        lazy[i][x] = y;
        return;
    }
    int mid = (l + r) / 2;
    update(ql, qr, x, y, i * 2, l, mid);
    update(ql, qr, x, y, i * 2 + 1, mid + 1, r);
}

void output(int i = 1, int l = 1, int r = N) {
    push(i, l, r);
    if (l == r) {
        print(int(seg[i][val[l]]), ' ');
        return;
    }
    int mid = (l + r) / 2;
    output(i * 2, l, mid); output(i * 2 + 1, mid + 1, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N);
    repi(1, N + 1)
        scan(val[i]);
    build();
    scan(Q);
    while (Q--) {
        scn(int, l, r, x, y);
        update(l, r, x, y);
    }
    output();
    print('\n');

    return 0;
}