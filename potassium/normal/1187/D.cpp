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
#define ll long long
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

template<class T>
struct segment_tree{
	private:
	struct _node {
		int _val = INF;
	} nullNode;
	
	vector<_node> _segment_tree;
	int _leaf_size = 0;
	
	inline _node __merge(_node a, _node b) {
		_node temp;
		temp._val = min(a._val,b._val);
		return temp;
	}
	
	inline void __init(int id, T val) {
		_segment_tree[id]._val = val;
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
	
	inline _node query(int id, int l, int r, int ql, int qr) {
		if (qr < l || r < ql) return nullNode;
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
	
	public:
	inline void update(int ql, int qr, int val) {
		update(1,0,_leaf_size-1,ql,qr,val);
	}
	
	inline T query(int ql, int qr) {
		return query(1,0,_leaf_size-1,ql,qr)._val;
	}
	
	inline segment_tree(vector<T>& v) {
		_segment_tree.resize(1 << __lg(v.size()-1)+2);
		_leaf_size = v.size();
		build(1,0,v.size()-1,v);
	}
};

stack<int> s[300007];
vector<int> loc(300007);

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		vector<int> v(n);
		vector<int> v2(n);
		bool isPossible = 1;
		
		for (int i = 1; i <= n; i++)
			while (!s[i].empty())
				s[i].pop();
		
		for (int i = 0; i < n; i++)
			cin >> v[i];
		for (int i = n-1; i >= 0; i--)
			s[v[i]].push(i);
		
		for (int i = 0; i < n; i++) {
			cin >> v2[i];
			if (s[v2[i]].empty())
				isPossible = 0;
			else  {
				loc[i] = s[v2[i]].top();
				s[v2[i]].pop();
			}
		}
		
		segment_tree<int> st(v);
		for (int i = 0; i < n; i++) {
			if (st.query(0,loc[i]) < v2[i]) {
				isPossible = 0;
				break;
			} else
				st.update(loc[i],loc[i],INF);
		}
		
		if (!isPossible) {
			cout << "NO" EL;
		} else {
			cout << "YES" EL;
		}
	}
			
	return 0;
}
 
/*
  _____                                               _               _       _                   _ _ 
 |  __ \                                             (_)             (_)     | |                 | | |
 | |__) | __ ___   __ _ _ __ __ _ _ __ ___  _ __ ___  _ _ __   __ _   _ ___  | |__   __ _ _ __ __| | |
 |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \| '_ ` _ \| | '_ \ / _` | | / __| | '_ \ / _` | '__/ _` | |
 | |   | | | (_) | (_| | | | (_| | | | | | | | | | | | | | | | (_| | | \__ \ | | | | (_| | | | (_| |_|
 |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|_| |_| |_|_|_| |_|\__, | |_|___/ |_| |_|\__,_|_|  \__,_(_)
                   __/ |                                       __/ |                                  
                  |___/                                       |___/                                                                                 
*/

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