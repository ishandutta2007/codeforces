#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],fq[2];

int main()
{
	long long i,ii,k;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]|=k<<ii;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]&&a[i]<3)
		{
			fq[a[i]-1]++;
		}
	}
	if(!fq[0])
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n",fq[1]/fq[0]+1);
	}
}