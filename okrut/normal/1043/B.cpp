#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
vector <int> tab, ciag, wyn;
int n;
bool check (int a)
{
	rep(i,0,n-a) if (ciag[i]!=ciag[i+a]) return false;
	return true;
}
int main ()
{
	scanf ("%d", &n);
	tab.resize(n);
	ciag.resize(n);
	rep(i,0,n)
	{
		scanf ("%d", &tab[i]);
		if (i>0) ciag[i]=tab[i]-tab[i-1];
		else ciag[i]=tab[i];
	}
	rep(i,1,n+1) if (check(i)) wyn.pb(i);
	printf ("%d\n", wyn.size());
	rep(i,0,(int)wyn.size()) printf ("%d ", wyn[i]);
	printf ("\n");
}