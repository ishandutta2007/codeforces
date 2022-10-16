#include <bits/stdc++.h>

using namespace std;

long long n,m,pr[150069],cd[150069],fq[150069];

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
	long long i,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		pr[i]=i;
		cd[i]=1;
		fq[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(fd(k)!=fd(l))
		{
			cd[fd(k)]+=cd[fd(l)];
			fq[fd(k)]+=fq[fd(l)];
			pr[fd(l)]=fd(k);
		}
		fq[fd(k)]++;
	}
	for(i=1;i<=n;i++)
	{
		if(cd[fd(i)]*(cd[fd(i)]-1)/2!=fq[fd(i)])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}