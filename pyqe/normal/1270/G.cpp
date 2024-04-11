#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],ls[1000069],sq[1000069],zs=0;

int main()
{
	long long t,rr,i,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ls[i]=0;
		}
		zs=0;
		for(p=1;!ls[p];p-=a[p])
		{
			zs++;
			sq[zs]=p;
			ls[p]=zs;
		}
		printf("%lld\n",zs-ls[p]+1);
		for(i=ls[p];i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}