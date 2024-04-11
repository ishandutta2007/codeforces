#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[3],inf=1e18;
map<pair<long long,long long>,pair<long long,long long>> mxe;

int main()
{
	long long i,j;
	pair<long long,long long> tg[3];
	pair<long long,pair<long long,long long>> z={-inf,{0,0}};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%lld",a+j);
		}
		for(j=0;j<3;j++)
		{
			tg[j]={a[(j+1)%3],a[(j+2)%3]};
			if(tg[j].fr>tg[j].sc)
			{
				swap(tg[j].fr,tg[j].sc);
			}
			z=max(z,{min(a[j]+mxe[tg[j]].fr,tg[j].fr),{i,mxe[tg[j]].sc}});
		}
		for(j=0;j<3;j++)
		{
			mxe[tg[j]]=max(mxe[tg[j]],{a[j],i});
		}
	}
	printf("%lld\n%lld",1ll+!!z.sc.sc,z.sc.fr);
	if(z.sc.sc)
	{
		printf(" %lld",z.sc.sc);
	}
	printf("\n");
}