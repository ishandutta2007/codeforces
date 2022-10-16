#include <bits/stdc++.h>

using namespace std;

long long n,d,nn,a[400069],ps[400069],m=1;
map<long long,long long> fq;

int main()
{
	long long i,j,k,mn=1e18;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(!fq[k])
		{
			nn++;
			a[nn]=k;
		}
		fq[k]++;
	}
	sort(a+1,a+nn+1);
	k=d*8/n;
	for(i=0;i<k;i++)
	{
		m*=2;
		if(m>=nn)
		{
			printf("0\n");
			return 0;
		}
	}
	for(i=1;i<=nn;i++)
	{
		ps[i]=ps[i-1]+fq[a[i]];
	}
	for(i=m;i<=nn;i++)
	{
		mn=min(mn,ps[nn]-ps[i]+ps[i-m]);
	}
	printf("%lld\n",mn);
}