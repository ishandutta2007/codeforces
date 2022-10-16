#include <bits/stdc++.h>

using namespace std;

long long n,fq[10000069],ps[10000069];
bitset<10000069> vtd;

int main()
{
	long long t,rr,i,j,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=2;i<=10000000;i++)
	{
		ps[i]=ps[i-1];
		if(!vtd[i])
		{
			for(j=i;j<=10000000;j+=i)
			{
				vtd[j]=1;
				ps[i]+=fq[j];
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",ps[min(l,10000000ll)]-ps[min(k-1,10000000ll)]);
	}
}