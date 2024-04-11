#include <bits/stdc++.h>

using namespace std;

long long n,m,pr[100069];

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
	long long i,c=0,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		pr[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(fd(k)==fd(l))
		{
			c++;
		}
		else
		{
			pr[fd(l)]=fd(k);
		}
	}
	printf("%lld\n",c);
}