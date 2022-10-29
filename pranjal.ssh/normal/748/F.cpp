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

inline int add(int a, int b, int m = inf) {if ((a += b) >= m)a -= m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}

vvi g;
vi special;
vi sub;
vvi avail;
void pre(int u, int p) {
	sub[u] = special[u];
	for (int v : g[u]) {
		if (v == p) continue;
		pre(v, u);
		sub[u] += sub[v];
	}
}

int findRoot(int u, int p) {
	for (int v : g[u]) {
		if (v == p) continue;
		if (sub[v] > sub[0] - sub[v])
			return findRoot(v, u);
	}
	return u;
}

void dfs(int u, int p, int w) {
	if (special[u]) avail[w].push_back(u);
	sub[u] = special[u];
	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u, w);
		sub[u] += sub[v];
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n, k; cin >> n >> k;
	g = vvi(n);
	FOR (i, 1, n - 1) {
		int u, v; cin >> u >> v; --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sub = special = vi(n);
	FOR (i, 1, 2*k) {
		int x; cin >> x; --x;
		special[x] = 1;
	}
	pre(0, -1);
	int root = findRoot(0, -1);
	avail = vvi(n);
	if (special[root]) avail[root].push_back(root);
	for (int it : g[root]) dfs(it, root, it);

	priority_queue<pair<int, int>> pq;
	if (special[root]) pq.push({1, root});
	for (int it : g[root]) if (sub[it]) pq.push({sub[it], it});

	cout << "1\n" << root + 1 << "\n";
	
	while (!pq.empty()) {
		auto mx = pq.top();
		pq.pop();
		auto mx2 = pq.top();
		pq.pop();
		cout << avail[mx.S].back() + 1 << " " << avail[mx2.S].back() + 1 << " " << root + 1 << "\n";
		avail[mx.S].pop_back();
		avail[mx2.S].pop_back();
		if (mx.F - 1) pq.push({mx.F - 1, mx.S});
		if (mx2.F - 1) pq.push({mx2.F - 1, mx2.S});
	}
	
	return 0;	
}