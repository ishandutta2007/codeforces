#include <bits/stdc++.h>

using namespace std;

long long n,d;
bitset<1069> a[2];

int main()
{
	long long i,ii,k,mx=0;
	
	scanf("%lld%lld",&n,&d);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[ii][i]=k;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[0][i]&&a[1][i])
		{
			mx=max(mx,i);
		}
	}
	if(a[0][1]&&(a[0][d]||(a[1][d]&&mx>=d)))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}