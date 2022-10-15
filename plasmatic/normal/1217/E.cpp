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

struct SegTree {
    vpl seg;
    int N;
    void init(int N0) {
        N = N0;
        seg.assign(N * 4, mpr(LLINF, LLINF));
    }
    void merge(pll &res, const pll &r) {
        if (r.first <= res.first) {
            res.second = res.first;
            res.first = r.first;
        }
        else if (r.first <= res.second)
            res.second = r.first;
        if (r.second <= res.first) {
            res.second = res.first;
            res.first = r.second;
        }
        else if (r.second <= res.second)
            res.second = r.second;
    }
    pll _query(int i, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return mpr(LLINF, LLINF);
        if (l >= ql && r <= qr) return seg[i];
        int mid = (l + r) / 2;
        pll res = _query(i << 1, l, mid, ql, qr);
        merge(res, _query(i << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
    void _update(int i, int l, int r, int q, ll v) {
        if (q > r || q < l) return;
        if (l >= q && r <= q) return void(seg[i] = mpr(v, LLINF));
        int mid = (l + r) / 2;
        _update(i << 1, l, mid, q, v); _update(i << 1 | 1, mid + 1, r, q, v);
        seg[i] = seg[i << 1]; 
        merge(seg[i], seg[i << 1 | 1]);
    }
    ll query(int l, int r) {
        auto res = _query(1, 1, N, l, r);
        return res.first + res.second;
    }
    void update(int q, ll v) { _update(1, 1, N, q, v); }
};

const int MN = 2e5 + 1;
int N, Q,
    val[MN];
SegTree segs[10];

void setVal(int idx, int val, ll setAs) {
    int digIdx = 0;
    while (val > 0) {
        if (val % 10)
            segs[digIdx].update(idx, setAs);

        val /= 10;
        digIdx++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, Q);
    repi(0, 10)
        segs[i].init(N);
    repi(1, N + 1) {
        scn(int, x);
        setVal(i, x, x);
        val[i] = x;
    }

    while (Q--) {
        scn(int, T, a, b);
        if (T == 1) {
            setVal(a, val[a], LLINF);
            setVal(a, val[a] = b, b);
        }
        else {
            ll ans = LLINF;
            repi(0, 10)
                mina(ans, segs[i].query(a, b));
            println(ans == LLINF ? -1 : ans);
        }
    }

    return 0;
}