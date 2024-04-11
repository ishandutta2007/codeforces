#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+10;

int Point[N], Seg[N], T[N];
pair <int, int> Pos[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int r, n;
	scanf ("%d %d", &r, &n);
	
	Pos[0].fi = Pos[0].se = 1;
	rep(i,1,n+1) scanf ("%d %d %d", &T[i], &Pos[i].fi, &Pos[i].se);
	
	T[0] = 0;
	
	rep(i,0,n+1) 
	{
		Seg[i] = Point[i] = -N;
	}
	
	Point[0] = -1;
	
	rep(i,0,n+1)
	{
		Seg[i+1] = max(Seg[i], Seg[i+1]);
		
		Point[i] = max(Point[i], Seg[i]);
		
		Point[i]++;
		
		rep(j,i+1,n+1)
		{
			int t = T[j] - T[i];
			if (t>=2*(r-1))
			{
				Seg[j] = max(Seg[j], Point[i]);
				break;
			}
			
			int d  = abs(Pos[i].fi - Pos[j].fi) + abs(Pos[i].se - Pos[j].se);
			
			if (d <= t) Point[j] = max(Point[j], Point[i]);
		}
	}
	
	int res = 0;
	rep(i,1,n+1) res = max(res, Point[i]);
	printf ("%d\n", res);
}