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

const int N = 1e5+100;
const int LOG = 20;
const ll mod  = 1e9+7;
pair <int, ll> up[N][LOG];
vector <int> graf[N];
ll B[N];
void dfs (int a, int b)
{
	up[a][0] = mp(b, __gcd(B[a],B[b]));
	
	for (int s: graf[a]) if (s!=b) dfs(s,a);
}
int main ()
{
	int n;
	scanf ("%d", &n);
	ll res = 0;
	B[0] = 0;
	rep(i,1,n+1) 
	{
		scanf ("%lld", &B[i]);
		res+=B[i];
	}
	res%=mod;
	
	rep(i,1,n)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	debug ("wczytano\n");
	dfs(1,0);
	
	int x = 0;
	bool f = true;
	while(f)
	{
		f = false;
		rep(a,1,n+1) 
		{
			up[a][x+1] = mp(up[up[a][x].fi][x].fi, __gcd(up[up[a][x].fi][x].se, up[a][x].se));
			if (up[a][x+1].fi!=0) f = true;
		}
		x++;
		debug ("poziom %d\n", x);
	}
	rep(a,1,n+1)
	{
		int v = a;
		ll g=0;
		debug ("\nidz z %d\n", a);
		while (v!=1 && v!=0)
		{
			g = __gcd(up[v][0].se, g);
			x = 0;
			ll d = 1;
			debug ("line 72 %d %lld\n", up[v][x+1].fi, up[v][x+1].se);
			while (up[v][x+1].fi>0 && ((g>0 && up[v][x+1].se%g==0) || (g==0 && up[v][x+1].se==0)))
			{
				x++;
				d*=2LL;
			}
			debug ("here\n");
			res+= d * g;
			v = up[v][x].fi;
			debug ("do %d (%lld) z %lld\n", v, d, g);
		}
		res%=mod;
	}
	printf ("%lld\n", res);
}