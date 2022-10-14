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

const int N = 5e5+10;
vector <int> graf[N];
int vst[N], Taken[N], Depth[N];
void dfs (int a, vector <int> &tab)
{
	debug ("dfs %d (%d)\n",a, Depth[a]);
	tab.pb(a);
	vst[a]++;
	for (int s: graf[a]) if (vst[s]==0) 
	{
		Depth[s] = Depth[a]+1;
		dfs(s, tab);
	}
}

void solve (int a, int b)
{
	vector <int> V;
	for (int s: graf[a]) if (Depth[s]>Depth[b])
	{
		if (Depth[s]== Depth[a]+1)
		{
			solve(s, a);
			if (Taken[s]==0) V.pb(s);
		}
		else V.pb(s);
	}
	
	debug ("solve for %d: ", a);
	for (int v: V) debug ("%d ", v);
	debug ("\n");
	
	if ((int)V.size() % 2 ==1 && a!=b) 
	{
		Taken[a] = 1;
		V.pb(b);
	}
	
	rep(i,0,(int)V.size()/2) printf ("%d %d %d\n", V[i*2], a, V[i*2+1]);
}
int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	int w = 0;
	rep(i,1,n+1) if (vst[i]==0)
	{
		vector <int> tab;
		dfs(i, tab);
		int s = 0;
		for (int v: tab) s+=(int)graf[v].size();
		w += s/4;
	}
	
	printf ("%d\n", w);
	
	rep(i,1,n+1) if (Depth[i]==0)
	{
		solve(i,i);
	}
}