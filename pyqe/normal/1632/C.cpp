#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,j,mk,e,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		z=m-n;
		for(i=m;i<=m*4;i++)
		{
			mk=(n|i)-i;
			if(!mk)
			{
				z=(min(z,i-m+1));
			}
			else
			{
				for(j=0;j<22;j++)
				{
					if(mk>>j&1)
					{
						e=j;
					}
				}
				for(j=e;!(i>>j&1)||(n>>j&1);j++);
				z=min(z,i-m+(1ll<<j)-n%(1ll<<j)+1);
			}
		}
		printf("%lld\n",z);
	}
}