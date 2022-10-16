#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[200069],fq[1000069];

int main()
{
	long long t,rr,i,z,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		mn=1e18;
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			z+=!fq[a[i]];
			fq[a[i]]++;
			if(i>d)
			{
				fq[a[i-d]]--;
				z-=!fq[a[i-d]];
			}
			if(i>=d)
			{
				mn=min(mn,z);
			}
		}
		for(i=1;i<=n;i++)
		{
			fq[a[i]]=0;
		}
		printf("%lld\n",mn);
	}
}