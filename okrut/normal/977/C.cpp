#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
int n, k;
vector <int> tab;
int main ()
{
	scanf ("%d %d", &n, &k);
	tab.resize(n);
	rep(i,0,n) scanf ("%d", &tab[i]);
	sort(tab.begin(), tab.end());
	if (k==0)
	{
		if (tab[0]>1) printf ("%d\n", tab[0]-1);
		else printf ("-1\n");
		return 0;
	}
	if (k==n)
	{
		printf ("%d\n", tab[n-1]);
		return 0;
	}
	if (tab[k-1]==tab[k]) printf ("-1\n");
	else printf ("%d\n", tab[k-1]);
	return 0;
}