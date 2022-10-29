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
int M;

inline int add(int a, int b) {if ((a += b) >= M)a -= M; return a;}
inline int subt(int a, int b) {if ((a -= b) < 0)a += M; return a;}
inline int mul(int a, int b) {return (int)(((ll)a * (ll)b) % M);}


int expo(int a, int n) {
	ll ans = 1;
	ll x = a;
	while (n > 0) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
		n >>= 1;
	}
	return ans;
}

const int N = 1e5 + 10;
vii g[N + 10];
int sub[N + 10], vis[N + 10], p10[N + 10], pm10[N + 10];
map<int, int> mp,mpr;
int curn, p1;
ll ans;

void pre(int root, int par) {
	curn++;
	sub[root] = 1;
	for (ii & it : g[root]) {
		if (it.F == par or vis[it.F]) continue;
		pre(it.F, root);
		sub[root] += sub[it.F];
	}
}
int centroid(int root, int par) {
	for (ii & it : g[root])
		if (!vis[it.F] and it.F != par and sub[it.F] > curn / 2) return centroid(it.F, root);
	return root;
}

void include(int u, int par, int upar, int len) {
	ans += mpr[subt(0, mul(upar, pm10[len]))];
	ans += (upar == 0);
	
	for (ii & it : g[u]) {
		if (it.F == par or vis[it.F]) continue;
		include(it.F, u, (upar*10LL + it.S) % M, len + 1);
	}
}
void update(int u, int par, int upar, int len) {
	mp[subt(0, mul(upar, pm10[len]))]++;
	for (ii & it : g[u]) {
		if (it.F == par or vis[it.F]) continue;
		update(it.F, u, (upar*10LL + it.S) % M, len + 1);
	}
}
void includer(int u, int par, int upar, int len) {
	ans += mp[upar];
	ans += (upar == 0);
	for (ii & it : g[u]) {
		if (it.F == par or vis[it.F]) continue;
		includer(it.F, u, (it.S*1LL*p10[len] + upar) % M, len + 1);
	}
}
void updater(int u, int par, int upar, int len) {
	mpr[upar]++;
	for (ii & it : g[u]) {
		if (it.F == par or vis[it.F]) continue;
		updater(it.F, u, (it.S*1LL*p10[len] + upar) % M, len + 1);
	}
}

void decompose(int root) {
	curn = 0;
	pre(root, -1);
	int cent = centroid(root, -1);
	mp.clear();
	mpr.clear();
	vis[cent] = 1;

	for (ii & it : g[cent]) {
		if (vis[it.F]) continue;
		include(it.F, cent, it.S, 1);
		includer(it.F, cent, it.S, 1);
		update(it.F, cent, it.S, 1);
		updater(it.F, cent, it.S, 1);
	}

	for (ii & it : g[cent]) {
		if (vis[it.F]) continue;
		decompose(it.F);
	}
}

int totient(int x) {
	int ret = x;
	for (int i = 2; i*i <= x; ++i) {
		if (x % i == 0) {
			while (x > 1 and x % i == 0) x /= i;
			ret /= i, ret *= i - 1;
		}
	}
	if (x > 1) ret /= x, ret *= x - 1;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n; cin >> n >> M;
	if (M == 1) {
		cout << n * (n - 1LL) << "\n";
		return 0;
	}

	p10[0] = 1;
	pm10[0] = 1;
	p1 = expo(10, totient(M) - 1);

	
	FOR (i, 1, N + 5) p10[i] = mul(p10[i - 1], 10);
	FOR (i, 1, N + 5) pm10[i] = mul(pm10[i - 1], p1);

	FOR (i, 1, n - 1) {
		int u, v, d; cin >> u >> v >> d; d %= M;
		g[u].push_back({v, d});
		g[v].push_back({u, d});
	}
	decompose(0);
	cout << ans;

	return 0;	
}