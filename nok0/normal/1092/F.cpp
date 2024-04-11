/**
 *	author: nok0
 *	created: 2020.09.12 13:57:02
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ll long long
#define ld long double
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(int i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V<V<T>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define VEC(type, name, size)\
	V<type> name(size);\
	IN(name)
#define VVEC(type, name, h, w)\
	VV<type> name(h, V<type>(w));\
	IN(name)
#define INT(...)\
	int __VA_ARGS__;\
	IN(__VA_ARGS__)
#define LL(...)\
	ll __VA_ARGS__;\
	IN(__VA_ARGS__)
#define STR(...)\
	string __VA_ARGS__;\
	IN(__VA_ARGS__)
#define CHAR(...)\
	char __VA_ARGS__;\
	IN(__VA_ARGS__)
#define DOUBLE(...)\
	DOUBLE __VA_ARGS__;\
	IN(__VA_ARGS__)
#define LD(...)\
	LD __VA_ARGS__;\
	IN(__VA_ARGS__)
template <class T> void scan(T a) { cin >> a; }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(V<T> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T> void scan(V<T> &a) { for(auto &i : a) scan(i); }
template <class T, class L> void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) { scan(head); IN(tail...); }
template <class T> inline void print(T x){ cout << x << '\n';}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p){
	is >> p.first >> p.second;
	return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p){
	os << p.first << " " << p.second;
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const V<T> &v){
	REP(i, SZ(v)){
		if(i) os << " ";
		os << v[i];
	}
	return os;
}
//debug
template <typename T>
void view(const V<T> &v){
	cerr << "{ ";
	for(const auto &e : v){
		cerr << e << ", ";
	}
	cerr << "\b\b }";
}
template <typename T>
void view(const VV<T> &vv){
	cerr << "{\n";
	for(const auto &v : vv){
		cerr << "\t";
		view(v);
		cerr << "\n";
	}
	cerr << "}";
}
template <typename T, typename U>
void view(const V<pair<T, U>> &v){
	cerr << "{\n";
	for(const auto &c : v) cerr << "\t(" << c.first << ", " << c.second << ")\n";
	cerr << "}";
}
template <typename T, typename U>
void view(const map<T, U> &m){
	cerr << "{\n";
	for(auto &t : m) cerr << "\t[" << t.first << "] : " << t.second << "\n";
	cerr << "}";
}
template <typename T, typename U>
void view(const pair<T, U> &p){ cerr << "(" << p.first << ", " << p.second << ")";}
template <typename T>
void view(const set<T> &s) {
	cerr << "{ ";
	for(auto &t : s) {
		view(t);
		cerr << ", ";
	}
	cerr << "\b\b }";
}
template <typename T>
void view(T e) { cerr << e;}
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	view(H);
	cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                           \
	do{                                                     \
		cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                              \
		cerr << "\b\b]\n";                                   \
	} while(0)
#else
#define debug(...) (void(0))
#endif
template <class T> V<T> press(V<T> &x){ 
	V<T> res = x;
	sort(all(res));
	res.erase(unique(all(res)), res.end());
	REP(i, SZ(x)){
		x[i] = lower_bound(all(res), x[i]) - res.begin();
	}
	return res;
}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T divup(T x, T y) {return (x+(y-1))/y;}
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
struct iofast{iofast(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(15);}}iofast_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

// Graph Template
struct Edge{
	ll to,cost;
	Edge(ll to,ll cost):to(to),cost(cost){}
	bool operator < (const Edge& a) const{
		return cost < a.cost;
	}
};
using Graph = VV<>;
using WGraph = VV<Edge>;

void Read_Graph(Graph &g, int m, bool directed = false){
	REP(i, m){
		LL(u, v); u--; v--;
		g[u].pb(v);
		if(!directed) g[v].pb(u);
	}
}
void Read_Tree(Graph &g, bool directed = false) {Read_Graph(g, SZ(g) - 1, directed);}

void Read_Graph(WGraph &g, int m, bool directed = false){
	REP(i, m){
		LL(u, v, c); u--; v--;
		g[u].pb({v, c});
		if(!directed) g[v].pb({u, c});
	}
}
void Read_Tree(WGraph &g, bool directed = false) {Read_Graph(g, SZ(g) - 1, directed);}

template <typename T>
struct ReRooting{
private:
	using F = function<T(T, int)>;
	using F2 = function<T(T, T)>;
	int n;
	Graph G;
	VV<T> dp;
	F f, g;
	F2 merge;
	T ide;

	T dfs1(int p, int k){
		T res = ide;
		int cnt = -1;
		REP(i, SZ(G[k])){
			if(G[k][i] == p) continue;
			dp[k][i] = dfs1(k, G[k][i]);
			res = merge(res, f(dp[k][i], G[k][i]));

		}
		return g(res, k);
	}

	void dfs2(int p, int k, T add){
		REP(i, SZ(G[k])){
			if(G[k][i] == p){
				dp[k][i] = add;
				break;
			}
		}
		V<T> pL(SZ(G[k]) + 1), pR(SZ(G[k]) + 1);
		pL[0] = ide;
		REP(i, SZ(G[k])) pL[i + 1] = merge(pL[i], f(dp[k][i], G[k][i]));
		pR[SZ(G[k])] = ide;
		RREP(i, SZ(G[k])) pR[i] = merge(pR[i + 1], f(dp[k][i], G[k][i]));
		REP(i, SZ(G[k])){
			if(G[k][i] == p) continue;
			T val = merge(pL[i], pR[i + 1]);
			dfs2(k, G[k][i], g(val, k));
		}
	}
	void build(int root){
		REP(i, n) dp[i].resize(SZ(G[i]));
		dfs1(-1, root);
		dfs2(-1, root, ide);
	}

public:
	ReRooting(Graph G_, F f_, F2 merge_, T ide_, F g_ = [](T a, int b){return a;})
	: G(G_), f(f_), merge(merge_), ide(ide_), g(g_){
		n = SZ(G);
		dp.resize(n);
	}

	V<T> solve(int root = 0){
		build(root);
		V<T> vec(n);
		REP(k, n){
			T res = ide;
			REP(i, SZ(G[k])) res = merge(res, f(dp[k][i], G[k][i]));
			vec[k] = g(res, k);
		}
		return vec;
	}
};

int main(){
	INT(n);
	VEC(int, l, n);
	Graph G(n);
	Read_Tree(G);
	using P = pair<ll, ll>;
	auto f = [](P a, int v){return a;};
	auto merge = [](P a, P b){
		return P(a.first + b.first, a.second + b.second);
	};
	auto g = [&](P a, int v){
		return P(a.first + a.second, a.second + l[v]);
	};
	ReRooting<P> RE(G, f, merge, {0, 0}, g);
	auto res = RE.solve();
	print(max_element(all(res))->first);
}