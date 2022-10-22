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


template<class T>
struct MCMF {
// private:
	int size;

	struct Edge {
		int to;
		T cap;
		T cost;
		int rev;

		Edge(int to, T cap, T cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) { }
	};

	vector<vector<Edge>> graph;
	vector<T> dist;
	vector<T> flow;
	vector<T> pot;
	vector<bool> inQueue;
	vector<bool> done;
	vector<pair<int, int>> pre;

	void SPFA() {
		queue<int> Q;
		for (int u = 0; u < size; u++) {
			dist[u] = 0;
			inQueue[u] = true;
			Q.push(u);
		}

		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();

			inQueue[u] = false;
			for (int i = 0; i < (int)graph[u].size(); i++) {
				const Edge& e = graph[u][i];
				if (e.cap > 0 && dist[u] + e.cost < dist[e.to]) {
					dist[e.to] = dist[u] + e.cost;
					if (!inQueue[e.to]) {
						Q.push(e.to);
						inQueue[e.to] = true;
					}
				}
			}
		}

		swap(pot, dist);
	}

	pair<T, T> dijkstra(int s, int t, bool n2dijkstra) {
		for (int u = 0; u < size; u++) {
			dist[u] = numeric_limits<T>::max();
			done[u] = false;
		}

		dist[s] = 0;
		flow[s] = numeric_limits<T>::max();
		if (n2dijkstra) {
			while (true) {
				int u = -1; T d = numeric_limits<T>::max();
				for (int v = 0; v < size; v++)
					if (!done[v] && dist[v] < d) {
						u = v;
						d = dist[v];
					}
				if (u == -1) break;
				done[u] = true;

				for (int i = 0; i < (int)graph[u].size(); i++) {
					const Edge& e = graph[u][i];
					if (e.cap > 0 && dist[u] + e.cost + pot[u] - pot[e.to] < dist[e.to]) {
						flow[e.to] = min(flow[u], e.cap);
						dist[e.to] = dist[u] + e.cost + pot[u] - pot[e.to];
						pre[e.to] = { u, i };
					}
				}
			}
		}
		else {
			priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> PQ;
			PQ.push({ 0, s });
			while (!PQ.empty()) {
				int u = PQ.top().second;
				PQ.pop();
				if (done[u]) continue;
				done[u] = true;

				for (int i = 0; i < (int)graph[u].size(); i++) {
					const Edge& e = graph[u][i];
					if (e.cap > 0 && dist[u] + e.cost + pot[u] - pot[e.to] < dist[e.to]) {
						flow[e.to] = min(flow[u], e.cap);
						dist[e.to] = dist[u] + e.cost + pot[u] - pot[e.to];
						pre[e.to] = { u, i };
						PQ.push({ dist[e.to], e.to });
					}
				}
			}
		}

		if (dist[t] == numeric_limits<T>::max()) return { 0, 0 };
		// if (dist[t] >= 0) return { 0, 0 };

		int u = t;
		while (u != s) {
			Edge& e = graph[pre[u].first][pre[u].second];
			e.cap -= flow[t];
			graph[u][e.rev].cap += flow[t];
			u = pre[u].first;
		}

		for (int u = 0; u < size; u++)
			dist[u] += pot[u] - pot[s];
		swap(pot, dist);

		return { flow[t], flow[t] * pot[t] };
	}

public:
	pair<T, T> mcmf(int s, int t, bool n2dijkstra = true) {
		T ans_flow = 0, ans_cost = 0;
		SPFA();
		while (true) {
			pair<T, T> res = dijkstra(s, t, n2dijkstra);
			if (res.first == 0) break;
			ans_flow += res.first;
			ans_cost += res.second;
		}
		return { ans_flow, ans_cost };
	}
	
	void addedge(int u, int v, T cap, T cost) {
		Edge a(v, cap, cost, graph[v].size());
		Edge b(u, 0, -cost, graph[u].size());
		graph[u].push_back(move(a));
		graph[v].push_back(move(b));
	}

	MCMF(int size) : size(size), graph(size), dist(size), flow(size), pot(size), inQueue(size), done(size), pre(size) { }
};

int main() {
	int n1,n2,m,r,b; R(n1,n2,m,r,b);

	const int SRC = n1 + n2;
	const int SINK = n1 + n2 + 1;
	const int SS = n1 + n2 + 2;
	const int TT = n1 + n2 + 3;
	MCMF<int> flow(n1 + n2 + 4);
	flow.addedge(SINK, SRC, INT_MAX, 0);

	string s1, s2; R(s1, s2);
	int reqS = 0, reqT = 0;
	for (int i = 0; i < n1; i++) {
		if (s1[i] == 'R') {
			flow.addedge(SRC, i, INT_MAX, 0);
			flow.addedge(SS, i, 1, 0);
			reqS++;
		}
		if (s1[i] == 'B') {
			flow.addedge(i, SINK, INT_MAX, 0);
			flow.addedge(i, TT, 1, 0);
			reqT++;
		}
		if (s1[i] == 'U') {
			flow.addedge(SRC, i, INT_MAX, 0);
			flow.addedge(i, SINK, INT_MAX, 0);
		}
	}
	for (int i = 0; i < n2; i++) {
		if (s2[i] == 'R') {
			flow.addedge(i + n1, SINK, INT_MAX, 0);
			flow.addedge(i + n1, TT, 1, 0);
			reqT++;
		}
		if (s2[i] == 'B') {
			flow.addedge(SRC, i + n1, INT_MAX, 0);
			flow.addedge(SS, i + n1, 1, 0);
			reqS++;
		}
		if (s2[i] == 'U') {
			flow.addedge(SRC, i + n1, INT_MAX, 0);
			flow.addedge(i + n1, SINK, INT_MAX, 0);
		}
	}
	flow.addedge(SRC, TT, reqS, 0);
	flow.addedge(SS, SINK, reqT, 0);

	vector<pii> euv(m);
	vector<pii> eid(m);
	for (int i = 0; i < m; i++) {
		int u,v; R(u,v); u--; v--;
		euv[i].first = u;
		eid[i].first = flow.graph[u].size();
		flow.addedge(u, v + n1, 1, r);
		euv[i].second = v;
		eid[i].second = flow.graph[v + n1].size();
		flow.addedge(v + n1, u, 1, b);
	}

	pii ans = flow.mcmf(SS, TT, false);
	if (ans.first < reqS + reqT) {
		W(-1);
	}
	else {
		W(ans.second);
		string color(m, 'U');
		for (int i = 0; i < m; i++) {
			int u = euv[i].first;
			int v = euv[i].second;
			int uid = eid[i].first;
			int vid = eid[i].second;
			if (flow.graph[u][uid].cap == 0) color[i] = 'R';
			if (flow.graph[v + n1][vid].cap == 0) color[i] = 'B';
		}
		W(color);
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