#pragma GCC optimize ("O3", "unroll-loops")
// #pragma GCC target ("avx2")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
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
		long long getMod() const { return MODVALUE; }
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


struct Query {
	const static int INSERT = 0;
	const static int QUERY = 1;

	int tp;
	int mul;
	int addto;
	array<int, 3> p;
};
vector<Query> query;

template<class T, T (*func)(T, T)>
struct BIT {
	vector<T> bit;
	const int N;
	
	inline void upd(int idx, T val) {
		for (int i = idx; i <= N; i += i & -i)
			bit[i] = func(bit[i], val);
	}

	inline T qry(int idx) {
		T ans = 0;
		for (int i = idx; i > 0; i -= i & -i)
			ans = func(ans, bit[i]);
		return ans;
	}

	inline BIT(int N) : N(N) {
		bit.resize(N + 1);
	}
};

int add(int x, int y) {
	return x + y;
}
BIT<int, add> bit(100007);

vector<int> ans;
void solve(vector<int>& q) {
	for (auto& i : q) {
		if (query[i].tp == Query::INSERT)
			bit.upd(query[i].p[0], +1);
		else
			ans[query[i].addto] += query[i].mul * bit.qry(query[i].p[0]);
	}

	for (auto& i : q) {
		if (query[i].tp == Query::INSERT)
			bit.upd(query[i].p[0], -1);
	}
}

void CDQ(vector<int>& q) {
	const int n = (int)q.size();
	if (n <= 1) return;

	const int mid = (n - 1) / 2;

	vector<int> l, r;
	for (int i = 0; i < n; i++)
		(i <= mid ? l : r).emplace_back(q[i]);
	CDQ(l);
	CDQ(r);

	vector<int> cur;
	cur.reserve(q.size());
	for (int i = 0; i < n; i++) {
		if ((i <= mid && query[q[i]].tp == Query::INSERT) ||
			(i > mid && query[q[i]].tp == Query::QUERY))
			cur.emplace_back(q[i]);
	}

	sort(cur.begin(), cur.end(), [&](int x, int y) {
		if (query[x].p[1] != query[y].p[1]) return query[x].p[1] < query[y].p[1];
		return query[x].tp < query[y].tp;
	});
	solve(cur);
}

int main() {
	int x,y,z,n,m,k; R(x,y,z,n,m,k);

	int xl = INT_MAX, yl = INT_MAX, zl = INT_MAX;
	int xr = INT_MIN, yr = INT_MIN, zr = INT_MIN;
	for (int i = 0; i < n; i++) {
		int x,y,z; R(x,y,z);
		chkmin(xl, x);
		chkmin(yl, y);
		chkmin(zl, z);
		chkmax(xr, x);
		chkmax(yr, y);
		chkmax(zr, z);
	}

	ans = vector<int>(k + 1, 0);
	vector<int> q;
	for (int i = 0; i < m; i++) {
		int x,y,z; R(x,y,z);
		query.emplace_back( Query{ Query::INSERT, 0, 0, array<int, 3>{ x, y, z } } );
	}

	auto addQuery = [&](int x[2], int y[2], int z[2], int addto) {
		for (int mask = 0; mask < 8; mask++) {
			query.emplace_back(Query{ 
				Query::QUERY,
				__builtin_popcount(mask) % 2 == 1 ? +1 : -1,
				addto,
				array<int, 3>{ x[mask >> 0 & 1], y[mask >> 1 & 1], z[mask >> 2 & 1] } 
			});
		}
	};

	{
		int vx[2] = { xl - 1, xr };
		int vy[2] = { yl - 1, yr };
		int vz[2] = { zl - 1, zr };
		addQuery(vx, vy, vz, k);
	}

	vector<vector<int>> pts(k);
	for (int i = 0; i < k; i++) {
		int x,y,z; R(x,y,z);
		int vx[2] = { min(xl, x) - 1, max(xr, x) };
		int vy[2] = { min(yl, y) - 1, max(yr, y) };
		int vz[2] = { min(zl, z) - 1, max(zr, z) };
		addQuery(vx, vy, vz, i);
 
		pts[i] = { x, y, z };
	}

	q.reserve(query.size());
	for (int i = 0; i < (int)query.size(); i++)
		q.emplace_back(i);

	sort(q.begin(), q.end(), [&](int x, int y) {
		if (query[x].p[2] != query[y].p[2]) return query[x].p[2] < query[y].p[2];
		return query[x].tp < query[y].tp;
	});
	CDQ(q);

	auto isOpen = [&](int x, int y, int z) {
		return xl <= x && x <= xr &&
				yl <= y && y <= yr &&
				zl <= z && z <= zr;
	};

	if (ans[k] > 0) {
		W("INCORRECT");
	}
	else {
		W("CORRECT");
		for (int i = 0; i < k; i++)
			if (isOpen(pts[i][0], pts[i][1], pts[i][2]))
				W("OPEN");
			else if (ans[i] == 0)
				W("UNKNOWN");
			else
				W("CLOSED");
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