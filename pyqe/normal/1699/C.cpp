#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,pst[100069];

int main()
{
	long long t,rr,i,k,mn,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			pst[k]=i;
		}
		z=1;
		mn=pst[0];
		mx=pst[0];
		for(i=1;i<n;i++)
		{
			if(pst[i]>=mn&&pst[i]<=mx)
			{
				z=z*(mx-mn+1-i)%dv;
			}
			mn=min(mn,pst[i]);
			mx=max(mx,pst[i]);
		}
		printf("%lld\n",z);
	}
}