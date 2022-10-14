#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/ld(2.0)
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF=1e9;
namespace flow
{
	vector <int> dist;
	vector <bool> used;
	//flow table
	const int N=500;
	ll can[N][N], thru[N][N];
	vector <vector <int> > graf;
	int n;
	int z, u;
	ll dfs (int a, ll f=1e18)
	{
		if (a==u) return f;
		if (f==0LL) return 0LL;
		ll ret;
		for (int s: graf[a]) if (dist[s]==dist[a]+1)
		{
			ret=dfs(s, min(f, can[a][s]-thru[a][s]));
			if (ret>0)
			{
				thru[a][s]+=ret;
				thru[s][a]-=ret;
				return ret;
			}
		}
		return 0LL;
	}
	ll main (vector <pair <pair <int, int>, ll > > &e, int Z, int U)
	{
		graf.clear();
		dist.clear();
		used.clear();
		z=Z;
		u=U;
		n=max(u,z)+1;
		memset(can, 0, sizeof can);
		memset(thru, 0, sizeof thru);
		rep(i,0,(int)e.size()) 
		{
			n=max(n, max(e[i].fi.fi, e[i].fi.se)+1);
			can[e[i].fi.fi][e[i].fi.se]+=e[i].se;
			//can[e[i].fi.se][e[i].fi.fi]=e[i].se;
		}
		graf.resize(n);
		for (pair <pair <int, int>, int> p: e)
		{
			graf[p.fi.fi].pb(p.fi.se);
			graf[p.fi.se].pb(p.fi.fi);
		}
		dist.reserve(n);
		used.reserve(n);
		bool flag=true;
		ll ret=0;
		while (flag)
		{
			dist.clear();
			dist.resize(n, INF);
			used.clear();
			used.resize(n, false);
			queue <int> kol;
			dist[z]=0;
			used[u]=false;
			kol.push(z);
			while (!kol.empty())
			{
				int x=kol.front();
				kol.pop();
				if (used[x]) continue;
				used[x]=true;
				rep(i,0,n) if (can[x][i]>thru[x][i]) if (dist[i]>dist[x]+1)
				{
					dist[i]=dist[x]+1;
					kol.push(i);
				}
			}
			if (dist[u]==INF) flag=false;
			ll x=dfs(z);
			while (x>0)
			{
				ret+=x;
				x=dfs(z);
			}
		}
		return ret;
	}
}
int n, m, z, u;
vector <pair <pair <int, int>, ll> > edge;
int x;
bool check (ld w) //each bear bears w
{
	vector <pair <pair <int, int>, ll> > e=edge;
	for (pair <pair <int, int>, ll> &p: e)
	{
		p.se=(ld(p.se)/w);
	}
	ll f=flow::main(e, 1,n);
	return f>=(ll)x;
}
ld eps=1e-15;
ld binsuche (ld lewy, ld prawy)
{
	debug ("binsuche %Lf %Lf\n", lewy, prawy);
	while (prawy-lewy>eps)
	{
		if (check(mitte)) lewy=mitte;
		else prawy=mitte;
	}
	return mitte*(ld)x;
}
int main ()
{
	scanf ("%d %d %d", &n, &m, &x);
	if (x<1000) eps=1e-12;
	if (x<10) eps=1e-10;
	
	edge.resize(m);
	rep(i,0,m) scanf ("%d %d %lld", &edge[i].fi.fi, &edge[i].fi.se, &edge[i].se);
	printf ("%.8lf\n", (double)binsuche(eps, 1e6));
}