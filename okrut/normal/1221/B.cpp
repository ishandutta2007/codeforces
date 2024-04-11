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
	int n;
	scanf ("%d", &n);
	rep(i,0,n)
	{
		rep(j,0,n) 
		{
			if ((i+j)%2==0) printf ("B");
			else printf ("W");
		}
		printf ("\n");
	}
}