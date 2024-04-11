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

#define T int
#define Default 0
#define Op(a, b) (a) += (b)
struct BIT {
    int N, cqid;
    vector<T> bit; vector<int> qid;
    void init(int n) { N = n; bit.resize(N + 1); qid.resize(N + 1); }
    T& get(int x) { if (qid[x] != cqid) { qid[x] = cqid; bit[x] = Default; } return bit[x]; }
    void reset() { cqid++; }
    void add(int x, T v) { for (; x <= N; x += x & - x) Op(get(x), v); }   
    T sum(int x) { T sum = Default; for (; x; x -= x & -x) Op(sum, get(x)); return sum; }
};
#undef T
#undef Default
#undef Op

#define T int
struct Rank {
    vector<T> rank;
    void add(T x) { rank.pb(x); }
    void init() {
        sort(rank.begin(), rank.end());
        rank.resize(unique(rank.begin(), rank.end()) - rank.begin());
    }
    int get(T x) { return lower_bound(rank.begin(), rank.end(), x) - rank.begin() + 1; }
};
#undef T

struct person {
    int x, y, i;
};

struct dish {
    int x, yl, yr;
};

void rot45Set(int &x, int &y) {
    int a = x + y, b = -x + y;
    x = a;
    y = b;
}

pii rot45(int &x, int &y) {
    pii res = mpr(x, y);
    rot45Set(res.first, res.second);
    return res;
}

struct evt {
    char type;
    int x, y, ind;
};

const int MN = 1e5 + 1;
int N, M;
dish dishes[MN];
person people[MN];

// CDQ stuff
Rank compy;
vector<evt> events;
int ans[MN];
BIT bit;

void CDQ(int L, int R, vec<evt> events) {
    if (L > R) return;
    if (events.empty()) return;

    int mid = ((ll)L + (ll)R) / 2;
    vec<evt> lhs, rhs;
    bit.reset();
    // db(L); db(R); dbln;
    for (auto &e : events) {
        if (e.type == 'Q') {
            // dblb("Q"); db(e.x); db(e.y); db(e.ind); dbln;
            if (R <= e.x)
                ans[e.ind] += bit.sum(e.y);
            else if (L < R) {
                if (e.x > mid) rhs.pb(e);
                lhs.pb(e);
            }
        }
        else {
            // db(e.type); db(e.x); db(e.y); dbln;
            if (e.type == 'A') bit.add(e.y, 1);
            else if (e.type == 'D') bit.add(e.y, -1);
            if (L < R) {
                if (e.x <= mid) lhs.pb(e);
                else rhs.pb(e);
            }
        }
    }

    CDQ(L, mid, lhs); CDQ(mid + 1, R, rhs);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, M);
    repi(0, N) scan(dishes[i].yl);
    repi(0, N) scan(dishes[i].yr);
    repi(0, N) scan(dishes[i].x);
    repi(0, M) scan(people[i].y);
    repi(0, M) scan(people[i].x);
    repi(0, M) people[i].i = i;

    // make "events"
    sort(people, people + M, [] (const person &a, const person &b) { return a.y < b.y; });
    sort(dishes, dishes + N, [] (const dish &a, const dish &b) { return a.yr < b.yr; });
    repi(0, N) {
        auto &d = dishes[i];
        events.pb({'A', d.x, d.yl, -1});
    }
    int ptr = 0;
    repi(0, M) {
        while (ptr < N && dishes[ptr].yr < people[i].y) {
            auto &d = dishes[ptr];
            events.pb({'D', d.x, d.yl, -1});
            ptr++;
        }

        auto &p = people[i];
        events.pb({'Q', p.x, p.y, p.i});
    }

    // CDQ
    int mn = INT_MAX, mx = INT_MIN;
    for (auto &e : events) {
        rot45Set(e.x, e.y);
        compy.add(e.y);
    }
    compy.init();
    for (auto &e : events) {
        e.y = compy.get(e.y);
        mina(mn, e.x);
        maxa(mx, e.x);
    }
    bit.init(compy.rank.size());
    CDQ(mn, mx, events);

    // answer
    repi(0, M)
        print(ans[i], ' ');
    print('\n');

    return 0;
}