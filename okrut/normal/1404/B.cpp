#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+1;
vector <int> graf[N];
int Depth[N];

int path (int a, int b, int to)
{
	if (a==to) return 0;
	
	for (int s: graf[a]) if (s!=b) 
	{
		int ret = path(s, a, to);
		if (ret>=0) return ret+1;
	}
	return -1;
}

void dfs (int a, int b)
{
	for (int s: graf[a]) if (s!=b)
	{
		Depth[s] = Depth[a]+1;
		dfs(s, a);
	}
}

int main ()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n, a, b, da, db;
		scanf ("%d %d %d %d %d", &n, &a, &b, &da, &db);
		
		rep(i,1,n+1) graf[i].clear();
		rep(i,1,n)
		{
			int x, y;
			scanf ("%d %d", &x, &y);
			graf[x].pb(y);
			graf[y].pb(x);
		}
		
		int ab = path(a, a, b);
		
		if (ab <= da or 2*da>=db)
		{
			printf ("Alice\n");
			continue;
		}
		Depth[1] = 0;
		dfs(1,1);
		int maks = 0, leaf;
		rep(i,2,n+1) if (maks < Depth[i]) 
		{
			maks = Depth[i];
			leaf = i;
		}
		
		Depth[leaf] = 0;
		dfs(leaf, leaf);
		
		int path = 0;
		rep(i,1,n+1) path = max(path, Depth[i]);
		
		if (path > da*2) printf ("Bob\n");
		else printf ("Alice\n");
	}
	
}