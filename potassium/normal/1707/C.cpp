#pragma GCC optimize ("O3", "unroll-loops")
// #pragma GCC target ("avx2")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
// #define pb push_back
// #define mp make_pair
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
	mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
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


struct dsu {
	vector<int> p, sz;

	dsu(int N) {
		p.resize(N + 1);
		iota(p.begin(), p.end(), 0);
		sz.resize(N + 1, 1);
	}

	int find(int u) {
		return u == p[u] ? u : p[u] = find(p[u]);
	}

	bool uni(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)
			return false;

		if (sz[u] < sz[v])
			swap(u, v);

		p[v] = u;
		sz[u] += sz[v];

		return true;
	}
};

int main() {
	int n,m; R(n,m);
	vector<vector<int>> g(n + 1);
	dsu dsu(n + 1);
	vector<pii> bad;
	for (int i = 0; i < m; i++) {
		int u,v; R(u,v);
		if (dsu.uni(u, v)) {
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		else {
			bad.push_back({ u, v });
		}
	}

	const int MAXJ = 20;
	vector<int> dep(n + 1, -1);
	vector<vector<int>> jump(MAXJ + 1, vector<int>(n + 1, -1));
	function<void(int, int)> dfs = [&](int u, int p) {
		jump[0][u] = p;
		for (auto& v : g[u]) {
			if (v == p) continue;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	};
	dep[1] = 0;
	dfs(1, 1);

	for (int j = 1; j <= MAXJ; j++)
		for (int u = 1; u <= n; u++)
			jump[j][u] = jump[j - 1][jump[j - 1][u]];

	auto lca = [&](int u, int v) {
		if (dep[u] > dep[v]) swap(u, v);
		for (int j = MAXJ; j >= 0; j--)
			if ((dep[v] - dep[u]) >> j & 1)
				v = jump[j][v];

		assert(dep[u] == dep[v]);
		if (u == v) return u;

		for (int j = MAXJ; j >= 0; j--)
			if (jump[j][u] != jump[j][v]) {
				u = jump[j][u];
				v = jump[j][v];
			}

		return jump[0][u];
	};

	auto mov = [&](int u, int step) {
		for (int j = MAXJ; j >= 0; j--)
			if (step >> j & 1)
				u = jump[j][u];
		return u;
	};

	vector<int> val(n + 1, 0);
	for (auto& p : bad) {
		int u = p.first;
		int v = p.second;
		if (dep[u] > dep[v]) swap(u, v);
		int l = lca(u, v);

		if (l != u && l != v) {
			val[1] -= 1;
			val[u] += 1;
			val[v] += 1;
		}
		else {
			assert(l == u);
			int uc = mov(v, dep[v] - dep[u] - 1);
			val[uc] -= 1;
			val[v] += 1;
		}
	}

	function<void(int, int)> dfs2 = [&](int u, int p) {
		for (auto& v : g[u]) {
			if (v == p) continue;
			val[v] += val[u];
			dfs2(v, u);
		}
	};
	dfs2(1, 1);

	string ans;
	for (int u = 1; u <= n; u++)
		ans += "01"[val[u] == 0];

	W(ans);

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