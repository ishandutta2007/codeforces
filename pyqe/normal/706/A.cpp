#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,y,x,k,l,w,ly,lx;
	double mn=1e18;
	
	scanf("%lld%lld%lld",&y,&x,&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ly=abs(y-k);
		lx=abs(x-l);
		mn=min(mn,sqrt(ly*ly+lx*lx)/w);
	}
	printf("%.20lf\n",mn);
}