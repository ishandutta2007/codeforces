#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,a[100069],dg[100069],zs=0;
pair<long long,long long> as[100069],sq[100069];

void ae(long long x,long long y)
{
	zs++;
	sq[zs]={x,y};
	dg[x]++;
	dg[y]++;
}

int main()
{
	long long i,j,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		as[i]={a[i],i};
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	for(nn=0;nn+1<=n&&as[nn+1].fr>1;nn++);
	swap(as[min(nn+1,n)],as[1]);
	nn=min(nn+2,n);
	for(j=1,i=1;i<=n;i++)
	{
		k=as[i].sc;
		if(i<=nn)
		{
			if(i-1)
			{
				ae(l,k);
			}
		}
		else
		{
			for(;j<=nn&&dg[as[j].sc]==a[as[j].sc];j++);
			if(j>nn)
			{
				printf("NO\n");
				return 0;
			}
			ae(as[j].sc,k);
		}
		l=k;
	}
	printf("YES %lld\n%lld\n",nn-1,zs);
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}