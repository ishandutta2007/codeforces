#include <bits/stdc++.h>

using namespace std;

const long long ma=100;
long long n,a[169],fq[169];

int main()
{
	long long t,rr,i,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=ma;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			fq[a[i]]++;
		}
		for(p=1;fq[p]!=1;p++);
		for(i=1;a[i]!=p;i++);
		printf("%lld\n",i);
	}
}