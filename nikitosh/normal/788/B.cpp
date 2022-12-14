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
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 1e6 + 5;

vi g[MAX_N];
int used[MAX_N];
int deg[MAX_N];

void dfs(int v) {
 	used[v] = 1;
 	for (int u : g[v])
 		if (!used[u])
 			dfs(u);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m;
	scanf("%d%d", &n, &m);
	int cnt = 0;
	forn (i, m) {
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	deg[v]++, deg[u]++;
	 	if (v != u)
		 	g[u].pb(v), g[v].pb(u);
		else
			cnt++;
	}
	forn (i, n)
		if (deg[i] > 0) {
			dfs(i);
			break;	
		}
	forn (i, n)
		if (!used[i] && deg[i] > 0) {
		 	puts("0");
		 	return 0;
		}
	ll ans = 0;
	forn (i, n)
		ans += sz(g[i]) * 1ll * (sz(g[i]) - 1) / 2;
	ans += cnt * 1ll * (cnt - 1) / 2;
	ans += cnt * 1ll * (m - cnt);
	printf(I64 "\n", ans);
	return 0;
}