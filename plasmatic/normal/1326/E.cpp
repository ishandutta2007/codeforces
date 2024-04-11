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

template <int MN, typename T>
struct SegmentTree {
    int n; T seg[MN << 2], lazy[MN << 3];
    T merge(T a, T b) { return max(a, b); }
    void push(int i) {
        if (lazy[i]) {
            seg[i] += lazy[i];
            lazy[i << 1] += lazy[i];
            lazy[i << 1 | 1] += lazy[i];
            lazy[i] = 0;
        }
    }
    T getDefault() { return INF; };
    T _query(int i, int bl, int br, int ql, int qr){
        if(br < ql || bl > qr) return getDefault();
        push(i);
        if(bl >= ql && br <= qr) return seg[i];
        int mid = (bl + br) >> 1;
        return merge(_query(i << 1, bl, mid, ql, qr), _query(i << 1 | 1, mid + 1, br, ql, qr));
    }
    T _update(int i, int bl, int br, int ql, int qr, T v){
        push(i);
        if(qr < bl || ql > br) return seg[i];
        if(bl >= ql && br <= qr) { lazy[i] += v; push(i); return seg[i]; }
        int mid = (bl + br) >> 1;
        return seg[i] = merge(_update(i << 1, bl, mid, ql, qr, v), _update(i << 1 | 1, mid + 1, br, ql, qr, v));
    }
    void init(int n0) { n = n0; }
    T query(int l, int r) { return _query(1, 1, n, l, r); }
    void update(int l, int r, T v) { _update(1, 1, n, l, r, v); }
};

const int MN = 3e5 + 1;
int N,
    P[MN], id[MN], Q[MN];
SegmentTree<MN, int> seg;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N);
    repi(0, N) {
        scan(P[i]);
        id[P[i]] = i + 1;
    }
    repi(0, N) scan(Q[i]);

    int ans = N;
    seg.init(N);
    seg.update(1, id[N], 1);
    repi(0, N) {
        print(ans, ' ');

        seg.update(1, Q[i], -1);
        while (seg.query(1, N) <= 0) {
            ans--;
            seg.update(1, id[ans], 1);
        }
    }
    print('\n');

    return 0;
}