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
vector <pair <int, int> > pot;
vector <bool> taken;
vector <pair <int, int> > e;
int n, m;
int must;
void wait ()
{
	int h;
	scanf ("%d", &h);
	h--;
	taken[h]=true;
	rep(i,0,m) 
	{
		if (h==e[i].fi) must=e[i].se;
		else if (h==e[i].se) must=e[i].fi;
	}
}
void play ()
{
	int h=-1;
	if (must!=-1) if (!taken[must]) 
	{
		debug ("musze\n");
		h=must;
	}
	must=-1;
	
	if (h==-1)
	{
		rep(i,0,m) 
		{
			if (!taken[e[i].fi]) 
			{
				debug ("z krawedzi\n");
				h=e[i].fi;
				break;
			}
		}
	}
	if (h==-1)
	{
		rep(i,0,n*2) if (!taken[pot[i].se]) 
		{
			h=pot[i].se;
			break;
		}
	}
	taken[h]=true;
	printf ("%d\n", h+1);
	fflush(stdout);
}
int main ()
{
		scanf ("%d %d", &n, &m);
		e.resize(m);
		pot.resize(n*2);
		int a, b;
		taken.resize(n*2,false);
		rep(i,0,n*2) 
		{
			scanf ("%d", &pot[i].fi);
			pot[i].se=i;
		}
		e.resize(m);
		rep(i,0,m) 
		{
			scanf ("%d %d", &e[i].fi, &e[i].se);
			e[i].fi--;
			e[i].se--;
			if (pot[e[i].fi].fi<pot[e[i].se].fi) swap(e[i].fi, e[i].se);
		}
		sort(pot.begin(), pot.end());
		reverse(pot.begin(), pot.end());
		int t;
		must=-1;
		scanf ("%d", &t);
		rep(i,0,n)
		{
			if (t==1)
			{
				play();
				wait();
			}
			else
			{
				wait();
				play();
			}
		}
}