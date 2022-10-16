#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,j,k,mx;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		mx=0;
		bad=0;
		for(j=1,i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(mx<k)
			{
				sq[i]=k;
				vtd[k]=1;
			}
			else if(max(mx,j)>k)
			{
				bad=1;
			}
			else
			{
				sq[i]=j;
				vtd[j]=1;
			}
			for(;j<=n&&vtd[j];j++);
			mx=max(mx,sq[i]);
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