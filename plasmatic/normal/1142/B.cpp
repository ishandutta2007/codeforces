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

const int MN = 2e5 + 1, LG = 18;
int N, M, Q, tb[LG][MN], lv[MN];
vector<int> g[MN];
bool vis[MN];
void dfsLca(int c, int p, int clv) {
    vis[c] = true;
	lv[c] = clv;
	tb[0][c] = p;
	for (auto to : g[c])
        dfsLca(to, c, clv + 1);
}
void initSp() {
	memset(tb, -1, sizeof tb);
    repi(1, M + 1)
        if (!vis[i])
            dfsLca(i, -1, 0);
	for (int i = 1; i < LG; i++) {
		for (int j = 1; j <= M; j++) {
			int pp = tb[i - 1][j];
			tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];
		}
	}
}
int kth(int v, int up) {
    repi(0, LG) {
        if (v == -1) return v;
        if ((up >> i) & 1)
            v = tb[i][v];
    }
    return v;
}

struct Qu {
    int i, l;
};
int perm[MN], val[MN], idOf[MN], lst[MN], rleft[MN];
vector<Qu> qus[MN];
set<int> occ;
bitset<MN> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    scan(N, M, Q);
    repi(0, N) {
        scan(perm[i]);
        idOf[perm[i]] = i;
    }

    // build graph
    memset(lst, -1, sizeof lst);
    repi(1, M + 1) {
        scan(val[i]);
        int pre = perm[(idOf[val[i]] - 1 + N) % N];
        // db(i); db(val[i]); db(pre); db(lst[pre]); dbln;
        if (lst[pre] != -1)
            g[lst[pre]].pb(i);
        lst[val[i]] = i;
    }
    initSp();

    // input queries
    repi(0, Q) {
        scn(int, l, r);
        qus[r].pb({i, l});
    }

    // assert(0);

    // get left bound for each right
    repi(1, M + 1)
        rleft[i] = kth(i, N - 1);
    // dbarr(rleft, M + 1); dbln;

    // answer queries
    repi(1, M + 1) {
        occ.insert(rleft[i]);
        for (auto q : qus[i])
            ans[q.i] = occ.lower_bound(q.l) != occ.end();
    }

    // output
    repi(0, Q)
        print(ans[i]);
    print('\n');

    return 0;
}