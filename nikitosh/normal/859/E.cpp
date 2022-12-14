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
const int MOD = 1e9 + 7;

vi g[MAX_N];
int used[MAX_N];
vi comp;

int mul(int a, int b) {
 	return (a * 1ll * b) % MOD;
}

void dfs(int v) {
 	used[v] = 1;
 	comp.pb(v);
 	for (int u : g[v])
 		if (!used[u])
 			dfs(u);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n) {
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	g[v].pb(u), g[u].pb(v);
	}
	n *= 2;
	int ans = 1;
	forn (i, n) {
	 	if (!used[i]) {
	 	 	comp.clear();
	 	 	dfs(i);
	 	 	int size = 0;
	 	 	bool loop = 0;
	 	 	for (int v : comp) {
	 	 		for (int u : g[v]) {
	 	 			if (u == v)
	 	 				loop = 1;
				}
				size += sz(g[v]);
			}
			size /= 2;
			if (size > sz(comp)) {
				ans = 0;
			}
			if (size == sz(comp)) {
				if (!loop)
					ans = mul(ans, 2);
			}
			if (size == sz(comp) - 1) {
			 	ans = mul(ans, sz(comp));
			}
	 	}
	}
	printf("%d\n", ans);
	return 0;
}