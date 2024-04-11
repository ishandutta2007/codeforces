#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],fq[100069],fq2[100069];

int main()
{
	long long t,rr,i,c,mx,mx2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			fq[i]=0;
			fq2[i]=0;
		}
		c=0;
		mx=0;
		mx2=0;
		for(i=1;i<=n;i++)
		{
			c+=i==1||a[i]==a[i-1];
			fq[a[i]]+=(i==1||a[i]==a[i-1])+(i==n||a[i]==a[i+1]);
			mx=max(mx,fq[a[i]]);
			fq2[a[i]]++;
			mx2=max(mx2,fq2[a[i]]);
		}
		if(mx2>(n+1)/2)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",c-1+max(mx-c-1,0ll));
	}
}