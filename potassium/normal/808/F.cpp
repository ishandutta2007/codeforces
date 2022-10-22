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


template<class T>
struct dinic {
private:
	int size;

	struct Edge {
		int to;
		T cap;
		int rev;

		Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {};
	};

	vector<vector<Edge>> graph;
	vector<int> dist;
	vector<bool> isTrav;
	vector<int> cur;

	int sink;

	bool bfs(int s, int t) {
		for (int i = 0; i < size; i++) { isTrav[i] = 0; dist[i] = 0; cur[i] = 0; }

		queue<int> q;
		isTrav[s] = 1;
		q.push(s);
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < (int)graph[now].size(); i++) {
				int toNode = graph[now][i].to;
				if (!isTrav[toNode] && graph[now][i].cap > 0) {
					isTrav[toNode] = 1;
					q.push(toNode);
					dist[toNode] = dist[now] + 1;
					if (toNode == t) return 1;
				}
			}
		}
		return 0;
	}

	T dfs(int node, T flow) {
		if (node == sink) return flow;

		for (int& i = cur[node]; i < (int)graph[node].size(); i++) {
   			int toNode = graph[node][i].to;

			if (dist[toNode] == dist[node] + 1 && graph[node][i].cap > 0) {
				T toflow = dfs(toNode, min(flow, graph[node][i].cap));
				if (toflow) {
					graph[node][i].cap -= toflow;
					graph[toNode][graph[node][i].rev].cap += toflow;
					return toflow;
				}
   			}
		}
		return 0;
	}

public:
	T maxflow(int s, int t) {
		sink = t;
		T flow = 0;
		while (bfs(s, t))
			while (true) {
				T newflow = dfs(s, numeric_limits<T>::max());
				if (newflow)
					flow += newflow;
				else
					break;
			}
		return flow;
	}

	void addedge(int u, int v, T cap) {
		Edge a(v, cap, graph[v].size());
		Edge b(u, 0, graph[u].size());
		graph[u].push_back(move(a));
		graph[v].push_back(move(b));
	}

	void addedge_undir(int u, int v, T cap) {
		Edge a(v, cap, graph[v].size());
		Edge b(u, cap, graph[u].size());
		graph[u].push_back(move(a));
		graph[v].push_back(move(b));
	}

	dinic(int size) : size(size) {
		graph.resize(size);
		dist.resize(size);
		isTrav.resize(size);
		cur.resize(size);
	}
};

template<class T>
struct primeSieve {
	const int MAXN;
	vector<int> primes;
	vector<int> mpf;

	primeSieve(int n) : MAXN(n) {
		primes.clear();
		mpf.resize(n + 1);
		iota(mpf.begin(), mpf.end(), 0);

		for (int i = 2; i <= n; i++) {
			if (mpf[i] == i)
				primes.emplace_back(i);

			for (auto& j : primes) {
				T prod = 1LL * i * j;
				if (prod > MAXN)
					break;
					
				mpf[prod] = j;
				if (i % j == 0)
					break;
			}
		}
	}
};
primeSieve<long long> sieve(200000);

bool isPrime(int x) {
	return x == sieve.mpf[x];
}

int main() {
	int n,k; R(n,k);
	vector<pair<pair<int, int>, int>> a, a1;
	for (int i = 0; i < n; i++) {
		int p,c,l; R(p,c,l);
		(c == 1 ? a1 : a).push_back({ { p, c }, l });
	}
	sort(a.begin(), a.end(), [](auto& x, auto& y) {
		return (x.first.second % 2) < (y.first.second % 2);
	});

	n = (int)a.size();
	int m = (int)a1.size();

	auto go = [&](int mid) {
		const int ONE = n;
		const int SRC = n + 1;
		const int SINK = n + 2;
		dinic<int> flow(n + 3);

		int total = 0;
		vector<int> even;
		for (int i = 0; i < n; i++) {
			if (a[i].second > mid) continue;

			total += a[i].first.first;
			if (a[i].first.second % 2 == 0) {
				even.emplace_back(i);
				flow.addedge(SRC, i, a[i].first.first);
			}
			else {
				flow.addedge(i, SINK, a[i].first.first);
				for (int j : even)
					if (isPrime(a[j].first.second + a[i].first.second))
						flow.addedge(j, i, 1e9);
			}
		}

		int best1 = -1;
		int best1p = -1;
		for (int i = 0; i < m; i++) {
			if (a1[i].second <= mid && chkmax(best1p, a1[i].first.first))
				best1 = i;
		}

		if (best1 != -1) {
			total += best1p;
			flow.addedge(ONE, SINK, best1p);
			for (int j : even)
				if (isPrime(a[j].first.second + 1))
					flow.addedge(j, ONE, 1e9);
		}

		int mincut = flow.maxflow(SRC, SINK);
		return total - mincut >= k;
	};

	if (!go(n + m)) {
		W(-1);
		return 0;
	}

	int l = 1, r = n + m;
	while (r > l) {
		int mid = (l + r) / 2;
		
		if (go(mid))
			r = mid;
		else
			l = mid + 1;
	}

	W(l);

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