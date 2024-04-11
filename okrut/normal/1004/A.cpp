#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
int n, m;
vector <long long> tab;
int main ()
{
	int a, b;
	long long d;
	cin>>n >>d;
	tab.resize(n);
	rep(i,0,n) cin>>tab[i];
	int wyn=2;
	rep(i,1,n)
	{
		if (tab[i]-tab[i-1]>=d*2) wyn++;
		if (tab[i]-tab[i-1]>d*2) wyn++;
	}
	printf ("%d\n", wyn);
	return 0;
}