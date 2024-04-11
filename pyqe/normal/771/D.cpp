#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,fq[3],vl[3][76],dp[76][76][76][2],fw[76],fi;

inline void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

inline long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long i,j,ii,jj,k,w,p[3];
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		k=(ch=='K')+2*(ch!='V'&&ch!='K');
		fq[k]++;
		vl[k][fq[k]]=i;
		if(k!=2)
		{
			ud(i,1);
		}
	}
	for(p[0]=0;p[0]<=fq[0];p[0]++)
	{
		for(p[1]=0;p[1]<=fq[1];p[1]++)
		{
			for(p[2]=0;p[2]<=fq[2];p[2]++)
			{
				for(ii=0;ii<2;ii++)
				{
					dp[p[0]][p[1]][p[2]][ii]=inf;
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		dp[0][0][0][ii]=0;
	}
	for(i=0;i<=n;i++)
	{
		for(p[0]=0;p[0]<=min(i,fq[0]);p[0]++)
		{
			if(p[0])
			{
				ud(vl[0][p[0]],-1);
			}
			for(j=fq[2],p[1]=0;p[1]<=min(i-p[0],fq[1]);p[1]++)
			{
				p[2]=i-p[0]-p[1];
				if(p[1])
				{
					ud(vl[1][p[1]],-1);
				}
				if(p[2]>=0&&p[2]<=fq[2])
				{
					for(;j>max(p[2],0ll);j--)
					{
						ud(vl[2][j],1);
					}
					for(ii=0;ii<3;ii++)
					{
						if(p[ii]<fq[ii])
						{
							w=dp[p[0]][p[1]][p[2]][ii==1]+qr(vl[ii][p[ii]+1]-1);
							for(jj=0;jj<=!!ii;jj++)
							{
								dp[p[0]+!ii][p[1]+(ii==1)][p[2]+(ii==2)][jj]=min(dp[p[0]+!ii][p[1]+(ii==1)][p[2]+(ii==2)][jj],w);
							}
						}
					}
				}
			}
			for(j=fq[2],p[1]=0;p[1]<=min(i-p[0],fq[1]);p[1]++)
			{
				p[2]=i-p[0]-p[1];
				if(p[1])
				{
					ud(vl[1][p[1]],1);
				}
				for(;j>max(p[2],0ll);j--)
				{
					ud(vl[2][j],-1);
				}
			}
		}
		for(p[0]=1;p[0]<=min(i,fq[0]);p[0]++)
		{
			ud(vl[0][p[0]],1);
		}
	}
	printf("%lld\n",dp[fq[0]][fq[1]][fq[2]][0]);
}