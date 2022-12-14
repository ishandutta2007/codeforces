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

const int MAXN = 1e5 + 5;

int a[MAXN];
vi g[MAXN];
LL deep[MAXN], ans[MAXN], path[MAXN], deepAndPath[MAXN];
LL globalAns = 0;

void dfs(int v, int p)
{
    LL max1 = 0, max2 = 0, max3 = 0;
    int ind1 = -1, ind2 = -1, ind3 = -1;
    LL maxAns1 = 0, maxAns2 = 0;
    int indAns1 = -1, indAns2 = -1;
	for (int u : g[v])
		if (u != p)
		{
			dfs(u, v);
			ans[v] = max(ans[v], ans[u]);
			if (deep[u] > max3)
				max3 = deep[u], ind3 = u;
			if (max3 > max2)
				swap(max2, max3), swap(ind2, ind3);
	    	if (max2 > max1)
				swap(max1, max2), swap(ind1, ind2);
	    	deepAndPath[v] = max(deepAndPath[u] + a[v], deepAndPath[v]);
			if (ans[u] > maxAns2)
				maxAns2 = ans[u], indAns2 = u;
			if (maxAns2 > maxAns1)
				swap(maxAns1, maxAns2), swap(indAns1, indAns2);
		}
	deep[v] = max1 + a[v];
	path[v] = max1 + max2 + a[v];
	ans[v] = max(ans[v], path[v]);
	globalAns = max(globalAns, maxAns1 + maxAns2);
	for (int u : g[v])
		if (u != p)
		{
		 	LL k = ans[u] + a[v];
		 	if (u != ind1)
		 		k += max1;
		 	else
		 		k += max2;
		 	deepAndPath[v] = max(deepAndPath[v], k);
		}
	globalAns = max(globalAns, deepAndPath[v]);
	globalAns = max(globalAns, ans[v]);
	for (int u : g[v])
		if (u != p)
		{
			LL k = ans[u] + a[v];
			if (ind3 != -1)
			{
				if (ind1 != u && ind2 != u)
					k += max1 + max2;
				else
				{
					if (ind1 != u && ind3 != u)
						k += max1 + max3;
				    else
				    	k += max2 + max3;
				}
				globalAns = max(globalAns, k);
			}
			if (ind2 != -1)
			{
				k = deepAndPath[u] + a[v];
				if (ind1 != u)
					k += max1;
				else
					k += max2;
			}
			globalAns = max(globalAns, k);
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
	forn (i, n)
		scanf("%d", &a[i]);
	forn (i, n - 1)	
	{
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	g[v].pb(u), g[u].pb(v);
	}
	dfs(0, -1);
	printf(I64 "\n", globalAns);
	return 0;
}