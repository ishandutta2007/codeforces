#include <bits/stdc++.h>               

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
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
typedef double dbl;

#define FNAME ""

const int MAX = 50, MAXN = 5e5 + 10;

int up[MAXN]; 
dbl dp[MAXN][MAX], old[MAX], old2[MAX];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int q;
	scanf("%d", &q);	
	int cur = 1;
	dp[0][0] = 1;	
	forn (qq, q)
	{
		int t, v;
	 	scanf("%d%d", &t, &v);
	 	v--;
	 	if (t == 1)
	 	{
	 		up[cur++] = v;
	 		int u = v, last = cur;
	 		dp[cur][0] = 1;
	 		//old[cur][0] = 1;
	 		forn (h, MAX)
	 			old[h] = 0;
	 		for (int h = 1; h < MAX; h++)
	 		{
	 			old2[0] = dp[u][0];
	 		    forab (j, 1, h + 1)
	 		    {
	 		        old2[j] = dp[u][j];
	 		    	dp[u][j] = 1 - (1 - dp[u][j]) / (2 - old[j - 1]) * (2 - dp[last][j - 1]);
	 			}
	 			forn (j, h + 1)
	 				old[j] = old2[j];
	 			if (u == 0)
	 				break;
	 			last = u;
	 			u = up[u];
	 		}
		}
		else
		{
			ld ans = 0;
		 	forab (i, 1, MAX)
		 		ans += dp[v][i];	
			printf("%.20f\n", (double) ans);
		}
	}
	cerr << clock() * 1. / CLOCKS_PER_SEC << endl;
	//while(1);
	return 0;
}