#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 12;
ll dp[2][1<<N], cost[1<<N]; //dla kazdej podmaski
int input[2000][12];
int n;
int main ()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		rep(i,0,2) rep(j,0,1<<n) dp[i][j] = 0;
		int m;
		scanf ("%d %d", &n, &m);
		rep(j,0,n) rep(i,0,m) scanf ("%d", &input[i][j]);
		vector <pair <int, int> > rob(m);
		rep(i,0,m) 
		{
			int b = 0;
			rep(j,0,n)  b = max(b, input[i][j]);
			rob[i] = mp(b, i);
		}
		sort(rob.begin(), rob.end());
		reverse(rob.begin(), rob.end());
		m = min(m, n);
		
		int k = 0;
		rep(i,0,m)
		{
			rep(i,0,1<<n) dp[k][i] = 0;
			rep(mask,0,1<<n)
			{
				cost[mask] = 0;
				rep(j,0,n)
				{
					ll d = 0;
					rep(l,0,n) if ((1<<l)&mask) d+=ll(input[rob[i].se][(l+j)%n]);
					cost[mask] = max(cost[mask], d);
				}
			}
			rep(mask,0,1<<n) for (int sub = mask; sub>=0; sub = (sub-1)&mask)
			{
				dp[k][mask] = max(dp[k][mask], dp[k^1][mask-sub]+cost[sub]);
				if (sub==0) break;
			}
			k^=1;
		}
		printf ("%lld\n", dp[k^1][(1<<n)-1]);
	}
}