#include <bits/stdc++.h>

using namespace std;

int n,m,nn[2],a[5069],ex[5069],fz[2][5069],ep[2][5069],wg[5069],ps[5069],dp[5069],inf=1e9;

void ad(int x,int w)
{
	nn[1]++;
	fz[1][nn[1]]=w;
	ep[1][nn[1]]=0;
	for(;a[x]%w==0;a[x]/=w,ep[1][nn[1]]++);
}

int main()
{
	int i,j,r,u,k,e,z=0,mx=-inf;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",ex+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=2;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				ad(i,j);
			}
		}
		if(a[i]-1)
		{
			ad(i,a[i]);
		}
		if(i==1)
		{
			for(j=1;j<=nn[1];j++)
			{
				fz[0][j]=fz[1][j];
				ep[0][j]=ep[1][j];
				e=ex[lower_bound(ex+1,ex+m+1,fz[0][j])-ex]==fz[0][j];
				u=!e*2-1;
				wg[i]+=ep[0][j]*u;
			}
			nn[0]=nn[1];
		}
		else
		{
			for(r=1,j=1;j<=nn[0]+1;j++)
			{
				for(;r<=nn[1]&&(j>nn[0]||fz[1][r]<fz[0][j]);r++)
				{
					e=ex[lower_bound(ex+1,ex+m+1,fz[1][r])-ex]==fz[1][r];
					u=!e*2-1;
					z+=ep[1][r]*u;
				}
				if(j<=nn[0])
				{
					e=ex[lower_bound(ex+1,ex+m+1,fz[0][j])-ex]==fz[0][j];
					u=!e*2-1;
					k=0;
					if(r<=nn[1]&&fz[1][r]==fz[0][j])
					{
						k=ep[1][r];
						r++;
					}
					ep[0][j]=min(ep[0][j],k);
					z+=(k-ep[0][j])*u;
					wg[i]+=ep[0][j]*u;
				}
			}
			for(r=0,j=1;j<=nn[0];j++)
			{
				if(ep[0][j])
				{
					r++;
					fz[0][r]=fz[0][j];
					ep[0][r]=ep[0][j];
				}
			}
			nn[0]=r;
		}
		nn[1]=0;
		ps[i]=ps[i-1]+wg[i];
		dp[i]=-inf;
		for(j=0;j<i;j++)
		{
			dp[i]=max(dp[i],dp[j]+ps[i]-ps[j]-wg[i]*(i-j));
		}
	}
	for(i=0;i<=n;i++)
	{
		mx=max(mx,dp[i]+ps[n]-ps[i]);
	}
	printf("%d\n",z+mx);
}