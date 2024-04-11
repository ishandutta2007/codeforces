#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1<<10;

int tab[N][10][2]; //for each row
int n;
int main ()
{
	scanf ("%d", &n);
	
	int odc=1;
	int x=0;
	while (odc < n)
	{
		vector <int> ask[2];
		rep(i,0,n) if (i & odc) ask[1].pb(i);
		else ask[0].pb(i);
		rep(l,0,2)
		{
			printf ("%d\n", (int)ask[l].size());
			for (int x: ask[l]) printf ("%d ", x+1);
			printf ("\n");
			fflush(stdout);
			
			rep(i,0,n) scanf ("%d", &tab[i][x][l]);
		}
		odc*=2;
		x++;
	}
	
	printf ("-1\n");
	rep(r,0,n)
	{
		int res = 1e9+5;
		rep(i,0,x)
		{
			if ((1<<i) & r) 
			{
				res = min(res, tab[r][i][0]);
			}
			else 
			{
				res = min(res, tab[r][i][1]);
			}
		}
		printf ("%d ", res);
	}
	
	printf ("\n");
}