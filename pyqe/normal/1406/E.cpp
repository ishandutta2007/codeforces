#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,sqn=98,as[10069];
bitset<100069> vtd;

int main()
{
	long long i,j,k,c,w,z=1;
	bool bad=0;
	
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		if(!vtd[i])
		{
			for(k=i;k<=n;k*=i)
			{
				nn++;
				as[nn]=k;
			}
			for(j=i;j<=n;j+=i)
			{
				vtd[j]=1;
			}
		}
	}
	sort(as+1,as+nn+1,greater<long long>());
	vtd.reset();
	c=n;
	for(i=1;i<=nn;i++)
	{
		printf("B %lld\n",as[i]);
		fflush(stdout);
		scanf("%lld",&k);
		w=0;
		for(j=as[i];j<=n;j+=as[i])
		{
			w+=!vtd[j];
			vtd[j]=1;
		}
		c-=w;
		if(bad&&k!=w)
		{
			z=z/__gcd(z,as[i])*as[i];
		}
		if(!bad&&(i%sqn==0||i==nn))
		{
			printf("A 1\n");
			fflush(stdout);
			scanf("%lld",&k);
			if(k!=c)
			{
				bad=1;
				i=(i-1)/sqn*sqn;
			}
		}
	}
	printf("C %lld\n",z);
	fflush(stdout);
}