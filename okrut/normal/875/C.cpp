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

namespace sat {
	vector <vector <int> > graf, revgraf, list, grafsss;
	vector <int> rob, sss, tru, sto; 
	vector <bool> vst;
	int n, m;
	void dfs0 (int a) {
		vst[a]=false;
		for (int v: graf[a]) if (vst[v]) dfs0 (v);
		rob.pb(a);
	}
	void dfs1 (int a, int b) {
		sss[a]=b;
		list[b].pb(a);
		for (int v: revgraf[a]) if (sss[v]==-1) dfs1(v, b);
	}
	bool flag;
	void dfs2 (int a, int b=-1) {
		sto[a]--;
		for (int v: list[a]) if (tru[v/2]!=-1) {
			if (b==-1) b = tru[v/2]^(1&v);
			else if (b!=tru[v/2]^(1&v)) flag = false;
		}
		if (b==-1) b=0;
		for (int v: list[a]) tru[v/2]=b^(1&v);
		for (int v: grafsss[a]) {
			if ((--sto[v])==0) dfs2 (v, b==0 ? -1 : 1);
		}
	}
	bool main (vector <pair <int, int> > &alt) {
		n=0;
		for (pair <int, int> p: alt) n=max(n, max(p.fi, p.se));
		n=n/2+1;
		m=n*2;
		tru.resize(n, -1);
		graf.resize(m);
		revgraf.resize(m);
		for (pair <int, int> v: alt) {
			graf[v.fi^1].pb(v.se);
			graf[v.se^1].pb(v.fi);
			revgraf[v.se].pb(v.fi^1);
			revgraf[v.fi].pb(v.se^1);
		}
		vst.resize(m, true);
		sss.resize(m, -1);
		rep(i,0,m) if (vst[i]) dfs0 (i);
		int a=0;
		for (int i=m-1; i>=0; i--) if (sss[rob[i]]==-1) {
			list.pb(sto);
			dfs1 (rob[i],a++);
		}
		grafsss.resize(a);
		sto.resize(a,0);
		rep(i,0,m) for (int v: graf[i]) if (sss[i]!=sss[v]) {
			 grafsss[sss[i]].pb(sss[v]);
			 sto[sss[v]]++;
		}
		flag=true;
		rep(i,0,n) if (sss[i*2]==sss[i*2+1]) return false;
		rep(i,0,a) if (sto[i]==0) dfs2(i);
		return flag;
	}
}

const int N = 1e5;
vector <int> tab[N];

int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	rep(i,0,n)
	{
		int l;
		scanf ("%d", &l);
		tab[i].resize(l);
		for (int &x: tab[i]) scanf ("%d", &x);
	}
	
	vector <pair <int, int> > alt;
	alt.pb(mp(0,0));
	rep(p,1,n)
	{
		int l = 0;
		int len = min((int)tab[p-1].size(), (int)tab[p].size());
		while (l <len && tab[p-1][l]==tab[p][l]) l++;
		if (l==len)
		{
			if (len==(int)tab[p-1].size()) continue;
			else
			{
				printf ("No\n");
				return 0;
			}
		}
		
		if (tab[p-1][l] < tab[p][l])
		{
			debug ("if %d, then %d\n", tab[p][l], tab[p-1][l]);
			alt.pb(mp(2*tab[p][l]+1, 2*tab[p-1][l]));
		}
		else
		{
			debug ("nie %d, tak %d\n", tab[p-1][l], tab[p][l]);
			alt.pb(mp(1, 2*tab[p-1][l]));
			alt.pb(mp(2*tab[p][l]+1, 1)); 
		}
	}
	
	if (sat::main(alt))
	{
		printf ("Yes\n");
		vector <int> res;
		rep(i,1,m+1) if (sat::tru[i]==1) res.pb(i);
		printf ("%d\n", (int)res.size());
		for (int x: res) printf ("%d ", x);
		if (!res.empty()) printf ("\n");
	}
	else printf ("No\n");
}