#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,hl[100069],a[100069],ps[100069],dp[2][100069];

void dnc(long long x,long long l,long long r,long long lh,long long rh)
{
	long long i,md=(lh+rh)/2,mn,e;
	pair<long long,long long> mne={1e18,-1};
	
	if(lh>rh)
	{
		return;
	}
	for(i=l;i<=min(r,md);i++)
	{
		mne=min(mne,{dp[0][i]+a[md]*(md-i)-ps[md]+ps[i],i});
	}
	mn=mne.fr;
	e=mne.sc;
	dp[1][md]=mn;
	dnc(x,l,e,lh,md-1);
	dnc(x,e,r,md+1,rh);
}

int main()
{
	long long i,j,k,l;
	
	scanf("%lld%lld%lld",&d,&n,&m);
	for(i=2;i<=d;i++)
	{
		scanf("%lld",&k);
		hl[i]=hl[i-1]+k;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]=l-hl[k];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i];
		dp[0][i]=1e18;
	}
	for(i=1;i<=m;i++)
	{
		dnc(i,0,n,0,n);
		for(j=0;j<=n;j++)
		{
			dp[0][j]=dp[1][j];
		}
	}
	printf("%lld\n",dp[0][n]);
}