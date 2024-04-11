#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long long n,m,i,j,k,x,y,countp=0,counts=0,minn,maxx, found,a[100001];

int main()
{
	cin>>n>>x>>y;
	for(i=1;i<=n;i++)cin>>a[i];
	for (i=1;i<=n;i++) {found=1;minn=(((i-x)<1)?1:i-x); maxx= (((i+y)>n)?n:i+y);for (j=minn;j<=maxx;j++) if ((a[i]>=a[j])and(i!=j)) found=0; if (found) break;} cout<<i;
}