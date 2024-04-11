#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
vector <vector <int> > tab;
vector <int> nast, pop;
int n,m;
int dfs (int a)
{
	if (nast[a]==-1) return 1;
	else return 1+dfs(nast[a]);
}
int main ()
{
	ios_base::sync_with_stdio(false);
	cin>>n >>m;
	tab.resize(m);
	nast.resize(n+1, -1); //brak nastepnika
	pop.resize(n+1,-1);
	int a, b;
	cin>>a;
	rep(i,1,n)
	{
		cin>>b;
		nast[a]=b;
		a=b;
	}
	rep(i,1,m)
	{
		debug ("check\n");
		cin>>a;
		rep(j,1,n)
		{
			cin>>b;
			if (nast[a]!=b) nast[a]=-1;
			a=b;
		}
		nast[a]=-1;
	}
	rep(i,1,n+1) if (nast[i]>0) pop[nast[i]]=i;
	long long wyn=n, x;
	rep(i,1,n+1) if (pop[i]==-1)
	{
		x=dfs(i);
		wyn+=((x-1)*x)/2;
	}
	cout<<wyn <<"\n";
}