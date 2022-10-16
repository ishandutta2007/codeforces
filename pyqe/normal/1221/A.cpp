#include <bits/stdc++.h>

using namespace std;

long long n,fq[30];

int main()
{
	long long t,rr,i,c,ls,k;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<30;i++)
		{
			fq[i]=0;
		}
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			for(c=0;k>1;k/=2,c++);
			fq[c]++;
		}
		ls=0;
		bad=1;
		for(i=0;i<30;i++)
		{
			fq[i]+=ls;
			if(i==11&&fq[i])
			{
				bad=0;
			}
			ls=fq[i]/2;
			fq[i]%=2;
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}