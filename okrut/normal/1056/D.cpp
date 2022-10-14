#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define miitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
vector <int> tab;
vector <vector <int> > graf;
int n;
void dfs (int a)
{
	for(int s: graf[a])
	{
		dfs(s);
		tab[a]+=tab[s];
	}
	if ((int)graf[a].size()==0) tab[a]=1;
}
int main ()
{
	scanf ("%d", &n);
	graf.resize(n);
	tab.resize(n,0);
	int s;
	rep(i,1,n)
	{
		scanf ("%d", &s);
		graf[s-1].pb(i);
	}
	dfs(0);
	sort(tab.begin(), tab.end());
	int x=0;
	rep(i,0,n)
	{
		printf ("%d ", tab[i]);
	}
	printf ("\n");
}