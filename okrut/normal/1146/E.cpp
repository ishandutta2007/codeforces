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
const int T = 1<<17;	

pair <int, int> tree[T + T];

void mark (pair <int, int> &p, pair <int, int> x)
{
	assert(p.fi * p.se ==0);
	assert(x.fi * x.se ==0);
	if (x.fi!=0)
	{
		p = mp(x.fi, 0);
	}
	if (x.se!=0)
	{
		if (p.fi==0) p.se^=1;
		else p.fi^=1;
	}
}
void update (int left, int right, pair <int,int> x, int a=1, int lewy=T, int prawy=2*T-1)
{
	if (a==1) 
	{
		left+=T;
		right+=T;
	}
	if (lewy<prawy)
	{
		mark (tree[a*2], tree[a]);
		mark (tree[a*2+1], tree[a]);
		tree[a] = mp(0,0);
	}
	
	if (left<=lewy && right>=prawy) 
	{
		mark(tree[a], x);
		if (x.fi==0 && x.se==1) debug ("marked %d %d: %d %d\n", lewy, prawy, tree[a].fi, tree[a].se);
	}
	else if (lewy<prawy)
	{
		if (left<=mitte) update (left, right, x, a*2, lewy, mitte);
		if (right>mitte) update (left, right, x, a*2+1, mitte+1, prawy);
	}	
}
int policz (int a)
{
	a+=T;
	int ret = tree[a].fi ^ tree[a].se;
	//debug ("policz %d: %d, ", a-T, ret);
	while (a>1)
	{
		a/=2;
		
		if (tree[a].fi==0) ret ^= tree[a].se;
		else ret = tree[a].fi;
		
		//if (tree[a]!=mp(0,0)) debug ("%d (%d %d), ", ret,tree[a].fi, tree[a].se);
	}
	//debug ("\n");
	return ret;
}
vector <int> ciag;
int n, q;
char c;
void wypisz ()
{
	debug ("moj ciag: \n");
	int a, b;
	rep(i,0,n)
		{
			b  = ciag[i];
			a = policz(abs(ciag[i]));
			
			if ((a&2)==2) b = abs(b);
			if ((a&1)==1) b*=-1;
			debug ("dla %d (%d) -> %d\n", ciag[i], a, b);
			printf ("%d ", b);
		}	
		printf ("\n");
}
int main ()
{
		scanf ("%d %d", &n, &q);
		ciag.resize(n);
		rep(i,0,n) scanf ("%d", &ciag[i]);
		int a;
		rep(i,0,q)
		{
			scanf (" %c %d", &c, &a);
			debug ("operate %c %d\n", c, a);
			if (a>=0 && c=='<')
			{
				update (0, a-1, mp(0,1));
				update (a, T-1, mp(2,0));
			}
			if (a>=0 && c=='>')
			{
				update(a+1, T-1, mp(3, 0));
			}
			if (a<0 && c=='<')
			{
				update (-a+1, T-1, mp(2,0));
			}
			if (a<0 && c=='>')
			{
				update (0, -a-1, mp(0,1));
				update (-a, T-1, mp(3,0));
			}
			
			//wypisz();
			
		}
		
		 wypisz();
		
}