#include <bits/stdc++.h>
#define wied(i,a,b) for (int i=a;  i<b; i++)
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define debug printf
using namespace std;
int main ()
{
	int n, s;
	scanf ("%d %d", &n, &s);
	int x=-s-1, y, a, b;
	wied(i,0,n)
	{
		scanf ("%d %d", &a, &b);
		y=a*60+b;
		if (y-x>=2*s+2)
		{
			x+=s+1;
			printf ("%d %d\n", x/60, x%60);
			return 0;
		}
		x=y;
	}
	x+=s+1;
	printf ("%d %d\n", x/60, x%60);
	return 0;
}