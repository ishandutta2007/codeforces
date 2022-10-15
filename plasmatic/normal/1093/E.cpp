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

struct Evt {
    bool t; // 0->upd, 1->qu
    int i, a, b, c, d;
};

const int MN = 2e5 + 1, B = 400;
int N, Q,
    idOf[MN], perm[MN], cnt[MN << 2];
bool isq[MN];
namespace __QID {
    int cqid = 0,
        qid[MN], bit[MN];
    inline void reset() {
        cqid++;
    }
    inline int& get(int x) {
        if (qid[x] < cqid) {
            qid[x] = cqid;
            bit[x] = 0;
        }
        return bit[x];
    }
    inline int sum(int x) {
        int sum = 0;
        for (; x; x -= x & -x)
            sum += get(x);
        return sum; 
    }
    inline void add(int x, int z) {
        for (; x <= N; x += x & -x)
            get(x) += z;
    }
};
using __QID::reset; using __QID::sum; using __QID::add;

int ans[MN];
void CDQ(int vl, int vr, vec<Evt> evts) {
    vec<Evt> lhs, rhs;
    int mid = (vl + vr) / 2;

    // db(vl); db(vr); db(mid); dbln;
    // for (auto &e : evts) {
    //     db(e.t); db(e.i); db(e.a); db(e.b); db(e.c); db(e.d); dbln;
    // }

    reset();
    for (auto &q : evts) {
        if (q.t == 0) { // update
            if (vl <= q.a && q.a <= vr) {
                if (q.b != -1) add(q.b, -1);
                add(q.c, 1);
            }
            if (q.a <= mid) lhs.pb(q);
            else rhs.pb(q);
        }
        else { // query
            if (q.a <= vl && vr <= q.b) {
                ans[q.i] += sum(q.d) - sum(q.c - 1);
            }
            else {
                if (q.a <= mid) lhs.pb(q);
                if (q.b > mid) rhs.pb(q);
            }
        }
    }
    if (vl != vr) {
        CDQ(vl, mid, lhs);
        CDQ(mid + 1, vr, rhs);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, Q);
    repi(1, N + 1) {
        scn(int, x);
        idOf[x] = i;
    }

    vec<Evt> evts;
    repi(1, N + 1) {
        scan(perm[i]);
        perm[i] = idOf[perm[i]];
        evts.pb({0, -1, perm[i], -1, i});
    }

    repi(0, Q) {
        scn(int, T);
        if (T == 1) {
            scn(int, vl, vr, l, r);
            evts.pb({1, i, vl, vr, l, r});
            isq[i] = true;
        }
        else {
            scn(int, x, y);
            evts.pb({0, -1, perm[x], x, y});
            evts.pb({0, -1, perm[y], y, x});
            swap(perm[x], perm[y]);
        }
    }

    CDQ(1, N, evts);

    repi(0, Q)
        if (isq[i])
            println(ans[i]);

    return 0;
}