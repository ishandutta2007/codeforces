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

const int MAXN = 3e5 + 5;

int pl[MAXN];
vi g[MAXN];
set <int> indices, s[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	forn (i, m)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--, u--;
		g[v].pb(u), g[u].pb(v);
	}	
	if (sz(g[0]) >= n - k)
	{
		puts("impossible");
		return 0;
	}
	pl[n - 1] = 0;
	s[0].insert(n - 1);
	indices.insert(0);
	int cur = 1;
	fornr (i, n - 1)
	{
		//printf("i = %d\n", i);
		for (int u : g[i])
			if (u > i)
			{
				s[pl[u]].erase(u);
 			}	
 		vi v;
		for (auto ind : indices)
			if (sz(s[ind]) > 0)
			{
				//printf("foudn ind = %d\n", ind);
				v.pb(ind);
			}
		for (int u : g[i])
			if (u > i)
			{
				s[pl[u]].insert(u);
 			}	
		if (i == 0 && sz(indices) > k)
		{
			puts("impossible");
			return 0;
		}
		if (sz(v) == 0)
		{
			s[cur].insert(i);
			pl[i] = cur;
			indices.insert(cur++);
			//printf("sz = %d\n", sz(indices));
			continue;	
		}
 		int maxx = 0, x = 0;
		for (auto ind : v)
		{
			indices.erase(ind);
			if (sz(s[ind]) > maxx)
			{
				maxx = sz(s[ind]);
				x = ind;
			}
		}
		//printf("sz indices = %d\n", sz(indices));
		for (auto ind : v)
		{
			if (ind != x)
			{
				for (auto l : s[ind])
				{
					pl[l] = x;
					s[x].insert(l);
				}
				s[ind].clear();
			}
		}
		s[x].insert(i);
		pl[i] = x;
		indices.insert(x);
        /*	puts("");
		printf("i = %d\n", i);
		printf("%d\n", sz(v));
		for (auto ind : indices)
		{
			//printf("ind = %d\n", ind);
		    for (auto l : s[ind])
		    	printf("%d ", l);
			puts("");
		}
			puts("");  */
	}
	if (sz(indices) != 1)
	{
		puts("impossible");
		return 0;
	}
	puts("possible");
	return 0;
}