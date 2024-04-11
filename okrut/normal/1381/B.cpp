#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e3+5;
int Dp[N][N][2], P[N+N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		rep(i,0,2*n) scanf ("%d", &P[i]);
		
		rep(i,0,n+1) rep(j,0,n+1) rep(k,0,2) Dp[i][j][k] = N+N;
		
		Dp[0][0][1] = Dp[0][0][0] = 0;
		
		
		rep(i,0,n+1) rep(j,0,n+1)
		{
			if (i+j==n*2)
			{
				if(Dp[i][j][0]<N+N or Dp[i][j][1]<N+N) printf ("YES\n");
				else printf ("NO\n");
				continue;
			}
			
			if (i<n)
			{
				Dp[i+1][j][0] = min( Dp[i+1][j][0], max(Dp[i][j][0], P[i+j]));
				
				if (P[i+j] > Dp[i][j][1])
				{
					Dp[i+1][j][0] = min(Dp[i+1][j][0], P[i+j]);
				}
			}
			if (j<n)
			{
				Dp[i][j+1][1] = min( Dp[i][j+1][1], max(Dp[i][j][1], P[i+j]));
				
				if (P[i+j] > Dp[i][j][0])
				{
					Dp[i][j+1][1] = min(Dp[i][j+1][1], P[i+j]);
				}
			}
		}
	}
	
}