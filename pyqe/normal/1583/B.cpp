#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<100069> vtd;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&k);
			vtd[k]=1;
			scanf("%lld",&k);
		}
		for(i=1;vtd[i];i++);
		k=i;
		for(i=1;i<=n;i++)
		{
			if(i!=k)
			{
				printf("%lld %lld\n",k,i);
			}
		}
	}
}