#pragma GCC optimize ("O3", "unroll-loops")
//#pragma GCC target ("avx2")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
using namespace __gnu_pbds;
namespace {
	const int MOD107 = 1000000007;
	const int MOD998 = 998244353;
	using ll = long long;
	using ull = unsigned long long;
	using pii = pair<int, int>;
	using pll = pair<ll, ll>;
	template <class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
		}

		inline void validate(const Modular& other) const {
			assert(MODVALUE != 0);
			assert(MODVALUE == other.MODVALUE);
			other.validate();
		}
	#else
		inline void validate() const { }
		inline void validate(const Modular& other) const { }
	#endif

	public:
		explicit operator long long() const { return val; }

		template<class T> Modular& operator = (const T& other) { val = other; return *this; }
		template<class T> void setMod(const T& MOD) { MODVALUE = MOD; }

		bool operator == (const Modular& other) { validate(other); return val == other.val; }
		bool operator != (const Modular& other) { return !(*this == other); }
		template<class T> bool operator == (const T& other) { return *this == initModular(other); }
		template<class T> bool operator != (const T& other) { return *this != initModular(other); }
		template<class T> friend bool operator == (const T& other, const Modular& m) { return m.initModular(other) == m; }
		template<class T> friend bool operator != (const T& other, const Modular& m) { return m.initModular(other) != m; }

		bool operator <  (const Modular& other) { validate(other); return val <  other.val; }
		bool operator <= (const Modular& other) { validate(other); return val <= other.val; }
		bool operator >  (const Modular& other) { validate(other); return val >  other.val; }
		bool operator >= (const Modular& other) { validate(other); return val >= other.val; }
		template<class T> bool operator <  (const T& other) { return *this <  initModular(other); }
		template<class T> bool operator <= (const T& other) { return *this <= initModular(other); }
		template<class T> bool operator >  (const T& other) { return *this >  initModular(other); }
		template<class T> bool operator >= (const T& other) { return *this >= initModular(other); }
		template<class T> friend bool operator <  (const T& other, const Modular& m) { return m.initModular(other) <  m; }
		template<class T> friend bool operator <= (const T& other, const Modular& m) { return m.initModular(other) <= m; }
		template<class T> friend bool operator >  (const T& other, const Modular& m) { return m.initModular(other) >  m; }
		template<class T> friend bool operator >= (const T& other, const Modular& m) { return m.initModular(other) >= m; }

		Modular& operator += (const Modular& other) { validate(other); val += other.val; val %= MODVALUE; return *this; }
		Modular  operator +  (const Modular& other) { Modular tmp = *this; return tmp += other; }
		template<class T> Modular& operator += (const T& other) { return *this += initModular(other); }
		template<class T> Modular  operator +  (const T& other) { return *this +  initModular(other); }
//		template<class T> friend Modular operator += (const T& other, const Modular& m) { return m.initModular(other) += m; }
		template<class T> friend Modular operator +  (const T& other, const Modular& m) { return m.initModular(other) +  m; }

		Modular& operator ++()    { return *this += 1; }
		Modular  operator ++(int) { Modular tmp = *this; ++*this; return tmp; }

		Modular  operator -  () const { return initModular(-val); }
		Modular& operator -= (const Modular& other) { validate(other); val -= other.val; val += MODVALUE; val %= MODVALUE; return *this;}
		Modular  operator -  (const Modular& other) { Modular tmp = *this; return tmp -= other; }
		template<class T> Modular& operator -= (const T& other) { return *this -= initModular(other); }
		template<class T> Modular  operator -  (const T& other) { return *this -  initModular(other); }
//		template<class T> friend Modular operator -= (const T& other, const Modular& m) { return m.initModular(other) -= m; }
		template<class T> friend Modular operator -  (const T& other, const Modular& m) { return m.initModular(other) -  m; }

		Modular& operator --()    { return *this -= 1; }
		Modular  operator --(int) { Modular tmp = *this; --*this; return tmp; }

		Modular& operator *= (const Modular& other) { validate(other); val *= other.val; val %= MODVALUE; val += MODVALUE; val %= MODVALUE; return *this; }
		Modular  operator *  (const Modular& other) { Modular tmp = *this; return tmp *= other; }
		template<class T> Modular& operator *= (const T& other) { return *this *= initModular(other); }
		template<class T> Modular  operator *  (const T& other) { return *this *  initModular(other); }
//		template<class T> friend Modular operator *= (const T& other, const Modular& m) { return m.initModular(other) *= m; }
		template<class T> friend Modular operator *  (const T& other, const Modular& m) { return m.initModular(other) *  m; }

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
		Modular inv() const { return pow(MODVALUE-2); }

		Modular& operator /= (const Modular& other) { val *= other.inv().val; val %= MODVALUE; return *this; }
		Modular  operator /  (const Modular& other) { Modular tmp = *this; return tmp /= other; }
		template<class T> Modular& operator /= (const T& other) { return *this /= initModular(other); }
		template<class T> Modular  operator /  (const T& other) { return *this /  initModular(other); }
//		template<class T> friend Modular operator /= (const T& other, const Modular& m) { return m.initModular(other) /= m; }
		template<class T> friend Modular operator /  (const T& other, const Modular& m) { return m.initModular(other) /  m; }

		friend istream& operator >> (istream& in, Modular& m) { in >> m.val; m.val %= m.MODVALUE; m.val += m.MODVALUE; m.val %= m.MODVALUE; return in; }
		friend ostream& operator << (ostream& out, const Modular& m) { return out << m.val; }

		Modular() { val = 0; MODVALUE = 0; }
		Modular(long long val, long long MOD) : MODVALUE(MOD), val((val % MOD + MOD) % MOD) { }
	};
	using Mint = Modular;
	inline ll pow(ll b, ll p, ll mod) {
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
	template <class T> inline bool chkmin(T&x, const T& y) { return x > y ? x = y, 1 : 0; }
	template <class T> inline bool chkmax(T&x, const T& y) { return x < y ? x = y, 1 : 0; }
}
namespace IO {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
	template<class T> inline void _R(deque<T> &x) {for (auto& i : x) _R(i);}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}

	template<class T> inline void _W(const T& x);
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p);
	template<class... T> inline void _W(const vector<T...>& x);
	template<class... T> inline void _W(const deque<T...>& x);
	template<class... T> inline void _W(const forward_list<T...>& x);
	template<class... T> inline void _W(const list<T...>& x);
	template<class... T> inline void _W(const set<T...>& x);
	template<class... T> inline void _W(const multiset<T...>& x);
	template<class... T> inline void _W(const unordered_set<T...>& x);
	template<class... T> inline void _W(const unordered_multiset<T...>& x);
	template<class... T> inline void _W(const map<T...>& x);
	template<class... T> inline void _W(const multimap<T...>& x);
	template<class... T> inline void _W(const unordered_map<T...>& x);
	template<class... T> inline void _W(const unordered_multimap<T...>& x);

	template<class T> inline void _W(const ordered_set<T>& x);

	template<class Container> inline void printContainer(const Container& x) { bool isFirst = 1; for (auto i : x) { if (!isFirst) cout << ' '; isFirst = 0; _W(i); } }

	template<class T> inline void _W(const T& x) {cout << x;}
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

	template<class T> inline void _W(const ordered_set<T>& x) { printContainer(x); }

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
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
const Mint ZERO = Mint(0, MOD998);


struct ACA {
	const static int SIGMA = 26;
	static int toNum(char c) {
		return c - 'a';
	}
	
	struct Node {
		vector<int> trie = vector<int>(SIGMA, -1);
		vector<int> next = vector<int>(SIGMA, 0);
		int link = -1;
		int succ = -1;
		int tag = -1;
	};
	vector<Node> dfa = vector<Node>(1);
	
	int insert(string& str, int idx) {
		int now = 0;
		for (char& ch : str) {
			int to = toNum(ch);
			if (dfa[now].trie[to] == -1) {
				dfa[now].trie[to] = dfa[now].next[to] = (int)dfa.size();
				dfa.emplace_back(Node());
			}
			now = dfa[now].trie[to];
		}
		dfa[now].tag = idx;
		return now;
	}
	
	void build() {
		queue<int> Q;
		dfa[0].link = 0;
		Q.push(0);
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			for (int to = 0; to < SIGMA; to++) {
				if (dfa[u].trie[to] != -1) {
					int v = dfa[u].trie[to];
					dfa[v].link = (u == 0 ? 0 : dfa[dfa[u].link].next[to]);
					dfa[v].succ = (dfa[dfa[v].link].tag != -1 ? dfa[v].link : dfa[dfa[v].link].succ);
					for (int j = 0; j < SIGMA; j++) {
						if (dfa[v].trie[j] == -1) {
							dfa[v].next[j] = dfa[dfa[v].link].next[j];
						}
					}
					Q.push(v);
				}
			}
		}
	}
};

int getNode(ACA& aca, string& str) {
	int now = 0;
	for (char& ch : str) {
		int to = ACA::toNum(ch);
		if (aca.dfa[now].trie[to] == -1)
			return -1;
		now = aca.dfa[now].trie[to];
	}
	return now;
}

struct LazyMax {
	maxheap<int> pq;
	maxheap<int> lazy;
	
	int get() {
		while (!lazy.empty() && pq.top() == lazy.top()) {
			pq.pop();
			lazy.pop();
		}
		return pq.top();
	}
	
	void remove(int val) {
		lazy.push(val);
	}
	
	void insert(int val) {
		pq.push(val);
	}
};

vector<int> group;
vector<LazyMax> groupQ;
int qry(ACA& aca, string& text) {
	int ans = -1;
	
	int now = 0;
	for (auto& ch : text) {
		int to = ACA::toNum(ch);
		now = aca.dfa[now].next[to];

		int tmp = (aca.dfa[now].tag != -1 ? now : aca.dfa[now].succ);
		while (tmp != -1) {
			int tag = aca.dfa[tmp].tag;
			chkmax(ans, groupQ[tag].get());
			tmp = aca.dfa[tmp].succ;
		}
	}
	
	return ans;
}

int main() {
	int n,m; R(n,m);
	vector<string> dict;
	ACA aca;
	
	group.resize(n, -100000);
	
	for (int i = 0; i < n; i++) {
		string s; R(s);
		int idx = getNode(aca, s);
		if (idx == -1) {
			idx = aca.insert(s, (int)dict.size());
			dict.emplace_back(s);
		} else if (aca.dfa[idx].tag == -1) {
			aca.dfa[idx].tag = (int)dict.size();
			dict.emplace_back(s);
		}
		
		group[i] = aca.dfa[idx].tag;
	}
	
	vector<int> val(n, 0);
	groupQ.resize((int)dict.size());
	for (int i = 0; i < n; i++) {
		groupQ[group[i]].insert(0);
	}
	
	aca.build();
	
	while (m--) {
		int ty; R(ty);
		
		if (ty == 1) {
			int idx, x; R(idx, x); --idx;
			int gpn = group[idx];
			
			groupQ[gpn].remove(val[idx]);
			val[idx] = x;
			groupQ[gpn].insert(val[idx]);
		} else {
			string q; R(q);
			W(qry(aca, q));
		}
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