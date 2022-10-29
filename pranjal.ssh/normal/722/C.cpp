#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;


#define TRACE

#ifdef TRACE
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define pr(...)
#define pra(a,n)
#define praa(a,n,m)
#endif

#define inc_stack_limit const rlim_t kStackSize = 64 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define pres(s,x) (s.find(x)!=s.end())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i, n) FOR (i, 0, (n) - 1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)

const ll inf2 = 1e15;
const int inf = 1e9 + 7;

inline int add(int a, int b, int m = inf) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = inf) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}



template <typename node>
struct ST {

#define mid ((l+r)>>1)

	int n;
	vector<node> T;

	ST(int n): n(n), T(4 * n + 10) {}
	void build(int no, int l, int r, vector<int> &arr) {
		if (l == r) {T[no] = node(arr[l]) ; return;}

		build(no << 1, l, mid, arr);
		build(no << 1 | 1, mid + 1, r, arr);
		T[no] = node::merge(T[no << 1], T[no << 1 | 1]);		
	}

	void upd(int no, int l, int r, int pos) {

		if (l == r) {T[no]=node(-inf2); return;}
		if (pos <= mid) upd(no << 1, l, mid, pos);
		else upd(no << 1 | 1, mid + 1, r, pos);

		T[no] = node::merge(T[no << 1], T[no << 1 | 1]);
	}
};

struct node {
	ll prefix, suffix, sum, total;
	node() : prefix(0), suffix(0), sum(0), total(0) {} 
	node(ll val) : prefix(val), suffix(val), sum(val), total(val) {}
	static node merge(const node&x, const node&y) {
		node ans;
		ans.prefix = max({x.prefix, x.total + y.prefix, -inf2});
		ans.suffix = max({y.suffix, y.total + x.suffix, -inf2});
		ans.total = max({x.total + y.total, -inf2});
		ans.sum = max({x.sum, y.sum, x.suffix + y.prefix, -inf2});
		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vi a(n + 1);
	FOR(i, 1, n) cin >> a[i];

	ST<node> T(n + 10);
	T.build(1,1,n,a);

	FOR(i,1,n){
		int d;cin>>d;
		T.upd(1,1,n,d);
		ll x = T.T[1].sum;
		if(x<0) x = 0;
		cout<<x<<"\n";
	}


	return 0;
}