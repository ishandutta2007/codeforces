#include <bits/stdc++.h>

using namespace std;

long long n,m,a[6];

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<6;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<6;i++)
		{
			a[i]=min(a[i],a[(i+5)%6]+a[(i+1)%6]);
		}
		if(n>=0)
		{
			if(m>=0)
			{
				z=a[5]*(n-min(n,m))+a[1]*(m-min(n,m))+a[0]*min(n,m);
			}
			else
			{
				m*=-1;
				z=a[5]*n+a[4]*m;
			}
		}
		else
		{
			n*=-1;
			if(m>=0)
			{
				z=a[2]*n+a[1]*m;
			}
			else
			{
				m*=-1;
				z=a[2]*(n-min(n,m))+a[4]*(m-min(n,m))+a[3]*min(n,m);
			}
		}
		printf("%lld\n",z);
	}
}