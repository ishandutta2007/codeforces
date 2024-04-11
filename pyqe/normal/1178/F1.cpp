#include <bits/stdc++.h>

using namespace std;

long long ln,n,nn=0,dsu[1000069],pst[1000069],dp[1569][569],sbt[1569],dv=998244353;
vector<long long> vl[569];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void jo(long long x,long long y)
{
	long long i,j,k;
	
	x=fd(x);
	y=fd(y);
	nn++;
	sbt[nn]=sbt[pst[x]]+sbt[pst[y]];
	for(i=1;i<=sbt[pst[x]];i++)
	{
		for(j=1;j<=sbt[pst[y]];j++)
		{
			k=dp[pst[x]][i]*dp[pst[y]][j]%dv;
			dp[nn][i]=(dp[nn][i]+k)%dv;
			dp[nn][i+j+1]=(dp[nn][i+j+1]+dv-k)%dv;
		}
	}
	for(i=2;i<=sbt[nn];i++)
	{
		dp[nn][i]=(dp[nn][i]+dp[nn][i-1])%dv;
	}
	dsu[y]=x;
	pst[x]=nn;
}

int main()
{
	long long i,j,r,u,k,l,w,sz,z=1;
	
	scanf("%lld%lld",&n,&ln);
	for(i=1;i<=ln;i++)
	{
		scanf("%lld",&k);
		if(k)
		{
			vl[k].push_back(i);
		}
	}
	dp[0][1]=1;
	sbt[0]=1;
	for(i=n;i;i--)
	{
		nn++;
		dp[nn][1]=1;
		sbt[nn]=1;
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			k=vl[i][j];
			dsu[k]=k;
			for(u=-1;u<=1;u+=2)
			{
				if((j||u==1)&&(j<sz-1||u==-1))
				{
					if(dsu[k+u])
					{
						l=fd(k+u);
						w=0;
						for(r=1;r<=sbt[pst[l]];r++)
						{
							w=(w+dp[pst[l]][r])%dv;
						}
						dp[nn][1]=dp[nn][1]*w%dv;
						dsu[l]=k;
					}
				}
			}
		}
		l=vl[i][0];
		if(fd(l)!=k)
		{
			printf("0\n");
			return 0;
		}
		pst[k]=nn;
		if(dsu[k+1])
		{
			jo(k,k+1);
		}
		if(dsu[l-1])
		{
			jo(k,l-1);
		}
	}
	for(i=1;i<=ln;i++)
	{
		if(dsu[i]&&fd(i)==i)
		{
			w=0;
			for(j=1;j<=sbt[pst[i]];j++)
			{
				w=(w+dp[pst[i]][j])%dv;
			}
			z=z*w%dv;
		}
	}
	printf("%lld\n",z);
}