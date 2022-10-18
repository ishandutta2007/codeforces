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
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);
using namespace std;
int n;
int x[1100]; int y[1100]; int r[1100];

bool ok(int xx,int yy)
{
	for (int i=1;i<=n;i++)
		if ( (xx - x[i])*(xx - x[i]) + (yy - y[i])*(yy - y[i]) <= r[i]*r[i] ) return true;
	return false;
};

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int xa,ya,xb,yb;
   scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
   if ( xa > xb ) swap(xa,xb);
   if ( ya > yb ) swap(ya,yb);
   scanf("%d",&n);
   for (int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&r[i]);
   
   int res = 0;
   for (int i=xa; i<=xb; i++)
	   if (!ok(i,ya)) res++;
   for (int i=ya+1; i<yb; i++)
       if (!ok(xa,i)) res++;
   for (int i=xa; i<=xb; i++)
	   if (!ok(i,yb)) res++;
   for (int i=ya+1; i<yb; i++)
       if (!ok(xb,i)) res++;
   cout << res;
   return 0;
}