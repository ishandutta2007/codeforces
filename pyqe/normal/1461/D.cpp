#include <bits/stdc++.h>

using namespace std;

long long n,m,rr,a[100069];
map<long long,long long> ls;

void dnc(long long lh,long long rh)
{
	long long i,sm=0,md=(a[lh]+a[rh])/2;
	
	for(i=lh;i<=rh;i++)
	{
		sm+=a[i];
	}
	ls[sm]=rr;
	if(a[lh]!=a[rh])
	{
		for(i=lh;a[i+1]<=md;i++);
		dnc(lh,i);
		dnc(i+1,rh);
	}
}

int main()
{
	long long t,i,k;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		dnc(1,n);
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			if(ls[k]==rr)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
}