#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,l,mxd,mx1;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		mxd=-1e18;
		mx1=-1e18;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&k,&l);
			mxd=max(mxd,k-l);
			mx1=max(mx1,k);
		}
		if(d<=mx1)
		{
			printf("1\n");
			continue;
		}
		if(mxd<=0)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",(d-mx1-1+mxd)/mxd+1);
	}
}