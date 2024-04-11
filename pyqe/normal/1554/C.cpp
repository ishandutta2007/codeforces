#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		m++;
		z=0;
		for(i=29;i+1;i--)
		{
			k=n>>i&1;
			l=m>>i&1;
			if(k&&!l)
			{
				break;
			}
			if(!k&&l)
			{
				z|=1ll<<i;
			}
		}
		printf("%lld\n",z);
	}
}