#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,fq[169],pc[169][169],dp[169][169];
pair<long long,long long> a[10069];

long long bf(long long lh,long long rh)
{
	if(lh>rh)
	{
		return 0;
	}
	if(dp[lh][rh]==-1)
	{
		long long i,k;
		
		for(i=lh;i<=rh;i++)
		{
			k=pc[lh][rh]-pc[lh][i-1]-pc[i+1][rh];
			dp[lh][rh]=max(dp[lh][rh],bf(lh,i-1)+k*k+bf(i+1,rh));
		}
	}
	return dp[lh][rh];
}

int main()
{
	long long i,j,r,k,l,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld%lld",&k,&l);
			nn++;
			a[nn]={l,k};
		}
	}
	sort(a+1,a+nn+1);
	for(j=1,i=1;i<=m;i++)
	{
		for(;j<=nn&&a[j].fr<=i;j++)
		{
			k=a[j].sc;
			fq[k]++;
		}
		for(r=i;r;r--)
		{
			pc[r][i]=pc[r+1][i]+fq[r];
			dp[r][i]=-1;
		}
	}
	printf("%lld\n",bf(1,m));
}