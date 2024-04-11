#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;

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

#define TRACE

#ifdef TRACE

#define cerr cout

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
#undef cerr
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
#define rep(n) FOR (_, 0, (n) - 1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;

const ll inf2 = 1e18;
const int inf = 1e9 + 7;

inline int add(int a, int b, int m = inf) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = inf) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}


template<typename T>
struct BIT1	// Point update,query
{
	vector<T> t;int n;BIT1(){n=0;}
	BIT1(int sz){ n=sz; t=vector<T>(sz+1,0);}
	void upd(int i, T val){while(i<=n) t[i]+=val, i+=i&-i;}
	T qry(int i){T ans=0; while(i>0) ans+=t[i],i-=i&-i; return ans;}
};

int main() 
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vi a(n + 1); FOR (i, 1, n) cin >> a[i];
	vvi divisors(n + 1);

	FOR (i, 1, n) {
		for (int j = i + i; j <= n; j += i)
			divisors[j].pb(i);
	}

	vvii queries(n + 1);
	
	FOR (i, 1, m) {
		int l, r; cin >> l >> r;
		queries[r].pb({l, i});
	}
	vll ans(m + 1);

	vi pos(n + 1);
	BIT1 <int> T(n + 1);
	int total = 0;

	FOR (r, 1, n) {
		pos[a[r]] = r;
		for (int i : divisors[a[r]])
			if (pos[i]) T.upd(pos[i], 1), ++total;

		for (int i = a[r]; i <= n; i += a[r])
			if (pos[i])	T.upd(pos[i], 1), ++total;

		for (auto &it : queries[r]) {
			ans[it.S] = total - T.qry(it.F - 1);
		}
	}

	FOR (i, 1, m)
		cout << ans[i] << "\n";



	return 0;	
}