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

bool blad;
const int N = 1e5+20;
ll sum[N];
vector <int> graf[N];
int n;

ll res;

ll dfs1 (int a, ll suma);

ll dfs0 (int a, ll suma) //suma mojego ojca
{
	ll mini = 1e9;
	
	for (int s: graf[a])
	{
		mini = min(mini, sum[s]);
	}
	if (mini< suma) blad = true;
	
	if ((int)graf[a].size()==0) mini = suma;
	
	
	sum[a] = mini;
	res+= mini - suma;
	
	debug ("%d: (%lld - %lld)  - %lld\n", a, mini, suma, res);
	
	for (int s: graf[a])
	{
		dfs1(s, mini);
	}
	
	return mini; //moja suma
}
ll dfs1 (int a, ll suma)
{
	if (suma > sum[a]) blad = true;
	res+=sum[a] - suma; //o tyle wzroslo
	debug ("%d: (%lld - %lld) - %lld\n", a, sum[a], suma, res);
	for (int s: graf[a]) 
	{
		dfs0 (s, sum[a]);
	}
	return sum[a];
}
int main ()
{
	blad = false;
	res=0;
	scanf("%d", &n);
	int a;
	rep(i,2,n+1)
	{
		scanf ("%d", &a);
		graf[a].pb(i); //jestes synem
	}
	rep(i,1,n+1) 
	{
		scanf ("%lld", &sum[i]);
		debug ("%d: %lld\n", i, sum[i]);
	}
	
	dfs1(1,0);
	
	if (blad) printf ("-1\n");
	else printf ("%lld\n", res);
}