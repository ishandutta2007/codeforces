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

const int N = 5e5+100;
vector <vector <pair <int, ll> > > graf;
ll dp[N][2]; //ile wolnch kolorows
int n, k;

void calc (int a, int b)
{
	dp[a][0] = dp[a][1] = 0;
	vector <ll> tab; //zyski z kolorowania krawedzi
	for (auto p: graf[a]) if (p.fi!=b) 
	{
		calc(p.fi,a);
		dp[a][0]+=dp[p.fi][0];
		dp[a][1]+=dp[p.fi][0];
		tab.pb(dp[p.fi][1] - dp[p.fi][0] + p.se);
	}
	sort(tab.begin(), tab.end(), [] (ll a, ll b) {return a>b;});
	rep(i,0,min(k, (int)tab.size())) if (tab[i]>0LL) dp[a][0]+=tab[i];
	rep(i,0,min(k-1, (int)tab.size())) if (tab[i]>0LL) dp[a][1]+=tab[i];
	
	debug ("calc (%d %d) = %lld %lld\n", a, b, dp[a][0], dp[a][1]);
}
int main ()
{
	int q;
	scanf ("%d", &q);
	rep(t,0,q)
	{
		scanf ("%d %d", &n, &k);
		graf.clear();
		graf.resize(n+1);
		rep(i,1,n)
		{
			int a, b;
			ll c;
			scanf ("%d %d %lld", &a, &b, &c);
			graf[a].pb(mp(b,c));
			graf[b].pb(mp(a,c));
		}
		calc(1,1);
		printf ("%lld\n", dp[1][0]);
	}
}