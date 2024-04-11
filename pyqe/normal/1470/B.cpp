#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e6,pc[1000069],a[300069],fq[1000069];
bitset<1000069> cpt;

int main()
{
	long long tt,rrr,t,rr,i,j,k,sm,z;
	
	for(i=1;i<=ma;i++)
	{
		pc[i]=i;
	}
	for(i=2;i<=ma;i++)
	{
		if(!cpt[i])
		{
			for(j=i*2;j<=ma;j+=i)
			{
				cpt[j]=1;
				for(;pc[j]%(i*i)==0;pc[j]/=i*i);
			}
		}
	}
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			a[i]=pc[a[i]];
			fq[a[i]]++;
			z=max(z,fq[a[i]]);
		}
		sm=0;
		for(i=1;i<=n;i++)
		{
			sm+=fq[a[i]]*(fq[a[i]]%2==0||a[i]==1);
			fq[a[i]]=0;
		}
		scanf("%lld",&t);
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld",&k);
			printf("%lld\n",max(z,sm*!!k));
		}
	}
}