#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fq[300069];
pair<long long,long long> a[300069];

int main()
{
	long long i,it,c,ls;
	
	scanf("%lld%lld",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	for(it=0;it<2;it++)
	{
		for(i=1;i<=m;i++)
		{
			fq[i]=0;
		}
		c=0;
		ls=0;
		for(i=1;i<n;i++)
		{
			if(a[i].fr==a[0].fr||a[i].sc==a[0].fr)
			{
				c++;
			}
			else
			{
				fq[a[i].fr]++;
				fq[a[i].sc]++;
				ls=i;
			}
		}
		if(fq[a[ls].fr]==n-c-1||fq[a[ls].sc]==n-c-1)
		{
			printf("YES\n");
			return 0;
		}
		swap(a[0].fr,a[0].sc);
	}
	printf("NO\n");
}