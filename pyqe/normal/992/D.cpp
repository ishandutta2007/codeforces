#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],ps[200069],ls[200069],inf=2e13;

int main()
{
	long long i,p,w,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
		ls[i]=ls[i-1];
		if(a[i-1]>1)
		{
			ls[i]=i-1;
		}
		w=a[i];
		for(p=i;1;p=ls[p])
		{
			z+=w>=(ps[i]-ps[p-1])*d&&w<=(ps[i]-ps[ls[p]])*d&&w%d==0;
			if(!ls[p]||w>inf/a[ls[p]])
			{
				break;
			}
			w*=a[ls[p]];
		}
	}
	printf("%lld\n",z);
}