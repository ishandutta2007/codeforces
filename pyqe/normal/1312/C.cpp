#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[54];

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<54;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			for(j=0;k;k/=d,j++)
			{
				fq[j]+=k%d;
			}
		}
		for(i=0;i<54;i++)
		{
			if(fq[i]>1)
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}