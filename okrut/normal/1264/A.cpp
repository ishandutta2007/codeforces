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
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		vector <int> input(n), tab;
		for (int &x: input) scanf ("%d", &x);
		pair <int, int> cur = mp(-1,0);
		for (int x: input)
		{
			if (x==cur.fi) cur.se++;
			else
			{
				if (cur.se>0) tab.pb(cur.se);
				cur.fi = x;
				cur.se = 1;
			}
		}
		tab.pb(cur.se);
		
		int g, s, b;
		g = s= b = 0;
		
		g = tab[0];
		rep(i,1,(int)tab.size())
		{
			if (2*(s+b+g+tab[i]) > n) break;
			if (s>g) b+=tab[i];
			else s+=tab[i];
		}
		if (s <= g || b<= g ) printf ("0 0 0\n");
		else printf ("%d %d %d\n", g, s, b);
	}
}