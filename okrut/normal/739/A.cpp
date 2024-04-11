#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;


int main ()
{
	int n, m, a, b, maks=1e9;
	scanf ("%d %d", &n, &m);
	rep(i,0,m)
	{
		scanf ("%d %d", &a, &b);
		maks=min(maks, b-a);
	}
	maks++;
	printf ("%d\n", maks);
	rep(i,0,n) printf ("%d ", i%maks);
	printf ("\n");
}