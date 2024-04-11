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
#define CASE(x) int x; cin >> x; while (x--)
using namespace std;
//using namespace __gnu_pbds;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> bst;
namespace input {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
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

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace output;
namespace utility{
	inline ll pow(ll b, ll p, ll mod) {
		b %= mod;
		long long ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
} using namespace utility;



template <class T>
struct sparse_table{
	private:
	static const int maximumlog2layers = 20;
	vector<T> _sparse_table[maximumlog2layers];
	inline T __func(T a, T b) {
		return min(a,b);
	}

	public:
	inline T& operator () (int lg2, int l) {return _sparse_table[lg2][l];}
	inline int size(int x) {return _sparse_table[x].size();}
	inline T query(int l, int r) {
		if (l > r) return -1;
		int _range = __lg(r-l+1);
		return(__func(_sparse_table[_range][l],_sparse_table[_range][r-(1<<_range)+1]));
	}
	inline void build() {
		int baseSize = _sparse_table[0].size();
		for (int i = 1; i < maximumlog2layers; i++) {
			int curSize = baseSize - (1<<i) + 1;
			if (curSize > 0) {
				_sparse_table[i].clear();
				_sparse_table[i].reserve(curSize);
				for (int j = 0; j < curSize; j++)
					_sparse_table[i].push_back(__func(_sparse_table[i-1][j],_sparse_table[i-1][j+(1<<i-1)]));
			} else return;
		}
	}
	inline sparse_table(vector<T> &v) {_sparse_table[0] = v; build();}
	inline sparse_table(int _size) {_sparse_table[0].resize(_size);}
};

int main() {
	int n; R(n);
	vector<int> a(n); R(a);
	vector<int> rb(n,-1);
	vector<int> ans(n,-1);
	
	vector<int> b(2*n); for (int i = 0; i < 2*n; i++) b[i] = a[i % n];
	sparse_table<int> st(b);

	vector<int> order(n); for (int i = 0; i < n; i++) order[i] = i;
	sort(all(order), [&](int x, int y){return a[x] > a[y];});

	if (a[order[n-1]]*2 >= a[order[0]]) {
		for (int i = 0; i < n; i++)
			_W(-1), _W(' ');
		return 0;
	}
	
	set<int> done;

	for (int i = 0; i < n; i++) {
		int maxv = -1;
		int idx = order[i];
		int dist = 0;
		
		int rr = idx+n;
		
		if (i > 0) {
			auto it = done.lower_bound(idx);
			if (it == done.end()) it = done.lower_bound(-1);
			rr = *it + (*it < idx ? n : 0);
		}
		
		int ll = idx;
		rr--;
		
		if (st.query(ll,rr)*2 >= a[idx]) {
			int j = (rr+1) % n;
			ans[idx] = ans[j] + ((j-idx+n) % n);
		} else {
			while (rr >= ll) {
				int mid = (ll+rr)/2;
				if (st.query(ll,mid)*2 >= a[idx]) ll = mid + 1; else rr = mid - 1;
			}
			ans[idx] = (ll-idx+n) % n;
		}
		
		/*for (int j = idx; ;) {
			maxv = max(maxv,a[j]);
			if (a[j]*2 < maxv) {
				rb[idx] = j;
				ans[idx] = (j-idx+n) % n;
				break;
			}
			if (rb[j] != -1) {
				rb[idx] = rb[j];
				ans[idx] = ans[j] + ((j-idx+n) % n);
				break;
			}
			j++;
			if (j == n) j -= n;
		}*/
		
		done.insert(idx);
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