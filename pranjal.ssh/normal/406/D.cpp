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



vvi g;
vi p, st, sub;
vvi jump;

void dfs(int u) {
	static int ctr = 0;
	st[u] = ++ctr;
	sub[u] = 1;
	for(auto it : g[u]) {
		if(it == p[u]) continue;
		p[it] = u;
		dfs(it);
		sub[u] += sub[it];
	}
}

void pre(int n) {
	jump = vvi(20, vi(n + 1));
	st = sub = p = vi(n + 1);
	dfs(n);
	FOR (i, 1, n) jump[0][i] = p[i];
	FOR (i, 1, 19) {
		FOR (j, 1, n) {
			jump[i][j] = jump[i - 1][jump[i - 1][j]];
		}
	}
}
inline bool insub(int u, int v) {
	return st[u] >= st[v] and st[u] < st[v] + sub[v];
}
int lca(int u, int v) {
	if(insub(u, v)) return v;
	NFOR (i, 19, 0) {
		if(jump[i][v] and !insub(u, jump[i][v]))
			v = jump[i][v];
	}
	return p[v];
}

int main() 
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n; cin >> n;
	vector <pair<ll, ll>> a(n + 1);

	FOR (i, 1 , n) cin >> a[i].F >> a[i].S;
	g = vvi(n + 1);

	vi hull = {n};

	NFOR (i, n - 1, 1) {
		while(sz(hull) >= 2) {
			auto p1 = a[i];
			auto p2 = a[hull[sz(hull) - 1]];
			auto p3 = a[hull[sz(hull) - 2]];

			ll num = (p3.S - p1.S) * (p2.F - p1.F) + p1.S * (p3.F - p1.F);
			if (num > p2.S * (p3.F - p1.F)) {
				hull.pop_back();
				continue;
			}
			break;
		}
		g[hull.back()].pb(i);
		hull.pb(i);
	}
	pre(n);

	TCASE {
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << " "; 
	}

	return 0;	
}