#include <bits/stdc++.h>

using namespace std;

long long n,pr[200069],fq[200069];

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			pr[i]=i;
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			pr[fd(k)]=fd(i);
		}
		for(i=1;i<=n;i++)
		{
			fq[fd(i)]++;
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",fq[fd(i)]," \n"[i==n]);
		}
	}
}