#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
typedef long long ll;
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

int total;

template<class T>
struct segment_tree{
	//private:
	struct _node {
		int gcd = 0;
	} nullNode;
	
	vector<_node> _segment_tree;
	int _leaf_size = 0;
	
	inline _node __merge(_node Lchild, _node Rchild) {
		_node temp;
		temp.gcd = __gcd(Lchild.gcd,Rchild.gcd);
		return temp;
	}
	
	inline void __init(int id, T val) {
		_segment_tree[id].gcd = val;
	}
	
	inline void update(int id, int l, int r, int ql, int qr, int val) {
		if (qr < l || r < ql) return;
		if (l == r) {
			__init(id,val);
			return;
		}
		int mid = (l+r)/2;
		update(id*2,l,mid,ql,qr,val);
		update(id*2+1,mid+1,r,ql,qr,val);
		_segment_tree[id] = __merge(_segment_tree[id*2],_segment_tree[id*2+1]);
	}
	
	inline void query(int id, int l, int r, int ql, int qr, int val) {
		if (qr < l || r < ql) return;
		if (_segment_tree[id].gcd % val == 0) return;
		if (l == r) {
			total++;
			return;
		}
		if (total > 1) return;
		int mid = (l+r)/2;
		query(id*2,l,mid,ql,qr,val);
		if (total > 1) return;
		query(id*2+1,mid+1,r,ql,qr,val);
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
	
	public:
	inline void update(int ql, int qr, int val) {
		update(1,0,_leaf_size-1,ql,qr,val);
	}
	
	inline bool query_isAC(int ql, int qr, int val) {
		total = 0;
		query(1,0,_leaf_size-1,ql,qr,val);
		return (total <= 1);
	}
	
	inline segment_tree(vector<T>& v) {
		_segment_tree.resize(1 << __lg(v.size()-1)+2);
		_leaf_size = v.size();
		build(1,0,v.size()-1,v);
	}
};
 
int main() {
	int n;
	cin >> n;
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.pb(x);
	}
	
	segment_tree<int> st(v);
	
	int q;
	cin >> q;
	while (q--) {
		int qx;
		cin >> qx;
		
		if (qx == 1) {
			int l,r,x;
			cin >> l >> r >> x;
			if (st.query_isAC(l-1,r-1,x))
				cout << "YES" EL;
			else
				cout << "NO" EL;
		}
		
		if (qx == 2) {
			int i,y;
			cin >> i >> y;
			st.update(i-1,i-1,y);
		}
	}
	
	return 0;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
template <class T1, class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << '(' << p.first << ',' << p.second << ')';
}
template <template <class...> class _TContainer, class... _T>
ostream& operator << (ostream& out, _TContainer<_T...>& _Container) {	
    out << '[';
    bool first = 1;
    for(auto x : _Container) {
    	if (!first) out << ',';
    	out << x;
    	first = 0;
    }
    out << ']';
    return out;
}