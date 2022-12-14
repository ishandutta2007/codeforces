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

const int MAX_N = 1e5 + 5;

int used[MAX_N], c[MAX_N], a[MAX_N];
vi g[MAX_N];
int cnt = 0;

void dfs(int v) {
 	used[v] = 1;
 	cnt++;
 	for (int u : g[v])
 		if (!used[u])
 			dfs(u);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	forn (i, k)
		scanf("%d", &c[i]), c[i]--;
	forn (i, m) {
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	g[v].pb(u), g[u].pb(v);
	}
	int sum = 0;
	forn (i, k) {
	 	cnt = 0;
	 	dfs(c[i]);
	 	a[i] = cnt;
	 	sum += cnt;
	}
	sort(a, a + k);
	ll ans = 0;
	forn (i, k) {
	 	int r = a[i];
	 	if (i == k - 1)
	 		r += n - sum;
	 	ans += r * 1ll * (r - 1) / 2;
	}
	printf(I64 "\n", ans - m);
	return 0;
}