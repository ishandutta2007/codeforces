#include <bits/stdc++.h>

using namespace std;

long long n,m,pst[100069];

int main()
{
	long long t,rr,i,k,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			pst[k]=i;
		}
		z=0;
		mx=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			z++;
			if(pst[k]>mx)
			{
				z+=(pst[k]-1-i)*2;
			}
			mx=max(mx,pst[k]);
		}
		printf("%lld\n",z);
	}
}