#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e6+10;
const int inf = 1e8;
int dp[N][3][5], tiles[N];
int best;
inline void check (int a, int b, int c, int w)
{
	dp[a][b][c] = max(dp[a][b][c], w);
	best = max(best, dp[a][b][c]);
}
int main ()
{
	rep(j,0,N)
	{
		rep(a,0,3) rep(b,0,5) dp[j][a][b] = (a==0 && b==0) ? 0 : -inf;
	}
	best = 0;
	int n, m;
	scanf ("%d %d", &n, &m);
	int a;
	rep(i,0,n)
	{
		scanf ("%d", &a);
		tiles[a]++;
	}
	
	rep(i,1,m+1)
	{
		rep(a,0,3) rep(b,a,5) if (dp[i-1][a][b]>=0)
		{
			int k = tiles[i];
			int p = min(a, k); //tyle sekwensow zamkne
			rep(z,0,min(4+1, k - p +1)) //tyle kart zostawie
			{
				check(i, min(2, b-a), z, dp[i-1][a][b] + p + (k -p - z) / 3);
			}
		}
		/*rep(a,0,3) rep(b,a,5) if (dp[i][a][b]>=0)
		{
			debug ("dp[%d][%d][%d]: %d\n", i, a, b, dp[i][a][b]);
		}
		debug ("\n");*/
	}
	printf ("%d\n", best);
}