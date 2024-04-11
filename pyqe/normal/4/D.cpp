#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[5069],zs=0;
pair<pair<long long,long long>,long long> a[5069];
pair<long long,long long> dp[5069];

int main()
{
	long long i,j,mx,e,p;
	pair<long long,long long> mxe={-1e18,-1};
	
	scanf("%lld%lld%lld",&n,&a[0].fr.fr,&a[0].fr.sc);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr.fr,&a[i].fr.sc);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		dp[i]={-1e18,-1};
	}
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[j].fr.fr>a[i].fr.fr&&a[j].fr.sc>a[i].fr.sc)
			{
				dp[j]=max(dp[j],{dp[i].fr+1,i});
			}
		}
		mxe=max(mxe,{dp[i].fr,i});
	}
	mx=mxe.fr;
	e=mxe.sc;
	for(p=e;p;p=dp[p].sc)
	{
		zs++;
		sq[zs]=a[p].sc;
	}
	printf("%lld\n",mx);
	for(i=zs;i;i--)
	{
		printf("%lld%c",sq[i]," \n"[i==1]);
	}
}