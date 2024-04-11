#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,lb,rb,a[100069],sq[100069];
pair<long long,long long> od[100069];

int main()
{
	long long i,k,p,ls=-1e18;
	
	scanf("%lld%lld%lld",&n,&lb,&rb);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&od[i].fr);
		od[i].sc=i;
	}
	sort(od+1,od+n+1);
	for(i=1;i<=n;i++)
	{
		k=od[i].fr;
		p=od[i].sc;
		sq[p]=max(a[p]+ls+1,lb);
		if(sq[p]>rb)
		{
			printf("-1\n");
			return 0;
		}
		ls=sq[p]-a[p];
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}