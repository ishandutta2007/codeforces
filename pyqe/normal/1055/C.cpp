#include <bits/stdc++.h>

using namespace std;

long long lh[2],rh[2],d[2];

int main()
{
	long long it,gd,df,mn;
	
	for(it=0;it<2;it++)
	{
		scanf("%lld%lld%lld",lh+it,rh+it,d+it);
	}
	if(lh[0]>lh[1])
	{
		swap(lh[0],lh[1]);
		swap(rh[0],rh[1]);
		swap(d[0],d[1]);
	}
	gd=__gcd(d[0],d[1]);
	df=lh[1]-lh[0];
	mn=df/gd;
	printf("%lld\n",max((long long)0,max(min(rh[0]+mn*gd,rh[1])-max(lh[0]+mn*gd,lh[1])+1,min(rh[0]+(mn+1)*gd,rh[1])-max(lh[0]+(mn+1)*gd,lh[1])+1)));
}