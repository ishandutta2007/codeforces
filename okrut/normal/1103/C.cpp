#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define debug //
using namespace std;
const int N = 250000;
vector <int> graf[N];
vector <bool> node;
int n, m, k;
int depth[N], vat[N];
int dfs (int a)
{
	debug ("%d: %d %d\n", a, vat[a], depth[a]);
	int ret = depth[a];
	for (int s: graf[a]) if (depth[s]==0)
	{
		node[a] = true;
		depth[s] = depth[a]+1;
		vat[s]=a;
		ret = max(ret, dfs(s));
	}
	return ret;
}
bool druk (int a, int b, int c)
{
	if (depth[c]>depth[b]) swap(b, c);
	int len = depth[b] - depth[c];
	if (a!=b) len++;
	if (a!=c) len++;
	if (len%3==0) return false;
	printf ("%d\n%d ", len, a);
	if (a==b) b=vat[b];
	while (b!=c)
	{
		printf ("%d ", b);
		b = vat[b];
	}
	printf ("%d\n", b);
	return true;
}
int main ()
{
	scanf ("%d %d %d", &n, &m, &k);
	int a, b;
	rep(i,0,m)
	{
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	node.resize(n+1, false);
	depth[1]=1;
	
	if (dfs(1)>=n/k)
	{
		a=0;
		rep(i,1,n+1) if (depth[i]>depth[a]) a=i;
		printf ("PATH\n%d\n", depth[a]);
		while (a!=0)
		{
			printf ("%d ", a);
			a = vat[a];
		}
		printf ("\n");
		return 0;
	}
	vector <int> tab;
	printf ("CYCLES\n");
	rep(i,1,n+1) if (!node[i])
	{
		if (--k < 0) break;
		tab.clear();
		for (int x: graf[i]) if (depth[x]<depth[i]-1) 
		{
			tab.pb(x);
			if ((int)tab.size()==2) break;
		}
		
		if (!druk(i, i, tab[0])) if (!druk(i, i, tab[1])) if (!druk(i, tab[0], tab[1]))
		{
			printf ("we have a problem\n");
		}
	}
}