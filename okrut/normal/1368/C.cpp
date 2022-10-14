#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

void draw(int x, int y)
{
	printf ("%d %d\n%d %d\n", x-1, y, x-2, y);
	printf ("%d %d\n%d %d\n", x, y-1, x, y-2);
	printf ("%d %d\n", x-2, y-2);
	printf ("%d %d\n%d %d\n", x-1, y-2, x-2, y-1);
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	
	
	int x = 0, y = 0;
	
	printf ("%d\n", n*7+8);
	
	printf ("%d %d\n", x, y);
	draw(x,y);
	
	rep(i,0,n)
	{
		x-=2;
		y-=2;
		draw(x,y);
	}
	
}