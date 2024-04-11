#pragma GCC optimize ("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << ' '
#define EL << '\n'
#define FL << flush
#define sqr(x) ((x)*(x))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i,l,r) for (int i = l; i < r; i++)
#define FORD(i,r,l) for (int i = r; i > l; i--)
using namespace std;
//using namespace __gnu_pbds;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> bst;
namespace input {
	template<class T> inline void _R(T &x) {cin >> x;}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
} using namespace input;
namespace overload_output {
	template<class T1, class T2> inline ostream& operator << (ostream& out, pair<T1,T2>& p) {return out << p.first << ' ' << p.second;}
	template<class T> inline ostream& operator << (ostream& out, vector<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, deque<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, forward_list<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, list<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, set<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, multiset<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, unordered_set<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, unordered_multiset<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, map<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, multimap<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, unordered_map<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, unordered_multimap<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
} using namespace overload_output;
namespace output {
	template<class T> inline void _W(const T& x) {cout << x;}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
	template<class T> inline void _W(const vector<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const deque<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const forward_list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2, class T3> inline void _W(const set<T1,T2,T3>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const unordered_set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const unordered_multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2> inline void _W(const map<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace output;


template<class T>
struct segment_tree{
	private:
	struct _node {
		ll _val = LLINF;
		int _idx = 0;
		ll _lazy = 0;
	} nullNode;

	vector<_node> _segtree;
	int _leaf_size = 0;

	inline _node __merge(_node a, _node b) {
		_node temp;
		if (a._val < b._val) {
			temp._val = a._val;
			temp._idx = a._idx;
		} else {
			temp._val = b._val;
			temp._idx = b._idx;
		}
		return temp;
	}

	inline void __init(int id, T val, int l, int r) {
		_segtree[id]._val = val;
		_segtree[id]._idx = l;
	}

	inline void __upd(int id, T val, int l, int r) {
		_segtree[id]._val += val;
	}

	inline void __lazy_upd(int id, T newtag, int l, int r) {
		_segtree[id]._lazy += newtag;
	}

	inline void __pushdown(int id, int l, int r) {
		if (_segtree[id]._lazy != nullNode._lazy) {
			if (l < r) {
				int mid = (l+r)>>1;
				__upd(id*2,_segtree[id]._lazy,l,mid);
				__upd(id*2+1,_segtree[id]._lazy,mid+1,r);
				__lazy_upd(id*2,_segtree[id]._lazy,l,mid);
				__lazy_upd(id*2+1,_segtree[id]._lazy,mid+1,r);
			}
			_segtree[id]._lazy = nullNode._lazy;
		}
	}

 	inline void update(int id, int l, int r, int ql, int qr, T val) {
		if (qr < l || r < ql) return;
		__pushdown(id,l,r);
		if (ql <= l && r <= qr) {
			__upd(id,val,l,r);
			__lazy_upd(id,val,l,r);
			return;
		}
		int mid = (l+r)>>1;
		update(id*2,l,mid,ql,qr,val);
		update(id*2+1,mid+1,r,ql,qr,val);
		_segtree[id] = __merge(_segtree[id*2],_segtree[id*2+1]);
	}

	inline void update(int id, int l, int r, int q, T val) {
		__pushdown(id,l,r);
		if (l == r) {
			__upd(id,val,l,r);
			return;
		}
		int mid = (l+r)>>1;
		if (q <= mid)
			update(id*2,l,mid,q,val);
		else
			update(id*2+1,mid+1,r,q,val);
		_segtree[id] = __merge(_segtree[id*2],_segtree[id*2+1]);
	}

	inline _node query(int id, int l, int r, int ql, int qr) {
		if (qr < l || r < ql) return nullNode;
		__pushdown(id,l,r);
		if (ql <= l && r <= qr) return _segtree[id];
		int mid = (l+r)>>1;
		return __merge(query(id*2,l,mid,ql,qr),query(id*2+1,mid+1,r,ql,qr));
	}

	inline void build(int id, int l, int r, vector<T>& v) {
		if (l == r) {
			__init(id,v[l],l,r);
			return;
		}
		int mid = (l+r)>>1;
		build(id*2,l,mid,v);
		build(id*2+1,mid+1,r,v);
		_segtree[id] = __merge(_segtree[id*2],_segtree[id*2+1]);
	}

	public:
	inline void update(int ql, int qr, T val) {
		update(1,0,_leaf_size-1,ql,qr,val);
	}

	inline _node query(int ql, int qr) {
		return query(1,0,_leaf_size-1,ql,qr);
	}

	inline segment_tree(vector<T>& v) {
		_segtree.resize(1 << __lg(v.size()-1)+2);
		_leaf_size = v.size();
		build(1,0,v.size()-1,v);
	}

	inline segment_tree(int size) {
		_segtree.resize(1 << __lg(size-1)+2, nullNode);
		_leaf_size = size;
	}
};

int main() {
	int n; R(n);
	vector<ll> v(n); for (auto& i : v) R(i);

	segment_tree<ll> st(v);

	vector<int> ans(n);
	for (int i = 1; i <= n; i++) {
		int idx = st.query(0,n-1)._idx;
		ans[idx] = i;
		st.update(idx+1,n-1,-i);
		st.update(idx,idx,1e18);
	}

	W(ans);

 	return 0;
}

static auto _batch_ios = [](){
	#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	#endif
	cout << fixed << setprecision(12);
	return 42;
}();