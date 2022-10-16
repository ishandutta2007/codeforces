#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,a[3],k,df;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a,a+3);
		k=a[1]-a[0];
		a[2]-=a[1]-a[0];
		a[1]=a[0];
		df=a[2]-a[0];
		if(a[0]<df)
		{
			k+=min(a[0]*2,a[2]);
		}
		else
		{
			k+=df*2;
			a[0]-=df;
			a[1]-=df;
			a[2]-=df*2;
			k+=a[0]*3/2;
		}
		printf("%lld\n",k);
	}
}