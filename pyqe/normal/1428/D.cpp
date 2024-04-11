#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[100069],sk[100069],zs=0;
pair<long long,long long> sq[200069];

void ad(long long y,long long x)
{
	zs++;
	sq[zs]={y,x};
}

int main()
{
	long long i,k,l=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i;i--)
	{
		if(a[i]==1)
		{
			ad(i,i);
			nn++;
			sk[nn]=i;
		}
		else if(a[i]==2)
		{
			if(nn)
			{
				ad(sk[nn],i);
				nn--;
			}
			else
			{
				i=-2;
				break;
			}
			l=i;
		}
		else if(a[i]==3)
		{
			if(l)
			{
				ad(i,l);
				ad(i,i);
			}
			else if(nn)
			{
				ad(i,sk[nn]);
				ad(i,i);
				nn--;
			}
			else
			{
				i=-2;
				break;
			}
			l=i;
		}
	}
	if(i!=-2)
	{
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			k=sq[i].fr;
			l=sq[i].sc;
			printf("%lld %lld\n",k,l);
		}
	}
	else
	{
		printf("-1\n");
	}
}