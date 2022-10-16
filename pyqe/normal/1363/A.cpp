#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[2];

int main()
{
	long long t,rr,i,ii,k,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k%2]++;
		}
		w=min(fq[1],d);
		for(i=1;i<=w;i+=2)
		{
			if(d<=i+fq[0])
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}