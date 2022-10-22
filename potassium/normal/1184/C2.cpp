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

	inline void __init(int id, T val) {
		_segment_tree[id]._val = val;
	}
	
	inline void __update(int id, int val, int l, int r) {
		_segment_tree[id]._val += val;
	}

	inline void update(int id, int l, int r, int ql, int qr, int val) {
		if (qr < l || r < ql) return;
		if (_segment_tree[id]._lazy != 0) {
			if (l < r) {
				_segment_tree[id*2]._val += _segment_tree[id]._lazy;
				_segment_tree[id*2]._lazy += _segment_tree[id]._lazy;
				_segment_tree[id*2+1]._val += _segment_tree[id]._lazy;
				_segment_tree[id*2+1]._lazy += _segment_tree[id]._lazy;
			}
			_segment_tree[id]._lazy = 0;
		}
		if (ql <= l && r <= qr) {
			__update(id,val,l,r);
			_segment_tree[id]._lazy += val;
			return;
		}
		int mid = (l+r)/2;
		update(id*2,l,mid,ql,qr,val);
		update(id*2+1,mid+1,r,ql,qr,val);
		_segment_tree[id] = __merge(_segment_tree[id*2],_segment_tree[id*2+1]);
	}

	inline _node query(int id, int l, int r, int ql, int qr) {
		if (qr < l || r < ql) return nullNode;
		if (_segment_tree[id]._lazy != 0) {
			if (l < r) {
				_segment_tree[id*2]._val += _segment_tree[id]._lazy;
				_segment_tree[id*2]._lazy += _segment_tree[id]._lazy;
				_segment_tree[id*2+1]._val += _segment_tree[id]._lazy;
				_segment_tree[id*2+1]._lazy += _segment_tree[id]._lazy;
			}
			_segment_tree[id]._lazy = 0;
		}
		if (ql <= l && r <= qr) return _segment_tree[id];
		int mid = (l+r)/2;
		return __merge(query(id*2,l,mid,ql,qr),query(id*2+1,mid+1,r,ql,qr));
	}

	inline void build(int id, int l, int r, vector<T>& v) {
		if (l == r) {
			__init(id,v[l]);
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
	inline void update(int ql, int qr, int val) {
		update(1,0,_leaf_size-1,ql,qr,val);
	}

	inline query() {
		return _segment_tree[1]._val;
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

struct disc_map{
	vector<int> NumUsed;
	unordered_map<int,int> m;

	public:
	inline void insert(int x) {NumUsed.push_back(x);}
	void discretize() {
		sort(NumUsed.begin(),NumUsed.end());
		NumUsed.resize(unique(NumUsed.begin(),NumUsed.end())-NumUsed.begin());
		int cur = -1;
		for (auto& i : NumUsed)
			m[i] = ++cur;
	}
	inline int operator[] (int x) {return m[x];}
	inline int size() {return m.size();}
	disc_map(int N) {NumUsed.reserve(N);m.reserve(N);}
};

vector<vector<pii> > va, vr;
vector<pair<pii,pii> > v;

int main() {
	int n,r; R(n,r);
	
	disc_map dm(n*2);
	v.reserve(n*2);

	for (int i = 0; i < n; i++) {
		int x,y; R(x,y);
		int xl = x+y-r;
		int xr = xl+2*r;
		int yl = x-y-r;
		int yr = yl+2*r;
		dm.insert(xl);
		dm.insert(xr);
		dm.insert(yl);
		dm.insert(yr);
		v.pb(mp(mp(xl,xr),mp(yl,1)));
		v.pb(mp(mp(xl,xr),mp(yr,-1)));
	}
	
	dm.discretize();
	va.resize(dm.size());
	vr.resize(dm.size());
	
	for (auto& i : v) {
		i.F.F = dm[i.F.F];
		i.F.S = dm[i.F.S];
		i.S.F = dm[i.S.F];
		if (i.S.S == 1) va[i.S.F].pb(i.F); else vr[i.S.F].pb(i.F);
	}
	
	segment_tree<int> st(dm.size());
	
	int ans = 0;
	
	for (int i = 0; i < dm.size(); i++) {
		for (auto j : va[i])
			st.update(j.first,j.second,1);
		ans = max(ans,st.query());
		for (auto j : vr[i])
			st.update(j.first,j.second,-1);
	}
	
	W(ans);

	return 0;
}

#ifndef LOCAL
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
#endif