#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[300069],pst[300069],zs=0;
vector<pair<long long,long long>> sq;

void mv(long long x,long long y)
{
	swap(a[x],a[y]);
	swap(pst[a[x]],pst[a[y]]);
	sq.push_back({x,y});
	zs++;
}

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pst[a[i]]=i;
	}
	for(i=1;i<=n/2;i++)
	{
		if(pst[i+n/2]<=n/2)
		{
			mv(pst[i+n/2],n);
		}
		mv(i,pst[i+n/2]);
		mv(i,i+n/2);
		if(pst[i]<=n/2)
		{
			mv(pst[i],n);
		}
		mv(i,pst[i]);
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}