#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std; 
typedef long long ll;
typedef long double ld;


int main ()
{
	int q;
	scanf ("%d", &q);
	rep(t,0,q)
	{
		int n;
		scanf ("%d", &n);
		vector <vector <int> > tab;
		set <int> wor;
		tab.resize(n+1);
		vector <int> ciag(n);
		int a;
		rep(i,0,n)
		{
			scanf ("%d", &a);
			tab[a].pb(i);
			ciag[i] = a;
		}
		int cost = 0;
		rep(i,1,n+1) 
		{
			reverse(tab[i].begin(), tab[i].end());
			if ((int)tab[i].size()>0) cost++;
		}
		int tyl = n+1, nt = n+1, res = cost;
		for (int x = n; x>0; x--) if ((int)tab[x].size()>0)
		{
			cost--;
			wor.insert(tab[x][0]);
			auto it = wor.find(tab[x][0]);
			while (it!=wor.begin())
			{
				it--;
				nt = min(nt,ciag[*it]);
			}
			rep(i,nt,tyl) if ((int)tab[i].size()>0)
			{
				cost++;
				for (int y: tab[i]) wor.erase(y);
			}
			tyl = nt;
			
			for (int y: tab[x]) wor.insert(y);
			res = min(res, cost);
		}
		printf ("%d\n", res);
	}
}