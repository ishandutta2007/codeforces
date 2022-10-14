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

const int N = 400000 + 20;
vector <int> graf[N], revgraf[N], kol;
int id[N], moc[N], czas[N], st[N]; //numer scc

int n, m, h;
void dfs0 (int a)
{
	id[a]=-1;
	for (int s: graf[a]) if (id[s]==0) dfs0(s);
	kol.pb(a);
}
void dfs1 (int a, int b)
{
	debug ("mark %d %d\n", a, b);
	moc[b]++;
	id[a] = b;
	for (int s: revgraf[a]) if (id[s]==-1) dfs1 (s, b);
}
int main ()
{
	scanf ("%d %d %d", &n, &m, &h);
	rep(i,1,n+1) scanf ("%d", &czas[i]);
	int a, b;
	rep(i,0,m)
	{
		scanf ("%d %d", &a, &b);
		
		if ((czas[a]+1) % h == czas[b]) 
		{
			debug ("%d to %d\n", a, b);
			graf[a].pb(b);
			revgraf[b].pb(a);
		}
		if ((czas[b]+1) % h== czas[a])
		{
			debug ("%d to %d\n", b, a);
			graf[b].pb(a);
			revgraf[a].pb(b);
		}
	}
	memset(id, 0, sizeof id);
	memset(st, 0, sizeof st);
	memset(moc, 0, sizeof moc);
	
	rep(i,1,n+1) if (id[i]==0) dfs0(i);
	reverse(kol.begin(), kol.end());
	
	for (int v: kol) if (id[v]==-1) dfs1 (v, v);
	
	rep(v,1,n+1) for (int s: graf[v])
	{
		if (id[v]!=id[s]) st[id[v]]++;
	}
	
	int best = n, res=-1;
	rep(i,1,n+1) if (id[i]==i) if (st[i]==0) 
	{
		if (best>moc[i])
		{
			res = i;
			best = moc[i];
		}
	}
	
	printf ("%d\n", best);
	if (best==n)
	{
		rep(i,1,n+1) printf ("%d ", i);
		printf ("\n");
	}
	else
	{
		assert(best == moc[res]);
		rep(i,1,n+1) if (id[i]==res) printf ("%d ", i);
		printf ("\n");
	}
}