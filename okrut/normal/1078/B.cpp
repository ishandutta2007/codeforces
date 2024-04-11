#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
typedef double ld;
vector <vector <ll> > dp[2];
vector <int> rob;
vector <pair <int, int> > tab;
int n, sum;
void tabtest (int l)
{
	debug ("nasz dp:\n");
	rep(i,0,n+1)
	{
		debug ("%d - elementami: ", i);
		rep(s,0,sum+1) debug ("%d ", (int)dp[l][i][s]);
		debug ("\n");
	}
}
int main ()
{
	//ios_base::sync_with_stdio(false);
	scanf ("%d", &n);
	rob.resize(n);
	rep(i,0,n) 
	{
		scanf ("%d", &rob[i]);
	}
	sort(rob.begin(), rob.end());
	int x=-1, y=0;
	sum=0;
	rep(i,0,n)
	{
		if (rob[i]!=x)
		{
			sum=max(sum, x*y);
			if (x!=-1) tab.pb(mp(x,y));
			x=rob[i];
			y=1;
		}
		else y++;
	}
	tab.pb(mp(x,y));
	
	sum=max(sum,(x*y));
	if ((int)tab.size()==1)
	{
		printf ("%d\n", n);
		return 0;
	}
	if ((int)tab.size()==2) //mamy tylko 2 rodzaje elementow
	{
		if (tab[0].fi*tab[0].se!=tab[1].fi*tab[1].se) 
		{
			printf ("%d\n", n);
			return 0;
		}
	}	
	// za pomoca k elementow sume s
	int l=0;
	rep(l,0,2)
	{
		dp[l].resize(n+1); //#elementow
		rep(i,0,n+1) dp[l][i].resize(sum+1, 0LL);
		dp[l][0][0]=1;
	}	
	
	for(pair <int, int> p: tab)
	{
		x=p.fi;
		rep(k,1,n+1) rep(s,1,sum+1) //tyle elementow taka suma
		{
			y=1;
			dp[1-l][k][s]=dp[l][k][s];
			while (y<=p.se && y<=k && y*x<=s)
			{
				dp[1-l][k][s]=max(dp[1-l][k][s], dp[l][k][s]+dp[l][k-y][s-x*y]);
				y++;
				if (dp[1-l][k][s]>1) break;
			}
		}
		l=1-l;
	}
	
	int res=0;
	rep(i,0,(int)tab.size())
	{
		x=tab[i].fi;
		rep(y,1,tab[i].se+1) 
		{
			if (dp[l][y][x*y]==1) res=max(res, y);
		}
	}
	printf ("%d\n", res);
}