#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<2> fq;

int main()
{
	long long t,rr,i,k;
	bool bad;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		bad=0;
		fq.reset();
		for(i=1;i<=n+1;i++)
		{
			if(i<=n)
			{
				scanf(" %c",&ch);
				k=(ch=='B')-(ch=='W');
			}
			else
			{
				k=-1;
			}
			if(k!=-1)
			{
				fq[k]=1;
			}
			else
			{
				bad|=fq[0]+fq[1]==1;
				fq.reset();
			}
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}