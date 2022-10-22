#pragma GCC optimize ("O3", "unroll-loops")
//#pragma GCC target ("avx2")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
namespace {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int,int> pii;
	typedef pair<ll,ll> pll;
	template <class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
	template <class T> using maxheap = priority_queue<T, vector<T>, greater<T>>;
	template <int MODVALUE>
	struct Modular {
	private:
		long long val;

		template<class T>
		static Modular toModular(const T& m) {
			long long val = m;
			if (val < 0) val += MODVALUE;
			if (val >= MODVALUE) val -= MODVALUE;
			return Modular(val);
		}

	public:
		bool operator == (const Modular& other) {return val == other.val;}
		bool operator != (const Modular& other) {return !(val == other.val);}
		template<class T> bool operator == (const T& other) {return *this == Modular(other);}
		template<class T> bool operator != (const T& other) {return !(*this == Modular(other));}
		template<class T> friend bool operator == (const T& other, const Modular& m) {return Modular(other) == m;}
		template<class T> friend bool operator != (const T& other, const Modular& m) {return !(Modular(other) == m);}

		bool operator < (const Modular& other) {return val < other.val;}
		bool operator <= (const Modular& other) {return val <= other.val;}
		bool operator > (const Modular& other) {return val > other.val;}
		bool operator >= (const Modular& other) {return val >= other.val;}
		template<class T> bool operator < (const T& other) {return *this < Modular(other);}
		template<class T> bool operator <= (const T& other) {return *this <= Modular(other);}
		template<class T> bool operator > (const T& other) {return *this > Modular(other);}
		template<class T> bool operator >= (const T& other) {return *this >= Modular(other);}
		template<class T> friend bool operator < (const T& other, const Modular& m) {return Modular(other) < m;}
		template<class T> friend bool operator <= (const T& other, const Modular& m) {return Modular(other) <= m;}
		template<class T> friend bool operator > (const T& other, const Modular& m) {return Modular(other) > m;}
		template<class T> friend bool operator >= (const T& other, const Modular& m) {return Modular(other) >= m;}

		Modular operator + (const Modular& other) {return toModular(val + other.val);}
		Modular& operator += (const Modular& other) {return *this = *this + other;}
		template<class T> Modular operator + (const T& other) {return *this + Modular(other);}
		template<class T> Modular& operator += (const T& other) {return *this += Modular(other);}
		template<class T> friend Modular operator + (const T& other, const Modular& m) {return Modular(other) + m;}
		template<class T> friend Modular operator += (const T& other, const Modular& m) {return Modular(other) += m;}

		Modular& operator ++() {return *this += 1;}
		Modular operator ++(int) {Modular tmp = *this; ++*this; return tmp;}

		Modular operator - () const {return Modular(-val);}
		Modular operator - (const Modular& other) {return toModular(val - other.val);}
		Modular& operator -= (const Modular& other) {return *this = *this - other;}
		template<class T> Modular operator - (const T& other) {return *this - Modular(other);}
		template<class T> Modular& operator -= (const T& other) {return *this -= Modular(other);}
		template<class T> friend Modular operator - (const T& other, const Modular& m) {return Modular(other) - m;}
		template<class T> friend Modular operator -= (const T& other, const Modular& m) {return Modular(other) -= m;}

		Modular& operator --() {return *this -= 1;}
		Modular operator --(int) {Modular tmp = *this; --*this; return tmp;}

		Modular operator * (const Modular& other) {return toModular(val * other.val % MODVALUE);}
		Modular& operator *= (const Modular& other) {return *this = *this * other;}
		template<class T> Modular operator * (const T& other) {return *this * Modular(other);}
		template<class T> Modular operator *= (const T& other) {return *this *= Modular(other);}
		template<class T> friend Modular operator * (const T& other, const Modular& m) {return Modular(other) * m;}
		template<class T> friend Modular operator *= (const T& other, const Modular& m) {return Modular(other) *= m;}

		Modular pow(long long power) {
			Modular m = *this, ans = 1;
			while (power) {
				if (power & 1) ans *= m;
				m *= m;
				power >>= 1;
			}
			return ans;
		}
		Modular pow(Modular& other) {return pow(other.val);}
		Modular inv() {return pow(MODVALUE-2);}

		Modular operator / (const Modular& other) {return *this * other;}
		Modular operator /= (const Modular& other) {return *this = *this / other;}
		template<class T> Modular operator / (const T& other) {return *this / Modular(other);}
		template<class T> Modular operator /= (const T& other) {return *this /= Modular(other);}
		template<class T> friend Modular operator / (const T& other, const Modular& m) {return Modular(other) / m;}
		template<class T> friend Modular operator /= (const T& other, const Modular& m) {return Modular(other) /= m;}

		friend istream& operator >> (istream& in, Modular& m) {in >> m.val; m = toModular(m.val % MODVALUE); return in;}
		friend ostream& operator << (ostream& out, const Modular& m) {return out << m.val;}

		Modular() : val(0) {}
		Modular(int val) : val(val % MODVALUE) {};
		Modular(long long val) : val(val % MODVALUE) {};
	};
}
namespace input {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
} using namespace input;
namespace output {
	template<class T> inline void _W(const T& x);
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p);
	template<class T> inline void _W(const vector<T>& x);
	template<class T> inline void _W(const deque<T>& x);
	template<class T> inline void _W(const forward_list<T>& x);
	template<class T> inline void _W(const list<T>& x);
	template<class T1, class T2, class T3> inline void _W(const set<T1,T2,T3>& x);
	template<class T> inline void _W(const multiset<T>& x);
	template<class T> inline void _W(const unordered_set<T>& x);
	template<class T> inline void _W(const unordered_multiset<T>& x);
	template<class T1, class T2, class T3> inline void _W(const map<T1, T2, T3>& x);
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x);
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x);
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x);

	template<class T> inline void _W(const T& x) {cout << x;}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
	template<class T> inline void _W(const vector<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const deque<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const forward_list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2, class T3> inline void _W(const set<T1,T2,T3>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const unordered_set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const unordered_multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2, class T3> inline void _W(const map<T1, T2, T3>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}

	template<class T> inline void _W(const ordered_set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace output;
namespace output_format{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
	inline string YN(bool b) {return b ? "YES" : "NO";}
} using namespace output_format;
namespace utility{
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
	inline bool chkmin(ll& x, ll y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(ll& x, int y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(int& x, ll y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(int& x, int y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmax(ll& x, ll y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(ll& x, int y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(int& x, ll y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(int& x, int y) {return x < y ? x = y, 1 : 0;}
} using namespace utility;
namespace std {
    template <class T1, class T2> struct hash<pair<T1,T2>> {
    	std::size_t operator()(pair<T1,T2> _) const {
        	return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
    	}
    };
}
using Mint = Modular<MOD>;


template<class T>
struct SegTree {
	struct node {
		T val = 0;
		T lazy = 0;
	} nullNode;

	const int leafSize;
	vector<node> segtree;

	node merge(node a, node b) {
		node tmp;
		tmp.val = max(a.val, b.val);
		return tmp;
	}

	void upd(node& a, T val, int l, int r) {
		a.val += val;
	}

	void updlazy(node& a, T val, int l, int r) {
		a.lazy += val;
	}

	void pushdown(int id, int l, int r) {
		if (segtree[id].lazy != nullNode.lazy && l < r) {
			int mid = (l+r)>>1;
			upd(segtree[id<<1], segtree[id].lazy, l, mid);
			upd(segtree[id<<1|1], segtree[id].lazy, mid+1, r);
			updlazy(segtree[id<<1], segtree[id].lazy, l, mid);
			updlazy(segtree[id<<1|1], segtree[id].lazy, mid+1, r);
			segtree[id].lazy = nullNode.lazy;
		}
	}

	void update(int id, int l, int r, int ql, int qr, T val) {
		if (qr < l || r < ql) return;
		pushdown(id, l, r);
		if (ql <= l && r <= qr) {
			upd(segtree[id], val, l, r);
			updlazy(segtree[id], val, l, r);
			return;
		}
		int mid = (l+r)>>1;
		if (ql <= mid) update(id<<1, l, mid, ql, qr, val);
		if (mid < qr) update(id<<1|1, mid+1, r, ql, qr, val);
		segtree[id] = merge(segtree[id<<1], segtree[id<<1|1]);
	}

	node query(int id, int l, int r, int ql, int qr) {
		if (qr < l || r < ql) return nullNode;
		pushdown(id, l, r);
		if (ql <= l && r <= qr)
			return segtree[id];
		int mid = (l+r)>>1;
		if (qr <= mid) return query(id<<1, l, mid, ql, qr);
		if (mid < ql) return query(id<<1|1, mid+1, r, ql, qr);
		return merge(query(id<<1, l, mid, ql, qr), query(id<<1|1, mid+1, r, ql, qr));
	}

	void build(int id, int l, int r, vector<T>& v) {
		if (l == r) {
			upd(segtree[id], v[l], l, r);
			return;
		}
		int mid = (l+r)>>1;
		build(id<<1, l, mid, v);
		build(id<<1|1, mid+1, r, v);
		segtree[id] = merge(segtree[id<<1], segtree[id<<1|1]);
	}

	void update(int ql, int qr, T val) {
//		W("update!",ql,qr,val);
		if (ql > qr) return;
		update(1, 0, leafSize-1, ql, qr, val);
	}

	node query(int ql, int qr) {
		return query(1, 0, leafSize-1, ql, qr);
	}

	SegTree(int size) : leafSize(size) {
		segtree.resize(leafSize<<2);
	}

	SegTree(vector<T>& v) : leafSize(v.size()) {
		segtree.resize(leafSize<<2);
		build(1, 0, leafSize-1, v);
	}
};

void getst(SegTree<ll>& st, int ysz) {
//	W("segtree");
//	for (int i = 0; i < ysz; i++)
//		cout << st.query(i,i).val << " \n"[i == ysz-1];
}

struct Query {
	bool isQ;
	int x, y, v;
	
	bool operator < (Query& other) {
		if (x != other.x)
			return x < other.x;
			
		return isQ > other.isQ;
	}
	
	Query(bool isQ, int p1, int p2, int p3) : isQ(isQ) {
		if (isQ) {
			x = p1;
			v = p2;
			assert(p3 == -1);
		} else {
			x = p1;
			y = p2;
			v = p3;
		}
	}
	
	friend ostream& operator << (ostream& out, const Query& q) {
		return out << (q.isQ ? "Query " : "Update ") << q.x << ' ' << q.y << ' ' << q.v;
	}
};

int main() {
	int n,m,p; R(n,m,p);
	vector<pii> a(n); R(a);
	vector<pii> b(m); R(b);
	vector<pair<pii,int>> c(p); R(c);
	
	sort(all(a));
	for (int i = n-2; i >= 0; i--)
		chkmin(a[i].S, a[i+1].S);
		
	sort(all(b));
	for (int i = m-2; i >= 0; i--)
		chkmin(b[i].S, b[i+1].S);
	
	vector<int> yUsed;
	for (int i = 0; i < p; i++)
		yUsed.pb(c[i].F.S);

	distinct(yUsed);
	int ysz = yUsed.size();
	
//	W("yUsed", yUsed);
	
	ll ans = -(a[0].S + b[0].S);
	SegTree<ll> st(ysz);
	int last = -1;
	for (int i = 0; i < m; i++) {
		int disc = lower_bound(all(yUsed), b[i].F) - yUsed.begin() - 1;
		if (disc == -1) {
			b[i].S = 0;
			continue;
		}
		st.update(last + 1, disc, -b[i].S);
		last = disc;
	}
	st.update(last + 1, ysz - 1, -1e12);
	
	getst(st, ysz);
	
	vector<Query> qry;
	for (int i = 0; i < n; i++)
		qry.pb({true, a[i].F, a[i].S, -1});
	for (int i = 0; i < p; i++)
		qry.pb({false, c[i].F.F, c[i].F.S, c[i].S});
		
	sort(all(qry));
	
	for (int i = 0; i < n+p; i++) {
		if (qry[i].isQ) {
			ll maxv = st.query(0, ysz-1).val;
//			W("Q", maxv, maxv - qry[i].v);
			chkmax(ans, maxv - qry[i].v);
		} else {
			int disc = lower_bound(all(yUsed), qry[i].y) - yUsed.begin();
			st.update(disc, ysz - 1, qry[i].v);
		}
		getst(st, ysz);
	}
	
	W(ans);

	return 0;
}

static auto _batch_ios = [](){
	#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);
	return 42;
}();