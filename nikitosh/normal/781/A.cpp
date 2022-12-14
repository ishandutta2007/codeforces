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

const int MAX_N = 2e5 + 5;

vi g[MAX_N];
int ans[MAX_N];

void dfs(int v, int pr, int color) {
 	ans[v] = color;
 	int cur = 0;	
 	for (int u : g[v])
 		if (ans[u] == -1) {
 			while (cur == ans[v] || (pr != -1 && cur == ans[pr]))
 				cur++;
 			dfs(u, v, cur++);
 		}	
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n - 1) {
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	g[v].pb(u), g[u].pb(v);
	}
	fill(ans, ans + n, -1);
	int maxDeg = 0;
	forn (i, n)
		maxDeg = max(maxDeg, sz(g[i]));
	printf("%d\n", maxDeg + 1);
	dfs(0, -1, 0);
	forn (i, n)
		printf("%d ", ans[i] + 1);
	return 0;
}