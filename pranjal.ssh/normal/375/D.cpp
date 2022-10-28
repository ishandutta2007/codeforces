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
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
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

const int N = 1e5+5;
vvi g;
vi f,c,tc,a,st,en; 

inline void add_mo(int pos) {
	f[tc[pos]]++;
	a[f[tc[pos]]]++;
}

inline void remove_mo(int pos) {
	a[f[tc[pos]]]--;
	f[tc[pos]]--;
}
void dfs(int u, int p) {
	static int ctr = -1;
	st[u] = ++ctr;
	tc[st[u]] = c[u];
	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	en[u] = ctr;
}

vector<pair<ii, ii>> q;

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n, Q; cin >> n >> Q;
	g = vvi(n);
	
	c = vi(n);
	tc = vi(n);

	FOR (i, 0, n - 1) cin >> c[i];
	FOR (i, 0, n - 2) {	
		int u, v; cin >> u >> v; --u, --v;
		g[u].pb(v); g[v].pb(u);
	}
	st = en = vi(n);
	dfs(0, -1);
	


	vector<pair<ii, ii>> q;
	FOR (i, 0, Q - 1) {
		int v, k; cin >> v >> k;--v;
		q.pb({{st[v], en[v]},{k, i}});
	}


	const int K = 330;

	sort(all(q), [&K](const pair<ii, ii>& x, const pair<ii, ii>& y) {
		return x.F.F / K == y.F.F / K ? x.F.S < y.F.S : x.F.F / K < y.F.F / K;
	});


	int l = 0, r = 0;
	vi ans(Q);
	f = a = vi(N);
	add_mo(0);  // ******** IMPORTANT


	for (auto &it : q) {
		int ql = it.F.F, qr = it.F.S;
		while (r < qr) {
			++r;
			add_mo(r);
		}
		while (r > qr) {
			remove_mo(r);
			--r;
		}
		while (l > ql) {
			--l;
			add_mo(l);
		}
		while (l < ql) {
			remove_mo(l);
			++l;
		}

		ans[it.S.S] = a[it.S.F];
	}

	FOR (i, 0, Q - 1) cout << ans[i] << "\n";



	return 0;
}