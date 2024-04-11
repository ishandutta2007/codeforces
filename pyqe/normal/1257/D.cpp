#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,mm,a[200069],rg[200069],ln[200069];
pair<long long,long long> d[200069];

int main()
{
	long long t,rr,i,c,z,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
		}
		scanf("%lld",&m);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&d[i].fr,&d[i].sc);
		}
		sort(d,d+m);
		mm=0;
		for(i=0;i<m;i++)
		{
			for(mm++;mm>1&&ln[mm-1]<=d[i].sc;mm--);
			rg[mm]=d[i].fr;
			ln[mm]=d[i].sc;
		}
		for(i=0;i<n;i++)
		{
			a[i]=lower_bound(rg,rg+mm+1,a[i])-rg;
			if(a[i]==mm+1)
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("-1\n");
			continue;
		}
		z=0;
		c=0;
		mx=-1e18;
		for(i=0;i<=n;i++)
		{
			c++;
			mx=max(mx,a[i]);
			if(i==n||c>ln[mx])
			{
				c=1;
				mx=a[i];
				z++;
			}
		}
		printf("%lld\n",z);
	}
}