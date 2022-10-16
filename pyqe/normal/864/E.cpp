#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dp[169][2069],sz=0;
pair<pair<long long,long long>,pair<long long,long long>> a[169];
stack<long long> sq;

int main()
{
	long long i,j,z=-1e18,e,k,l,w,pz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].fr.sc,&a[i].fr.fr,&a[i].sc.fr);
		a[i].sc.sc=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=2000;i++)
	{
		dp[0][i]=-1e18;
	}
	for(i=1;i<=n;i++)
	{
		k=a[i].sc.fr;
		l=a[i].fr.fr;
		w=a[i].fr.sc;
		pz=a[i].sc.sc;
		for(j=0;j<=2000;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=w&&j<l)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-w]+k);
			}
			if(i==n)
			{
				if(dp[i][j]>z)
				{
					z=dp[i][j];
					e=j;
				}
			}
		}
	}
	printf("%lld\n",z);
	for(i=n;i>0;i--)
	{
		k=a[i].sc.fr;
		l=a[i].fr.fr;
		w=a[i].fr.sc;
		pz=a[i].sc.sc;
		if(e>=w&&e<l&&dp[i-1][e-w]+k==dp[i][e])
		{
			sq.push(pz);
			sz++;
			e-=w;
		}
	}
	printf("%lld\n",sz);
	for(;sz;sq.pop(),sz--)
	{
		printf("%lld%c",sq.top()," \n"[sz==1]);
	}
}