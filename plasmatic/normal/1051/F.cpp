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

struct Ed {
	int v; ll w;
};

const int MN = 1e5 + 1, LG = 18, D = 21;
int N, M, Q,
    A[MN], B[MN], W[MN];
vec<Ed> g[MN];

// DSU
struct DSU {
    vector<int> dsu;
    void init(int N) { dsu.resize(N); iota(dsu.begin(), dsu.end(), 0); }
    int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
    void merge(int x, int y) { dsu[rt(x)] = rt(y); }
    bool same(int x, int y) { return rt(x) == rt(y); }
};

// lca
int tb[LG][MN], lv[MN];
ll disTree[MN];
void dfsLca(int c, int p, int clv, ll cdis) {
	lv[c] = clv;
	disTree[c] = cdis;
	tb[0][c] = p;
	for (auto to : g[c])
		if (to.v ^ p) 
			dfsLca(to.v, c, clv + 1, cdis + to.w);
}
void initSp() {
	memset(tb, -1, sizeof tb);
	dfsLca(1, -1, 0, 0);
	for (int i = 1; i < LG; i++) {
		for (int j = 1; j <= N; j++) {
			int pp = tb[i - 1][j];
			tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];
		}
	}
}
int lca(int a, int b) {
	if (a == b) return a;
	if (lv[a] > lv[b]) swap(a, b);
	int delta = lv[b] - lv[a];
	for (int i = 0; i < LG; i++)
		if ((delta >> i) & 1)
			b = tb[i][b];
	if (a == b) return a;
	for (int i = LG - 1; i >= 0; i--) {
		if (tb[i][a] != tb[i][b]) {
			a = tb[i][a];
			b = tb[i][b];
		}
	}
	return tb[0][a];
}
ll qdis(int a, int b) {
	return disTree[a] + disTree[b] - 2 * disTree[lca(a, b)];
}

// ST stuff
map<int, int> extraMp;
vi extra;
DSU uf;

// floyd and precalc
ll qdisNE(int node, int edge) {
	return min(qdis(node, A[edge]), qdis(node, B[edge]));
}
ll qdisEE(int edge1, int edge2) {
	return min(qdisNE(A[edge1], edge2), qdisNE(B[edge1], edge2));
}

ll dis[D][D], precalc[D][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, M);

	int ptr = 0;
    uf.init(N + 1);
    repi(0, M) {
        scan(A[i], B[i], W[i]);
        if (!uf.same(A[i], B[i])) {
			g[A[i]].pb({B[i], W[i]});
			g[B[i]].pb({A[i], W[i]});
            uf.merge(A[i], B[i]);
        } else {
			extra.pb(i);
			extraMp[i] = ptr++;
		}
    }
    initSp();

    // precalc
	int cnt = M - N + 1;
	// db(extra); db(cnt); dbln; assert(extra.size()==cnt);
	repi(0, cnt)
		repj(0, cnt)
			dis[i][j] = qdisEE(extra[i], extra[j]);
	repk(0, cnt) {
		repi(0, cnt) {
			repj(0, cnt) {
				mina(dis[i][j], dis[i][k] + dis[k][j] + W[extra[k]]);
			}
		}
	}
	repi(0, cnt) {
		repj(1, N + 1) {
			precalc[i][j] = qdisNE(j, extra[i]);
		}
	}

	// repi(0, cnt) db(i), db(A[i]), db(B[i]), db(W[i]), dbln;
	// repi(0, cnt)
	// 	repj(0, cnt)
	// 		db(i), db(j), db(dis[i][j]), dbln;

	// answer
	scan(Q);
	while (Q--) {
		scn(int, u, v);

		ll best = qdis(u, v);
		repi(0, cnt) {
			// db(i); db(u); db(v); db(extra[i]); db(qdisNE(u, extra[i])); db(qdisNE(v, extra[i])); dbln;
			mina(best, precalc[i][u] + precalc[i][v] + W[extra[i]]);
			repj(0, cnt) {
				if (i == j) continue;
				mina(best, precalc[i][u] + dis[i][j] + precalc[j][v] + W[extra[i]] + W[extra[j]]);
			}
		}
		println(best);
	}

    return 0;
}