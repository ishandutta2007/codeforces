#pragma GCC optimize ("O3", "unroll-loops")
// #pragma GCC target ("avx2")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
namespace {
	const int MOD107 = 1000000007;
	const int MOD998 = 998244353;
	using ll = long long;
	using ull = unsigned long long;
	using pii = pair<int, int>;
	using pll = pair<ll, ll>;
	template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
	template <class T> using maxheap = priority_queue<T, vector<T>, less<T>>;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//	mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
	struct Modular {
	private:
		long long MODVALUE = 0;
		long long val = 0;
 
		Modular initModular(long long val) const { return Modular(val, MODVALUE); }
 
	#ifdef LOCAL
		inline void validate() const {
			assert(MODVALUE != 0);
			assert(0 <= val && val < MODVALUE);
		}
 
		inline void validate(const Modular& other) const {
			validate();
			other.validate();
			assert(MODVALUE == other.MODVALUE);
		}
	#else
		inline void validate() const { }
		inline void validate(const Modular& other) const { }
	#endif
 
	public:
		explicit operator long long() const { return val; }
 
		template<class T> Modular& operator = (const T& other) { val = (other % MODVALUE + MODVALUE) % MODVALUE; return *this; }
		long long getMod() { return MODVALUE; }
		template<class T> void setMod(const T& MOD) { MODVALUE = MOD; }

		bool operator == (const Modular& other) const { validate(other); return val == other.val; }
		bool operator != (const Modular& other) const { return !(*this == other); }
 
		Modular& operator += (const Modular& other)       { validate(other); val += other.val; if (val >= MODVALUE) val -= MODVALUE; return *this; }
		Modular  operator +  (const Modular& other) const { Modular tmp = *this; return tmp += other; }
		template<class T> Modular& operator += (const T& other)       { return *this += initModular(other); }
		template<class T> Modular  operator +  (const T& other) const { return *this +  initModular(other); }
		template<class T> friend Modular operator + (const T& other, const Modular& m) { return m.initModular(other) + m; }
 
		Modular& operator ++()    { return *this += 1; }
		Modular  operator ++(int) { Modular tmp = *this; ++*this; return tmp; }
 
		Modular  operator -  () const { return initModular(-val); }
		Modular& operator -= (const Modular& other)       { validate(other); val -= other.val; if (val < 0) val += MODVALUE; return *this;}
		Modular  operator -  (const Modular& other) const { Modular tmp = *this; return tmp -= other; }
		template<class T> Modular& operator -= (const T& other)       { return *this -= initModular(other); }
		template<class T> Modular  operator -  (const T& other) const { return *this -  initModular(other); }
		template<class T> friend Modular operator - (const T& other, const Modular& m) { return m.initModular(other) - m; }
 
		Modular& operator --()    { return *this -= 1; }
		Modular  operator --(int) { Modular tmp = *this; --*this; return tmp; }
 
		Modular& operator *= (const Modular& other)       { validate(other); val *= other.val; val %= MODVALUE; if (val < 0) val += MODVALUE; return *this; }
		Modular  operator *  (const Modular& other) const { Modular tmp = *this; return tmp *= other; }
		template<class T> Modular& operator *= (const T& other)       { return *this *= initModular(other); }
		template<class T> Modular  operator *  (const T& other) const { return *this *  initModular(other); }
		template<class T> friend Modular operator * (const T& other, const Modular& m) { return m.initModular(other) * m; }
 
		Modular pow(long long power) const {
			Modular m = *this, ans = initModular(1);
			while (power) {
				if (power & 1) ans *= m;
				m *= m;
				power >>= 1;
			}
			return ans;
		}
		Modular pow(const Modular& other) const { return pow(other.val); }
		Modular inv() const { return pow(MODVALUE - 2); }
 
		Modular& operator /= (const Modular& other)       { val *= other.inv().val; val %= MODVALUE; if (val < 0) val += MODVALUE; return *this; }
		Modular  operator /  (const Modular& other) const { Modular tmp = *this; return tmp /= other; }
		template<class T> Modular& operator /= (const T& other)       { return *this /= initModular(other); }
		template<class T> Modular  operator /  (const T& other) const { return *this /  initModular(other); }
		template<class T> friend Modular operator / (const T& other, const Modular& m) { return m.initModular(other) / m; }
 
		friend istream& operator >> (istream& in, Modular& m) { in >> m.val; m.val %= m.MODVALUE; if (m.val < 0) m.val += m.MODVALUE; return in; }
		friend ostream& operator << (ostream& out, const Modular& m) { return out << m.val; }
 
		Modular() { val = 0; MODVALUE = 0; }
		Modular(long long val, long long MOD) : MODVALUE(MOD), val((val % MOD + MOD) % MOD) { }
	};
	using Mint = Modular;
	inline ll binpow(ll b, ll p, ll mod) {
		b %= mod;
		ll ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
	inline ll max(ll a, int b) { return (a > b ? a : b); }
	inline ll max(int a, ll b) { return (a > b ? a : b); }
	inline ll min(ll a, int b) { return (a < b ? a : b); }
	inline ll min(int a, ll b) { return (a < b ? a : b); }
	template <class T> inline bool chkmin(T&x, const T& y) { return y < x ? x = y, 1 : 0; }
	template <class T> inline bool chkmax(T&x, const T& y) { return x < y ? x = y, 1 : 0; }
}
namespace IO {
	struct InputWrapper {
	private:
		istream& in;

	public:
		template<class T> inline void _R(T &x) { in >> x; }
		template<class T1, class T2> inline void _R(pair<T1,T2> &x) { _R(x.first); _R(x.second); }
		template<class T> inline void _R(vector<T> &x) { for (auto& i : x) _R(i); }
		template<class T> inline void _R(deque<T> &x) { for (auto& i : x) _R(i); }
		inline void R() { }
		template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...); }
		template<class... T> inline void operator () (T &...x) { R(x...); }
		InputWrapper(istream& in) : in(in) { }
	} R(cin);

	struct OutputWrapper {
	private:
		ostream& out;
		
	public:
		template<class Container> inline void printContainer(const Container& x) { bool isFirst = 1; for (auto i : x) { if (!isFirst) out << ' '; isFirst = 0; _W(i); } }
		template<class T> inline void _W(const T& x) { out << x; }

		template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
		template<class... T> inline void _W(const vector<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const deque<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const forward_list<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const list<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const set<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const multiset<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_set<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_multiset<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const map<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const multimap<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_map<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_multimap<T...>& x) { printContainer(x); }

		inline void W() { out << '\n'; }
		template<class T> inline void W(const T &x) { _W(x); W(); }
		template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...); }
		template<class... T> inline void operator () (const T &...x) { W(x...); }
		OutputWrapper(ostream& out) : out(out) { }
	} W(cout), D(cerr);
} using namespace IO;
namespace outputFormat{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
	inline string YN(bool b) {return b ? "Yes" : "No";}
} using namespace outputFormat;
namespace std {
	template <class T1, class T2> struct hash<pair<T1,T2>> {
		std::size_t operator()(pair<T1,T2> _) const {
			return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
		}
	};
}


int main() {
	int n; R(n);
	vector<ll> switchCost(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> switchCost[i];

	vector<vector<pair<int, pll>>> g(n + 1);
	vector<vector<pair<int, ll>>> g2(n + 1);

	for (int i = 0; i + 1 < n; i++) {
		int u,v; ll c0,c1; R(u,v,c0,c1);
		g[u].push_back({ v, { c0, c1 } });
		g[v].push_back({ u, { c0, c1 } });
		g2[u].push_back({ v, c0 + c1 });
		g2[v].push_back({ u, c0 + c1 });
	}
	
	minheap<pair<ll, ll>> pq;
	for (int u = 1; u <= n; u++)
		pq.push({ switchCost[u], u });

	while (!pq.empty()) {
		ll d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d != switchCost[u]) continue;

		for (auto& e : g2[u]) {
			if (chkmin(switchCost[e.first], d + e.second))
				pq.push({ switchCost[e.first], e.first });
		}
	}
	
	const int MAXJ = 20;
	vector<vector<int>> jump(MAXJ, vector<int>(n + 1, 0));
	vector<vector<vector<ll>>> jump_dist(4, vector<vector<ll>>(MAXJ, vector<ll>(n + 1, LLONG_MAX)));
	vector<int> pre(n + 1, -1), post(n + 1, INT_MAX), dep(n + 1, 0);

	for (int mask = 0; mask < 4; mask++)
		for (int j = 0; j < MAXJ; j++) {
			jump_dist[mask][j][0] = 0;
			jump_dist[mask][j][1] = 0;
		}
	
	int time = -1;
	function<void(int, int)> dfs_jump = [&](int u, int p) {
		pre[u] = ++time;

		for (auto& e : g[u]) {
			int v = e.first;
			if (v == p) continue;

			dep[v] = dep[u] + 1;
			jump[0][v] = u;

			vector<vector<ll>> dist(4, vector<ll>(4, 1e18));
			for (int u = 0; u < 4; u++)
				dist[u][u] = 0;
			dist[0][1] = dist[1][0] = switchCost[u];
			dist[2][3] = dist[3][2] = switchCost[v];
			dist[0][2] = dist[2][0] = e.second.first;
			dist[1][3] = dist[3][1] = e.second.second;

			for (int k = 0; k < 4; k++)
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						chkmin(dist[i][j], dist[i][k] + dist[k][j]);

			for (int mask = 0; mask < 4; mask++)
				jump_dist[mask][0][v] = dist[!!(mask & 1)][2 + !!(mask & 2)];

			dfs_jump(v, u);
		}

		post[u] = time;
	};
	dfs_jump(1, -1);

	for (int j = 1; j < MAXJ; j++) {
		for (int u = 1; u <= n; u++) {
			jump[j][u] = jump[j - 1][jump[j - 1][u]];

			for (int from = 0; from < 2; from++) {
				for (int mid = 0; mid < 2; mid++) {
					for (int to = 0; to < 2; to++) {
						chkmin(jump_dist[to + 2 * from][j][u], 
							jump_dist[mid + 2 * from][j - 1][u] + jump_dist[to + 2 * mid][j - 1][jump[j - 1][u]]);
					}
				}
			}
		}
	}

	auto is_lca = [&](int u, int lca) {
		return pre[lca] <= pre[u] && post[u] <= post[lca];
	};

	auto find_lca = [&](int u, int v) {
		if (dep[u] > dep[v]) swap(u, v);

		if (is_lca(v, u)) return u;
		for (int j = MAXJ - 1; j >= 0; j--) {
			if (!is_lca(v, jump[j][u]))
				u = jump[j][u];
		}

		return jump[0][u];		
	};

	auto calc_dist = [&](int u, int uc, int lca) {
		vector<ll> ans(2, 0);
		ans[!uc] = switchCost[u];

		auto go = [&](int j) {
			vector<ll> new_ans(2, LLONG_MAX);
			for (int mask = 0; mask < 4; mask++)
				chkmin(new_ans[mask & 1], ans[!!(mask & 2)] + jump_dist[mask][j][u]);
			ans = move(new_ans);
			u = jump[j][u];
		};

		for (int j = MAXJ - 1; j >= 0; j--) {
			if (is_lca(jump[j][u], lca)) {
				go(j);
			}
		}

		return ans;
	};

	CASE(q) {
		int u,v; R(u,v); u++; v++;

		int uc = u % 2;
		int vc = v % 2;
		u /= 2;
		v /= 2;

		int lca = find_lca(u, v);
		vector<ll> ud = calc_dist(u, uc, lca);
		vector<ll> vd = calc_dist(v, vc, lca);
		
		W(min(ud[0] + vd[0], ud[1] + vd[1]));
	}

	return 0;
}

static auto __init__ = [](){
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif
	cout << fixed << setprecision(10);
	return 42;
}();