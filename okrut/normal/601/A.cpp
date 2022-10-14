#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
int  n, m;
vector <vector <int> > graf;
vector <int> tab;
queue <pair <int, int> > kol;
int main ()
{
	cin>>n >>m;
	int a, b;
	bool flag=false; //pociag jedzie od razu
	graf.resize(n+1);
	rep(i,0,m)
	{
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
		if (min(a,b)==1) if (max(a,b)==n) flag=true;
	}
	if (flag) rep(i,1,n+1)
	{
		tab=graf[i];
		graf[i].clear();
		sort(tab.begin(), tab.end());
		a=0;
		rep(j,1,n+1) 
		{
			if ((a<tab.size()) && (tab[a]==j)) a++;
			else graf[i].pb(j);
		}
	}
	kol.push(mp(1,0));
	tab.clear();
	tab.resize(n+1, -1); //nie mozna dotrzec
	pair <int, int> p;
	while (!kol.empty())
	{
		p=kol.front();
		kol.pop();
		if (tab[p.fi]==-1)
		{
			tab[p.fi]=p.se;
			rep(i,0,(int)graf[p.fi].size()) kol.push(mp(graf[p.fi][i], p.se+1));
		}
	}
	printf ("%d\n", tab[n]);
}