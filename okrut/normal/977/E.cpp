#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
vector <vector <int> > graf;
vector <bool> vst;
vector <int> czas;
bool cykl;
int e, v, dl;
int n, m;
void dfs (int a, int b=-1, int t=0)
{
	vst[a]=false;
	e+=graf[a].size();
	czas[a]=t;
	v++;
	rep(i,0,(int)graf[a].size()) if (graf[a][i]!=b)
	{
		if (vst[graf[a][i]]) dfs(graf[a][i], a, t+1);
		else 
		{
			cykl=true;
			dl=t-czas[graf[a][i]];
			if (dl<0) dl*=-1;
		}
	}
}
int main ()
{
	int a, b;
	scanf ("%d %d", &n, &m);
	graf.resize(n+1);
	vst.resize(n+1, true);
	czas.resize(n+1);
	rep(i,0,m)
	{
		scanf ("%d %d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int res=0;
	rep(i,1,n+1) if (vst[i])
	{
		e=0;
		v=0;
		cykl=false;
		dfs(i);
		debug ("%d: %d %d %d %d\n", i, e, v, dl, (int)cykl);
		if (cykl) if (e==v*2) if (v>2) if (dl==v-1) res++;
	}
	printf ("%d\n", res);
	return 0;
}