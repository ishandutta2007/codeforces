#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

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

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAXN = 2e5 + 5;

int from[MAXN];
vector <pii> g[MAXN];
vi ans[MAXN];

void dfs(int v, int p)
{
	int k = 1;
	for (auto np : g[v])
	{
	    int u = np.fs;
	    int ind = np.sc;
		if (u != p)
		{
			if (k == from[v])
				k++;
			from[u] = k;
			ans[k].pb(ind + 1);
			k++;
			dfs(u, v);
		}	
	}
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d", &n);	
	forn (i, n - 1)
	{
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	g[v].pb(mp(u, i)), g[u].pb(mp(v, i));
	}
	dfs(0, -1);
	int maxx = 0;
	forn (i, n)
		maxx = max(maxx, sz(g[i]));
	printf("%d\n", maxx);
	forab (i, 1, maxx + 1)
	{
		printf("%d ", sz(ans[i]));
		for (auto l : ans[i])
			printf("%d ", l);
		puts("");
	}
	return 0;
}