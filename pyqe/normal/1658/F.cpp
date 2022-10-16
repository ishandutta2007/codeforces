#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[200069],ps[200069];

int main()
{
	long long t,rr,i,j,ii;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
			ps[i]=ps[i-1]+a[i];
		}
		if(ps[n]*m%n)
		{
			printf("-1\n");
			continue;
		}
		d=ps[n]*m/n;
		for(i=m;i<=n;i++)
		{
			if(ps[i]-ps[i-m]==d)
			{
				break;
			}
		}
		if(i<=n)
		{
			printf("1\n%lld %lld\n",i-m+1,i);
			continue;
		}
		for(i=1;i<=m;i++)
		{
			if(ps[i]+ps[n]-ps[n-(m-i)]==d)
			{
				break;
			}
		}
		printf("2\n1 %lld\n%lld %lld\n",i,n-(m-i)+1,n);
	}
}