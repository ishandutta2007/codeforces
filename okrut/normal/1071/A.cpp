#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug //
using namespace std;
int a, b;
set <int> wor;
int main ()
{
	//ios_base::sync_with_stdio(false);
	scanf ("%d %d", &a, &b);
	int n=0; int m=0;
	int x=1;
	while (a>=x)
	{
		a-=x;
		x++;
		n++;
	}
	int y;
	if (n>0) y=(a/n); //o ile przesuwam wszystko
	else y=0;
	if (n>0) a%=n;
	vector <int> tab, tabb;
	rep(i,1,x) tab.pb(i+y);
	for (int i=n-1; i>=0; i--) if (a>0)
	{
		tab[i]++;
		a--;
	}
	rep(i,0,(int)tab.size()) wor.insert(tab[i]);
	x=1;
	while (x<=b)
	{
		if (wor.count(x)==0) 
		{
			m++;
			b-=x;
			tabb.pb(x);
		}
		x++;
	}
	printf ("%d\n", n);
	for (auto w: wor) printf ("%d ", w);
	printf ("\n%d\n", m);
	rep(i,0,m) printf ("%d ", tabb[i]);
	printf ("\n");
}