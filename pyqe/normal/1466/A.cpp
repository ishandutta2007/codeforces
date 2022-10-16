#include <bits/stdc++.h>

using namespace std;

long long n,ma=50,a[69];
bitset<69> vtd;

int main()
{
	long long t,rr,i,j,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		vtd.reset();
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			for(j=1;j<i;j++)
			{
				z+=!vtd[a[i]-a[j]];
				vtd[a[i]-a[j]]=1;
			}
		}
		printf("%lld\n",z);
	}
}