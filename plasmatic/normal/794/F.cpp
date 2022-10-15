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

const int MN = 1e5 + 1, D = 10;
// const int MN = 1e5 + 1, D = 10, B = 2;
int N, Q,   
    val[MN][D];
ll seg[MN << 2][D];
int lazy[MN << 3][D];

void identity(int f[D]) {
    repi(0, D) f[i] = i;
}
void compose(int f[D], int g[D]) { // g(x) -> f(g(x))
    static int tmp[D];
    repi(0, D) tmp[i] = f[g[i]];
    copy(tmp, tmp + D, g);
}
bool isIdentity(int f[D]) {
    repi(0, D) if (f[i] != i) return false;
    return true;
}
void build(int i, int l, int r) {
    identity(lazy[i]);
    if (l == r) {
        copy(val[l], val[l] + D, seg[i]);
        return;
    }
    int mid = (l + r) / 2;
    build(i << 1, l, mid); build(i << 1 | 1, mid + 1, r);
    repj(0, D)
        seg[i][j] = seg[i << 1][j] + seg[i << 1 | 1][j];
}
void push(int i) {
    static ll tmp[D];
    if (!isIdentity(lazy[i])) {
        fill(tmp, tmp + D, 0);
        repj(0, D)
            tmp[lazy[i][j]] += seg[i][j];
        copy(tmp, tmp + D, seg[i]);
        compose(lazy[i], lazy[i << 1]);
        compose(lazy[i], lazy[i << 1 | 1]);
        identity(lazy[i]);
    }
}
void upd(int i, int l, int r, int ql, int qr, int qx, int qy) {
    static int tmp[D];
    if (l > qr || r < ql) { push(i); return; }
    if (l >= ql && r <= qr) {
        identity(tmp);
        tmp[qx] = qy;
        compose(tmp, lazy[i]);
        push(i);
        return;        
    }
    push(i);
    int mid = (l + r) / 2;
    upd(i << 1, l, mid, ql, qr, qx, qy); upd(i << 1 | 1, mid + 1, r, ql, qr, qx, qy);
    repj(0, D)
        seg[i][j] = seg[i << 1][j] + seg[i << 1 | 1][j];
}
ll query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0LL;
    push(i);
    if (l >= ql && r <= qr) {
        ll res = 0;
        repj(1, D) res += j * seg[i][j];
        return res;
    }
    int mid = (l + r) / 2;
    return query(i << 1, l, mid, ql, qr) + query(i << 1 | 1, mid + 1, r, ql, qr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, Q);

    repi(1, N + 1) {
        ll x; scan(x);

        ll pow = 1;
        while (x > 0) {
            ll rem = x % 10;
            val[i][rem] += pow;

            x /= 10;
            pow *= 10;
        }
    }
    build(1, 1, N);

    while (Q--) {
        scn(int, T, l, r);

        if (T == 1) {
            int x, y; scan(x, y);
            if (x == y) continue;
            upd(1, 1, N, l, r, x, y);
        }
        else {
            // db(bl); db(br); dbln;
            ll ans = query(1, 1, N, l, r);
            println(ans);
        }

        // dblb("done"); dbln;
    }

    return 0;
}