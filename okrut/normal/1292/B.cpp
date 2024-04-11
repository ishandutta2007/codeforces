#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf = 2e16;

ll ax, ay, bx, by, xZero, yZero;

int goRight (ll x, ll y, ll lmt)
{
	debug ("Going right (%lld %lld) %lld\n", x, y, lmt);
	
	int ret;
	for (ret=0; lmt>=0; ret++)
	{
		debug ("Got from %lld %lld (%lld)\n", x, y, lmt);
		/* Jezeli jestem tutaj to mam ++ za x*/
		ll x1 = x*ax + bx, y1 = y*ay+by;
		ll dist = x1 - x + y1 - y;
		lmt-=dist;
		
		x = x1;
		y = y1;
	}
	return ret;
}

int goLeft (ll x, ll y, ll lmt)
{
	int ret;
	for (ret=0; lmt>=0 and x!=xZero; ret++)
	{
		ll x1 = (x-bx)/ax, y1 = (y-by)/ay;
		
		ll dist = x - x1 + y - y1;
		lmt -=dist;
		
		x = x1;
		y = y1;
	}
	
	if (x==xZero and lmt>=0) ret++;
	
	return ret;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	ll xs, ys, t;
	scanf ("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &xZero, &yZero, &ax, &ay, &bx, &by, &xs, &ys, &t);
	
	int res = 0;
	
	ll x= xZero, y = yZero;
	
	rep(i,0,60)
	{
		ll dist = abs(xs - x) + abs(ys - y);
		
		int r = goRight(x, y, t - dist);
		int l = goLeft(x, y, t - dist);
		
		debug ("To %lld %lld: %d %d\n",x, y, r, l);
		
		res = max(res, r);
		res = max(res, l);
		
		x = ax*x + bx;
		y = ay*y + by;
		
		if (x>inf or y>inf) break;
	}
	
	printf ("%d\n", res);
	
}