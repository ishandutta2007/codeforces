#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,nn=0,a[2069],ct[2][4069],dp[2][2069][2][4069],sbt[2][2069],sq[4069],dv=1e9+7;
vector<pair<int,int>> al[2069];
bitset<4069> vtd;

void dfs(int x)
{
	int i,sz=al[x].size(),l,p;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[p])
		{
			vtd[p]=1;
			if(l!=1)
			{
				dfs(l);
			}
			else
			{
				nn++;
			}
			a[nn]++;
		}
	}
}

int main()
{
	int i,j,r,ii,jj,u,uu,k,l,z;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	dfs(1);
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(jj=0;jj<2;jj++)
		{
			dp[ii][(nn+1)*ii][jj][0]=1;
		}
		for(i=1+(nn-1)*ii;i&&i<=nn;i+=u)
		{
			sbt[ii][i]=sbt[ii][i-u]+a[i];
			for(jj=0;jj<2;jj++)
			{
				for(j=0;j<=sbt[ii][i];j++)
				{
					dp[ii][i][jj][j]=dp[ii][i-u][jj][j]*jj;
					for(uu=-1;uu<=1;uu+=2)
					{
						if(j+a[i]*uu>=-sbt[ii][i-u]&&j+a[i]*uu<=sbt[ii][i-u])
						{
							dp[ii][i][jj][j]=(dp[ii][i][jj][j]+dp[ii][i-u][jj][abs(j+a[i]*uu)])%dv;
						}
					}
				}
			}
		}
	}
	z=dp[0][nn][0][0];
	for(i=1;i<=nn;i++)
	{
		for(jj=0;jj<2;jj++)
		{
			for(j=0;j<=m;j++)
			{
				sq[j]=0;
			}
			for(j=-sbt[0][i-1];j<=sbt[0][i-1];j++)
			{
				for(r=max(-sbt[1][i+1],-j);r<=min(sbt[1][i+1],a[i]-j);r++)
				{
					sq[j+r]=((long long)dp[0][i-1][jj][abs(j)]*dp[1][i+1][jj][abs(r)]+sq[j+r])%dv;
				}
			}
			if(!jj)
			{
				z=((long long)sq[a[i]-1]*4+z)%dv;
			}
			else
			{
				for(j=1;j<a[i];j++)
				{
					z=(((long long)sq[abs(j-(a[i]-j))]+sq[abs(j-(a[i]-j-1))]*(j<a[i]-1))*2+z)%dv;
				}
			}
			
		}
	}
	printf("%d\n",z);
}