#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+5;
const int L = 19;
int Lca[L][N], Depth[N], Dist, Deepest[N];
vector <int> graf[N];

int up (int a, int u)
{
	rep(i,0,L) if (u &(1<<i)) a = Lca[i][a];
	return a;
}

int lca (int a, int b)
{
	if (Depth[a] > Depth[b]) swap(a,b);
	b = up(b, Depth[b] - Depth[a]);
	
	if (a==b) return a;
	
	for (int i=L-1; i>=0; i--) if (Lca[i][a]!=Lca[i][b])
	{
		a = Lca[i][a];
		b = Lca[i][b];
	}
	return Lca[0][a];
}

bool dist (int a, int b, int c, int &d)
{
	if (a==c) return true;
	
	d++;
	for (int s: graf[a]) if (s!=b) if (dist(s, a, c, d)) return true;
	d--;
	return false;
}

void dfs0 (int a, int b)
{
	Depth[a] = 0;
	for (int s: graf[a]) if (s!=b) 
	{
		dfs0(s, a);
		Depth[a] = max(Depth[a], Depth[s]+1);
	}
}

int pivot (int a, int b, int c)
{
	vector <int> best(3,0);
	best[2] = c+1;
	
	for (int s: graf[a]) if (s!=b)
	{
		best[0] = max(best[0], Depth[s]+1);
		sort(best.begin(), best.end());
	}
	
	if (best[0]>=Dist) return a;
	
	for (int s: graf[a]) if (s!=b)
	{
		int ret;
		if (best[2]!=Depth[s]+1) ret = pivot(s, a, best[2]);
		else ret = pivot(s, a, best[1]);
		
		if (ret>0) return ret;
	}
	
	
	return -1;
}

void dfs (int a, int b)
{
	Lca[0][a] = b;
	Deepest[a] = a;
	
	for (int s: graf[a]) if (s!=b) 
	{
		Depth[s] = Depth[a]+1;
		dfs(s, a);
		
		if (Depth[Deepest[s]] > Depth[Deepest[a]]) Deepest[a] = Deepest[s];
	}
}



int main ()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n, a, b;
		scanf ("%d %d %d", &n, &a, &b);
		
		
		rep(i,1,n+1) graf[i].clear();
		rep(i,1,n)
		{
			int x, y;
			scanf ("%d %d", &x, &y);
			graf[x].pb(y);
			graf[y].pb(x);
		}
		
		Dist = 0;
		dist(a, 0, b, Dist);
		
		
		debug ("\n\nTest, dist= %d\n\n", Dist);
		
		dfs0(1, 0);
		
		int p = pivot(1,0,-1);
		
		debug ("Found pivot %d\n", p);
		
		if (p==-1)
		{
			printf ("NO\n");
			continue;
		}
		
		
		Depth[p] = 0;
		dfs(p,0);
		
		rep(i,1,n+1) debug ("%d (%d): %d, %d\n", i, Depth[i], Deepest[i], Lca[0][i]);
		
		rep(i,0,L-1) rep(v,1,n+1)
		{
			Lca[i+1][v] = Lca[i][Lca[i][v]];
		}
		
		set <pair <int, int> > vstd;
		while (up(a, Dist)!=b and up(b,Dist)!=a)
		{
			debug ("Processing %d (%d) %d (%d)\n", a,Deepest[a], b, Deepest[b]);
			
			if (vstd.count({a,b})==1) break;
			vstd.insert({a,b});
			
			if (Deepest[a]==a) swap(a,b);
			
			//move a to Deepest[a]
			a = Deepest[a];
			int c = lca(a, b);
			
			int d1 = Depth[a] - Depth[c];
			int d2 = Dist - d1;
			int d3 = Depth[b] - Depth[c] - d2;
			
			debug ("%d %d %d %d\n", c, d1, d2, d3);
			
			if (d2<=0) b = up(a, Dist);
			else
			{
				b = up(b, d3);
			}
		}
		
		if (up(a, Dist)==b or up(b,Dist)==a) printf ("YES\n");
		else printf ("NO\n");
	}
}