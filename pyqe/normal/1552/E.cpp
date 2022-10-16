#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ub,a[10069],ls[169];
pair<long long,long long> sq[169];

int main()
{
	long long i,j,r;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n*d;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=(n-1)/(d-1)+1;i++)
	{
		for(j=1;j<=n*d;j++)
		{
			if((a[j]-1)/(d-1)+1==i&&ls[a[j]]+1)
			{
				if(!ls[a[j]])
				{
					ls[a[j]]=j;
				}
				else
				{
					sq[a[j]]={ls[a[j]],j};
					ls[a[j]]=-1;
					for(r=1;r<=n;r++)
					{
						ls[r]=min(ls[r],0ll);
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}