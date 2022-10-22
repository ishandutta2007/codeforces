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


struct dsu_rb {
	vector<int> p, sz, d;

	vector<pii> rec;
	
	pii find(int u) {
		int w = 0;
		while (p[u] != u) {
			w ^= d[u];
			u = p[u];
		}
		return make_pair(u, w);
	}

	bool uni(int u, int v, int w) {
		pii ur = find(u);
		pii vr = find(v);
		if (ur.first == vr.first) return false;
		if (sz[ur.first] < sz[vr.first]) {
			swap(ur, vr);
			swap(u, v);
		}

		rec.push_back({ ur.first, vr.first });
		p[vr.first] = ur.first;
		d[vr.first] = vr.second ^ w ^ ur.second;
		sz[ur.first] += sz[vr.first];
		return true;
	}

	void persist() {
		rec.push_back({ -1, -1 });
	}

	void rollback() {
		while (rec.back().first != -1) {
			int u = rec.back().first;
			int v = rec.back().second;
			p[v] = v;
			d[v] = 0;
			sz[u] -= sz[v];
			rec.pop_back();
		}
		rec.pop_back();
	}

	dsu_rb(int N) : p(N), sz(N, 1), d(N, 0) { for (int i = 0; i < N; i++) p[i] = i; }
};

struct basis_rb {
	const static int SZ = 30;
	vector<int> basis = vector<int>(SZ, 0);
	vector<int> rec;

	void insert(int d) {
		for (int i = SZ - 1; i >= 0; i--) {
			if (d >> i & 1) {
				if (basis[i] >> i & 1) {
					d ^= basis[i];
				}
				else {
					basis[i] = d;
					rec.emplace_back(i);
					return;
				}
			}
		}
	}

	int query(int d) {
		for (int i = SZ - 1; i >= 0; i--)
			d = min(d, d ^ basis[i]);
		return d;
	}

	void persist() {
		rec.push_back(-1);
	}

	void rollback() {
		while (rec.back() != -1) {
			int i = rec.back();
			basis[i] = 0;
			rec.pop_back();
		}
		rec.pop_back();
	}
};

struct Query {
	int x, y, d;
};

int main() {
	int n,m; R(n,m);

	const int MAXQ = 262144;
	vector<vector<Query>> time_st(2 * MAXQ);
	function<void(int, int, int, int, int, Query&)> insert = [&](int id, int l, int r, int ql, int qr, Query& q) {
		if (ql <= l && r <= qr) {
			time_st[id].emplace_back(q);
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) insert(id * 2, l, mid, ql, qr, q);
		if (qr > mid) insert(id * 2 + 1, mid + 1, r, ql, qr, q);
	};

	map<pii, pii> edges;
	auto add = [&](int u, int v, int d, int t) {
		if (u > v) swap(u, v);
		edges[{ u, v }] = { t, d };
	};
	auto del = [&](int u, int v, int t) {
		if (u > v) swap(u, v);
		pii res = edges[{ u, v }];

		Query now;
		now.x = u;
		now.y = v;
		now.d = res.second;

		insert(1, 0, MAXQ - 1, res.first, t, now);
	};

	for (int i = 0; i < m; i++) {
		int u,v,d; R(u,v,d);
		add(u,v,d,0);
	}

	// int q; R(q);
	// int qcnt = 0;
	int qcnt = 1;
	vector<Query> queries(MAXQ, { -1, -1, -1 });
	// for (int t = 0; t < q; t++) {
	// 	int cmd; R(cmd);
	// 	if (cmd == 1) {
	// 		int u,v,d; R(u,v,d);
	// 		add(u,v,d,t);
	// 	}
	// 	else if (cmd == 2) {
	// 		int u,v; R(u,v);
	// 		del(u,v,t);
	// 		edges.erase({ u, v });
	// 	}
	// 	else if (cmd == 3) {
	// 		int u,v; R(u,v);
	// 		queries[t].x = u;
	// 		queries[t].y = v;
	// 		queries[t].d = qcnt++;
	// 	}
	// 	else assert(false);
	// }
	queries[0] = { 1, n, 0 };

	for (auto& e : edges) {
		del(e.first.first, e.first.second, MAXQ - 1);
	}

	dsu_rb dsu(n + 1);
	basis_rb basis;
	vector<int> ans(qcnt, -1);
	function<void(int)> dfs = [&](int id) {
		for (auto& q : time_st[id]) {
			if (!dsu.uni(q.x, q.y, q.d)) {
				int w = q.d ^ dsu.find(q.x).second ^ dsu.find(q.y).second;
				basis.insert(w);
			}
		}

		if (id < MAXQ) {
			for (int i = 0; i <= 1; i++) {
				dsu.persist();
				basis.persist();
				dfs(id * 2 + i);
				dsu.rollback();
				basis.rollback();
			}
		}
		else {
			if (queries[id - MAXQ].x != -1) {
				int w = dsu.find(queries[id - MAXQ].x).second ^ dsu.find(queries[id - MAXQ].y).second;
				ans[queries[id - MAXQ].d] = basis.query(w);
			}
		}
	};
	dfs(1);

	for (auto& i : ans)
		W(i);
	
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