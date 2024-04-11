#pragma GCC optimize ("Ofast")
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
#define pb push_back
#define mp make_pair
#define F first
#define S second
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
	template<class T> inline void _W(const T& x) {cout << x << ' ';}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(p.second);}
	template<class T> inline void _W(const vector<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const deque<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const forward_list<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const list<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const set<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const multiset<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const unordered_set<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const unordered_multiset<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const map<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {for (auto i : x) cout << i << ' ';}

 	inline void W() {cout << '\n';}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); W(y...);}
} using namespace output;

template<class T>
struct segment_tree{
	private:
	struct _node {
		int _val = 0;
		int _lazy = 0;
	} nullNode;

	vector<_node> _segment_tree;
	int _leaf_size = 0;

	inline _node __merge(_node a, _node b) {
		_node temp;
		temp._val = max(a._val,b._val);
		return temp;
	}

 	inline void update2(int id, int l, int r, int ql, int qr, int val) {
		if (qr < l || r < ql) return;
		int mid = (l+r)/2;
		if (_segment_tree[id]._lazy != 0) {
			if (l < r) {
				_segment_tree[id*2]._lazy = max(_segment_tree[id*2]._lazy, _segment_tree[id]._lazy);
				_segment_tree[id*2+1]._lazy = max(_segment_tree[id*2+1]._lazy, _segment_tree[id]._lazy);
			} else {
				_segment_tree[id]._val = max(_segment_tree[id]._val,_segment_tree[id]._lazy);
			}
			_segment_tree[id]._lazy = 0;
		}
		if (ql <= l && r <= qr) {
			_segment_tree[id]._lazy += val;
			return;
		}
		update2(id*2,l,mid,ql,qr,val);
		update2(id*2+1,mid+1,r,ql,qr,val);
		_segment_tree[id] = __merge(_segment_tree[id*2],_segment_tree[id*2+1]);
	}
	
	inline void update1(int id, int l, int r, int q, int val) {
		if (_segment_tree[id]._lazy != 0) {
			if (l < r) {
				_segment_tree[id*2]._lazy = max(_segment_tree[id*2]._lazy, _segment_tree[id]._lazy);
				_segment_tree[id*2+1]._lazy = max(_segment_tree[id*2+1]._lazy, _segment_tree[id]._lazy);
			} else {
				_segment_tree[id]._val = max(_segment_tree[id]._val,_segment_tree[id]._lazy);
			}
			_segment_tree[id]._lazy = 0;
		}
		if (l == r) {
			_segment_tree[id]._val = val;
			return;
		}
		int mid = (l+r)/2;
		if (q <= mid)
			update1(id*2,l,mid,q,val);
		else
			update1(id*2+1,mid+1,r,q,val);
		_segment_tree[id] = __merge(_segment_tree[id*2],_segment_tree[id*2+1]);
	}

	inline _node query(int id, int l, int r, int ql, int qr) {
		if (qr < l || r < ql) return nullNode;
		int mid = (l+r)/2;
		if (_segment_tree[id]._lazy != 0) {
			if (l < r) {
				_segment_tree[id*2]._lazy = max(_segment_tree[id*2]._lazy, _segment_tree[id]._lazy);
				_segment_tree[id*2+1]._lazy = max(_segment_tree[id*2+1]._lazy, _segment_tree[id]._lazy);
			} else {
				_segment_tree[id]._val = max(_segment_tree[id]._val,_segment_tree[id]._lazy);
			}
			_segment_tree[id]._lazy = 0;
		}
		if (ql <= l && r <= qr) return _segment_tree[id];
		return __merge(query(id*2,l,mid,ql,qr),query(id*2+1,mid+1,r,ql,qr));
	}

	inline void build(int id, int l, int r, vector<T>& v) {
		if (l == r) {
    		_segment_tree[id]._val = v[l];
			return;
		}
		int mid = (l+r)/2;
		build(id*2,l,mid,v);
		build(id*2+1,mid+1,r,v);
		_segment_tree[id] = __merge(_segment_tree[id*2],_segment_tree[id*2+1]);
	}

	inline void build_default(int id, int l, int r) {
		if (l == r) {
			_segment_tree[id] = nullNode;
			return;
		}
		int mid = (l+r)/2;
		build_default(id*2,l,mid);
		build_default(id*2+1,mid+1,r);
		_segment_tree[id] = __merge(_segment_tree[id*2],_segment_tree[id*2+1]);
	}

	public:
	inline void update2(int val) {
		update2(1,0,_leaf_size-1,0,_leaf_size-1,val);
	}
	
	inline void update1(int p, int x) {
		update1(1,0,_leaf_size-1,p,x);
	}

	inline T query(int ql, int qr) {
		return query(1,0,_leaf_size-1,ql,qr)._val;
	}

	inline segment_tree(vector<T>& v) {
		_segment_tree.resize(1 << __lg(v.size()-1)+2);
		_leaf_size = v.size();
		build(1,0,v.size()-1,v);
	}

	inline segment_tree(int size) {
		_segment_tree.resize(1 << __lg(size-1)+2);
		_leaf_size = size;
		build_default(1,0,size-1);
	}
};

int main() {
	int n; R(n);
	vector<int> v; v.resize(n);
	for (int i = 0; i < n; i++) R(v[i]);
	
	segment_tree<int> st = v;
	
	int q; R(q);
	while (q--) {
		int cmd; R(cmd);
		if (cmd == 1) {
			int p,x; R(p,x);
			p--;
			st.update1(p,x);
		} else {
			int x; R(x);
			st.update2(x);
		}
	}
	
	for (int i = 0; i < n; i++)
		_W(st.query(i,i));
	
	return 0;
}

#ifndef LOCAL
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
#endif