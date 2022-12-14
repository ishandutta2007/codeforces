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

vi g[MAX_N], path, ans[MAX_N];
int used[MAX_N], printed[MAX_N];
set<pii> was;

void dfs(int v) {
 	used[v] = 1;
 	path.pb(v);
 	for (int u : g[v])
 		if (!used[u])
 			dfs(u), path.pb(v);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	forn (i, m) {
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	g[v].pb(u), g[u].pb(v);
	 	was.insert(mp(v, u));
	 	was.insert(mp(u, v));
	}
	dfs(0);
	int curClone = 0;
	int bound = (2 * n + k - 1) / k;
	for (int l : path) {
		if (sz(ans[curClone]) >= bound)
			curClone++;
		ans[curClone].pb(l);
	}
	forn (i, k) {
	 	if (sz(ans[i]) == 0)
	 		ans[i].pb(0);
		printf("%d ", sz(ans[i]));
//	 	assert(sz(ans[i]) > 0);
//	 	assert(sz(ans[i]) <= bound);
//	 	forn (j, sz(ans[i]) - 1)
// 		assert(was.count(mp(ans[i][j], ans[i][j + 1])));
	 	for (int l : ans[i])
	 		printf("%d ", l + 1), printed[l] = 1;
	 	puts("");
	}
	forn (i, n)
		assert(printed[i]);
	return 0;
}