#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
vector <pair <int, int> > pkt;
int main ()
{
	int n;
	scanf ("%d", &n);
	int x, y;
	int maksx=-1e9, minx=1e9, miny=1e9, maksy=-1e9;
	int max_xpy=-1e9, min_xpy=1e9, max_xmy=-1e9, max_ymx=-1e9;
	rep(i,0,n)
	{
		scanf ("%d %d", &x, &y);
		maksx=max(maksx, x);
		minx=min(minx, x);
		maksy=max(maksy, y);
		miny=min(miny, y);
		min_xpy=min(min_xpy, x+y);
		max_xpy=max(max_xpy, x+y);
		max_xmy=max(max_xmy, x-y);
		max_ymx=max(max_ymx, y-x);
	}
	int best=0;
	best=max(best, max_xpy-minx-miny);
	best=max(best, maksx+maksy-min_xpy);
	best=max(best, max_xmy-minx+maksy);
	best=max(best, max_ymx-miny+maksx);
	printf ("%d ", best*2);
	rep(i,3,n) printf ("%d ", (maksx-minx +maksy-miny)*2);
	printf ("\n");
}