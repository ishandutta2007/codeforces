#include <bits/stdc++.h>

using namespace std;

long long n,d,d2;

int main()
{
	long long t,rr,i,k,w;
	bool bad,bad2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		w=d+1;
		bad=0;
		bad2=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			k=d2-k;
			if(k<d)
			{
				if(!bad)
				{
					w=min(w-1,k);
					bad2|=w<0;
					if(!w)
					{
						bad=1;
					}
				}
				else
				{
					w++;
					bad2|=w>k;
				}
			}
			else
			{
				w=d+1;
				bad=0;
			}
		}
		if(!bad2)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}