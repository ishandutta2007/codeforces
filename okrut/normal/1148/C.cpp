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

map <int, int> pos; //pozycje
vector <int> tab;
vector <pair <int, int> > res;
int n;
void swaps (int a, int b)
{
	debug ("swap %d %d ?\n", a,b);
	assert(n<=abs(a-b) *2);
	int va = tab[a];
	int vb = tab[b];
	
	
	pos[va] = b;
	pos[vb] = a;
	swap(tab[a], tab[b]);
	
	res.pb(mp(a+1, b+1));
}
int main ()
{
	scanf ("%d", &n);
	tab.resize(n);
	rep(i,0,n)
	{
		scanf ("%d", &tab[i]);
		pos[tab[i]] = i;
	}
	rep(i,0,n/2) //sortujemy polowe
	{
		int p = pos[i+1];
		debug ("%d is at %d\n", i+1, p);
		if (p==i) continue; //jest ok
		
		if (p*2>=n) 
		{
			//przez 1. wpisz mnie na koniec
			if (i>0 && p<n-1)
			{
				debug ("piszemy na okolo\n");
				swaps(0, n-1);
				swaps(p, 0);
				swaps(0, n-1);
				swaps(i, n-1);
			}
			else 
			{
				debug ("po prostu\n");
				swaps(i, p);
			}
		}
		else
		{
			swaps(p, n-1);
			swaps(n-1, i);
		}
	}
	rep(i,n/2,n)
	{
		int p = pos[i+1];
		debug ("%d is at %d\n", i+1, p);
		if (p==i) continue;
		
		swaps(i,0);
		swaps(p, 0);
		swaps(i, 0);
	}
	printf ("%d\n", (int)res.size());
	for (pair <int, int> p: res) printf ("%d %d\n", p.fi, p.se);
	
}