#include <bits/stdc++.h>

using namespace std;

long long n[2],d[2];

int main()
{
	long long t,rr,ii,u,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",n,n+1,d,d+1);
		z=0;
		for(ii=0;ii<2;ii++)
		{
			u=ii*2-1;
			mn=min(n[0]*u,n[1]*u);
			if(mn>=0)
			{
				n[0]-=mn*u;
				n[1]-=mn*u;
				z+=mn*min(d[0]*2,d[1]);
			}
		}
		z+=(abs(n[0])+abs(n[1]))*d[0];
		printf("%lld\n",z);
	}
}