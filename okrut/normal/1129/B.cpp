#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;

int main ()
{
	int k;
	scanf ("%d", &k);
	if (k==0)
	{
		printf ("1\n1\n");
		return 0;
	}
	int n=2000;
	int y=k+n;
	
	printf ("%d\n", n);
	int mil=1e6;
	printf ("-1 ");
	rep(i,1,n) 
	{
		printf ("%d ", min(y, mil));
		y-=min(y, mil);
	}
	printf ("\n");
}