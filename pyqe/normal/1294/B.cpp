#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,zs;
pair<long long,long long> a[100069];
bitset<100069> sq;

int main()
{
	long long t,rr,i,k,l,y,x;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].fr,&a[i].sc);
		}
		sort(a+1,a+n+1);
		zs=0;
		bad=0;
		y=0;
		x=0;
		for(i=1;i<=n;i++)
		{
			k=a[i].fr;
			l=a[i].sc;
			if(l<x)
			{
				bad=1;
				break;
			}
			for(;y<k;y++)
			{
				zs++;
				sq[zs]=0;
			}
			for(;x<l;x++)
			{
				zs++;
				sq[zs]=1;
			}
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=1;i<=zs;i++)
			{
				printf("%c",(char)('R'+('U'-'R')*sq[i]));
			}
			printf("\n");
		}
	}
}