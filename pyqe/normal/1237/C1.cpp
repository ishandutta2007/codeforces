#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<pair<long long,long long>,pair<long long,long long>> a[50069];
bitset<50069> vtd;

int main()
{
	long long i,ls;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].fr.fr,&a[i].fr.sc,&a[i].sc.fr);
		a[i].sc.sc=i;
	}
	sort(a+1,a+n+1);
	ls=-1;
	for(i=1;i<=n;i++)
	{
		if(ls!=-1&&a[i].fr.fr==a[ls].fr.fr&&a[i].fr.sc==a[ls].fr.sc)
		{
			printf("%lld %lld\n",a[i].sc.sc,a[ls].sc.sc);
			vtd[i]=1;
			vtd[ls]=1;
			ls=-1;
		}
		else
		{
			ls=i;
		}
	}
	ls=-1;
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			if(ls!=-1&&a[i].fr.fr==a[ls].fr.fr)
			{
				printf("%lld %lld\n",a[i].sc.sc,a[ls].sc.sc);
				vtd[i]=1;
				vtd[ls]=1;
				ls=-1;
			}
			else
			{
				ls=i;
			}
		}
	}
	ls=-1;
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			if(ls!=-1)
			{
				printf("%lld %lld\n",a[i].sc.sc,a[ls].sc.sc);
				vtd[i]=1;
				vtd[ls]=1;
				ls=-1;
			}
			else
			{
				ls=i;
			}
		}
	}
}