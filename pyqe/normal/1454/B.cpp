#include <bits/stdc++.h>

using namespace std;

long long n,pst[200069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			pst[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(!pst[k])
			{
				pst[k]=i;
			}
			else
			{
				pst[k]=-1;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(pst[i]>0)
			{
				i=pst[i];
				break;
			}
		}
		if(i>n)
		{
			i=-1;
		}
		printf("%lld\n",i);
	}
}