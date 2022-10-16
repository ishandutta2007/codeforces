#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[2][1069][1069],dp[2][1069][1069],zs=0,ys=-1,xs=-1;
bitset<1000069> sq;

int main()
{
	long long i,j,k,ii,u,mn,e;
	pair<long long,long long> mne;
	
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(!i||!j)
			{
				if(i>1||j>1)
				{
					for(ii=0;ii<2;ii++)
					{
						dp[ii][i][j]=1e18;
					}
				}
			}
			else
			{
				scanf("%lld",&k);
				for(ii=0;ii<2;ii++)
				{
					if(!k)
					{
						a[ii][i][j]=1e18;
						ys=i;
						xs=j;
					}
					else
					{
						u=2+ii*3;
						for(;k%u==0;a[ii][i][j]++,k/=u);
					}
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				dp[ii][i][j]=min(min(dp[ii][i-1][j],dp[ii][i][j-1])+a[ii][i][j],1000000000000000000ll);
			}
		}
	}
	mne=min(mp(dp[0][n][n],0),{dp[1][n][n],1});
	if(ys!=-1)
	{
		mne=min(mne,{1,-1});
	}
	mn=mne.fr;
	e=mne.sc;
	if(e!=-1)
	{
		for(i=n,j=n;i>1||j>1;)
		{
			for(ii=0;ii<2;ii++)
			{
				if(dp[e][i-!ii][j-ii]+a[e][i][j]==dp[e][i][j])
				{
					break;
				}
			}
			sq[n*2-2-zs]=ii;
			zs++;
			i-=!ii;
			j-=ii;
		}
	}
	else
	{
		zs+=ys-1;
		for(i=0;i<xs-1;i++)
		{
			zs++;
			sq[zs]=1;
		}
		zs+=n-ys;
		for(i=0;i<n-xs;i++)
		{
			zs++;
			sq[zs]=1;
		}
	}
	printf("%lld\n",mn);
	for(i=1;i<=n*2-2;i++)
	{
		printf("%c","DR"[sq[i]]);
	}
	printf("\n");
}