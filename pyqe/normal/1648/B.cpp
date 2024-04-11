#include <bits/stdc++.h>

using namespace std;

long long n,d,ps[1000069];
bitset<1000069> vtd;

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=d;i++)
		{
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			vtd[k]=1;
		}
		for(i=1;i<=d;i++)
		{
			ps[i]=ps[i-1]+vtd[i];
		}
		for(i=1;i<=d;i++)
		{
			if(vtd[i])
			{
				for(j=i;j<=d;j+=i)
				{
					if(ps[min(j+i-1,d)]-ps[j-1]&&!vtd[j/i])
					{
						break;
					}
				}
				if(j<=d)
				{
					break;
				}
			}
		}
		if(i>d)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}