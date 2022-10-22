#include <bits/stdc++.h>
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
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {cout << p.first << ' ' << p.second;}
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

	template<class T> inline void _W(T &x) {cout << x << ' ';}
	inline void W() {cout << "\n";}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); W(y...);}
} using namespace output;

vector<ll> v(300007);
int n,m,k;

template<class T>
struct segment_tree{
	struct _node {
		long long presum = -INF;
		long long sufsum = -INF;
		long long sum = -INF;
		long long subsum = -INF;
	} nullNode;

	vector<_node> _segment_tree;
	int _leaf_size = 0;

	inline _node __merge(_node Lchild, _node Rchild) {
		_node temp;
		temp.presum = max(Lchild.presum,Lchild.sum+Rchild.presum);
		temp.sufsum = max(Rchild.sufsum,Rchild.sum+Lchild.sufsum);
		temp.sum = Lchild.sum + Rchild.sum;
		temp.subsum = max(max(Lchild.subsum,Rchild.subsum),Lchild.sufsum+Rchild.presum);
		return temp;
	}

	inline void __init(int id, _node val) {
		_segment_tree[id].presum = val.presum;
		_segment_tree[id].sufsum = val.sufsum;
		_segment_tree[id].sum = val.sum;
		_segment_tree[id].subsum = val.subsum;
	}

	inline void build(int id, int l, int r, vector<_node>& v) {
		if (l == r) {
			__init(id,v[l]);
			return;
		}
		int mid = (l+r)/2;
		build(id*2,l,mid,v);
		build(id*2+1,mid+1,r,v);
		_segment_tree[id] = __merge(_segment_tree[id*2],_segment_tree[id*2+1]);
	}

	public:
	inline long long query_subsum() {
		return _segment_tree[1].subsum;
	}

	inline segment_tree(vector<_node>& _v) {
		_segment_tree.resize(1 << __lg(v.size()-1)+2);
		_leaf_size = _v.size();
		build(1,0,_v.size()-1,_v);
	}
};

vector<segment_tree<ll>::_node> vv;

int main() {
	R(n,m,k);
	for (int i = 0; i < n; i++) R(v[i]);
	ll ans = 0;
	for (int start = 0; start < m; start++) {
		vv.clear();
		vv.shrink_to_fit();
		vv.reserve(n/m+10);
		int blocks = (n-1-start)/m+1;
		for (int j = 0; j < blocks; j++) {
			segment_tree<ll>::_node temp;
			ll cur = 0;
			ll maxs = 0;
			for (int l = start+j*m; l < min(start+(j+1)*m,n); l++) {
				cur += v[l];
				maxs = max(maxs, cur);
			}
			temp.presum = maxs-k;
			temp.sum = cur-k;
			cur = maxs = 0;
			for (int l = min(start+(j+1)*m,n)-1; l >= start+j*m; l--) {
				cur += v[l];
				maxs = max(maxs,cur);
			}
			temp.sufsum = maxs-k;
			cur = maxs = 0;
			ll last = 0;
			for (int l = start+j*m; l < min(start+(j+1)*m,n); l++) {
				cur = max(last+v[l],v[l]);
				last = cur;
				maxs = max(maxs,cur);
   			}
   			temp.subsum = maxs-k;
			vv.pb(temp);
		}
		segment_tree<ll> st = vv;
		ans = max(ans,st.query_subsum());
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