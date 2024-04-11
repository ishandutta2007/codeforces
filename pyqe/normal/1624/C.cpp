#include <bits/stdc++.h>

using namespace std;

long long n,a[1069];
bitset<1069> vtd;

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			vtd[i]=0;
		}
		for(i=n;i;i--)
		{
			for(j=1;j<=n;j++)
			{
				if(!vtd[j])
				{
					for(k=a[j];k>i;k/=2);
					if(k==i)
					{
						vtd[j]=1;
						break;
					}
				}
			}
			if(j>n)
			{
				break;
			}
		}
		if(i<1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}