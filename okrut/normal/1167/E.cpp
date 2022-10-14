#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

vector <pair <int, int> > tab;
int n;
ll x;
int main ()
{
	scanf ("%d %lld", &n, &x);
	tab.resize(n);
	rep(i,0,n)
	{
		scanf ("%d", &tab[i].fi);
		tab[i].se=i;
	}
	sort(tab.begin(), tab.end());
	ll res=0LL;
	//idziemy od tylu
	ll ok=1; //pierwszy do usuniecia
	int r=n-1;
	
	rep(i,0,n) debug ("%d ", tab[i].se);
	debug ("\n");
	
	while (r>0) 
	{
		if (tab[r-1].se>tab[r].se) 
		{
			ok = tab[r-1].fi;
			break;
		}
		r--;
	}
	
	int l=-1;
	bool f = false;
	
	rep(i,1,x+1)
	{
		
		ok = max(ok, ll(i));
		debug ("zagranie %d - mozna od %lld \n",i, ok); 
		res += x - ok + 1;
		while (l < n - 1 && tab[l+1].fi==i)
		{
			if (l>=0) if (tab[l].se>tab[l+1].se) f = true;
			l++;
		}
		
		if (l>=0) while (r < n && tab[r].se <= tab[l].se) 
		{
			ok = tab[r].fi;
			r++;
		}
		
		if (f) break;
	}
	
	printf ("%lld\n", res);
	
}