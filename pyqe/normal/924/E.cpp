#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,db,ub,ttl=0,a[10069],fq[2][10069],dp[10069];
bitset<10069> kd;

int main()
{
	long long i,j,r,ii,k,z=-inf;
	
	scanf("%lld%lld%lld",&n,&db,&ub);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		kd[i]=k;
		fq[kd[i]][a[i]]++;
	}
	db=ttl-db;
	ub=ttl-ub;
	swap(db,ub);
	for(i=1;i<=ttl;i++)
	{
		dp[i]=-inf;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=ttl;i;i--)
		{
			if(fq[ii][i])
			{
				for(j=0;1;j++)
				{
					if((1ll<<j+1)-1<fq[ii][i])
					{
						k=i<<j;
					}
					else
					{
						k=i*(fq[ii][i]-((1ll<<j)-1));
					}
					for(r=ttl;r>=k;r--)
					{
						dp[r]=max(dp[r],dp[r-k]+max(r-max(r-ub+i-1,0ll)/i*i-(r-k+max(db-(r-k)-1,0ll)/i*i),0ll)/i*ii);
					}
					if((1ll<<j+1)-1>=fq[ii][i])
					{
						break;
					}
				}
			}
		}
	}
	for(i=0;i<=ttl;i++)
	{
		z=max(z,dp[i]);
	}
	printf("%lld\n",z);
}