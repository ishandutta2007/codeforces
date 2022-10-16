#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069];

int main()
{
	long long t,rr,i,k,p;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			sq[i]=i;
		}
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(sq[i]==k)
			{
				p=min(i,n-1);
				bad|=p<1;
				swap(sq[p],sq[p+1]);
			}
		}
		if(bad)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}