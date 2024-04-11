//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#define pb push_back
#define i64 long long
#define REP(i,a,b) for (int (i)=(a);(i)<(b);i++)
#define forn(i,b) for (int (i)=0;i<(b);i++)
const double eps = 1e-9;
const i64 inf = 2000000000;
const double pi = acos(-1.0);
using namespace std;
i64 n,m;

i64 gox(i64 x,i64 dx)
{
	if (dx == 0) return inf;
	if (dx > 0)
	{
		if (x + dx > n) return 0;
		return (n-x)/dx;
	}
	if (x - dx < 1) return 0;
	return ( (1 - x)/dx );
}

i64 goy(i64 y,i64 dy)
{
	if (dy == 0) return inf;
	if (dy > 0)
	{
		if (y + dy > m) return 0;
		return (m-y)/dy;
	}
	if (y - dy < 1) return 0;
	return ( (1 - y)/dy );
}

int main() {
 //  freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   i64 x,y;
   cin >> n >> m >> x >> y;
   int k; cin >> k;
   i64 dx[k]; i64 dy[k];
   i64 res = 0;
   forn(i,k)
   {
		scanf("%I64d%I64d",&dx[i],&dy[i]);
		i64 maxx = gox(x,dx[i]);
		i64 maxy = goy(y,dy[i]);
		i64 steps = min(maxx,maxy);
		//cout << x << " " << y << " " << steps << endl;
		res += steps;
		x += dx[i]*steps; y += dy[i]*steps;
   }
   
   cout << res << endl;
   return 0;
}