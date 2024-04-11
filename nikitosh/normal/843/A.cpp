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

int a[MAX_N], used[MAX_N];
pii b[MAX_N];
vi g[MAX_N], path;
vector<vi> ans;

void dfs(int v) {
    used[v] = 1;
    path.pb(v);
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
	forn (i, n)
		scanf("%d", &a[i]), b[i] = mp(a[i], i);
	sort(b, b + n);
	forn (i, n)
		g[i].pb(b[i].sc);
	forn (i, n)
		if (!used[i]) {
			dfs(i);
			ans.pb(path);
			path.clear();
		}
	printf("%d\n", sz(ans));
	for (auto &path : ans) {
		printf("%d ", sz(path));
	 	for (int v : path)
	 		printf("%d ", v + 1);
	 	puts("");
	}
	return 0;
}