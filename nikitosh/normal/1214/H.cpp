#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 2e5 + 5;

int h[MAX_N], ans[MAX_N], depth[MAX_N], pr[MAX_N];
vi g[MAX_N];
bool flag = 1;
int k;

void dfs(int v, int p, int d) {
	pr[v] = p;
	h[v] = 0;
	depth[v] = d;
	for (int u : g[v])
		if (u != p) {
			dfs(u, v, d + 1);
			h[v] = max(h[v], h[u] + 1);
		}
}

void calc(int v, int p, int up) {
	multiset<int> s;
	for (int u : g[v])
		if (u != p)
			s.insert(h[u] + 1);
	if (up != -1)
		s.insert(up);
	if (sz(s) >= 3 && k != 2) {
		auto it = s.rbegin();
		it++;
		int res = *it;
		it++;
		if (*it + res >= k - 1)
			flag = 0;
	}
	for (int u : g[v]) {
		if (u == p)
			continue;
		s.erase(s.find(h[u] + 1));
		int newUp = 1;
		if (sz(s))
			newUp = max(newUp, *s.rbegin() + 1);
		calc(u, v, newUp);
		s.insert(h[u] + 1);
	}
}

void color(int v, int p, int dlt) {
	for (int u : g[v])
		if (u != p) {
			ans[u] = ans[v] + dlt;
			if (ans[u] == k)
				ans[u] = 0;
			if (ans[u] == -1)
				ans[u] = k - 1;
			color(u, v, dlt);
		}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d%d", &n, &k);
	forn (i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--, u--;
		g[v].pb(u), g[u].pb(v);
	}	
	dfs(0, -1, 0);
	calc(0, -1, -1);
	if (!flag) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	int maxx = -1, ind = -1;
	forn (i, n)
		if (depth[i] > maxx)
			maxx = depth[i], ind = i;
	dfs(ind, -1, 0);
	maxx = -1;
	int ind2 = -1;
	forn (i, n)
		if (depth[i] > maxx)
			maxx = depth[i], ind2 = i;
	int v = ind2;
	vi diam;
	int cnt = 0;
	while (v != -1) {
		diam.pb(v);
		ans[v] = cnt++;
		if (cnt == k)
			cnt = 0;
		v = pr[v];
	}
	int len = sz(diam);
	v = (len - 1) / 2;
	color(diam[v], diam[v + 1], -1);
	color(diam[v + 1], diam[v], 1);
	forn (i, n)
		printf("%d ", ans[i] + 1);
	return 0;
}