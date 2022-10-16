#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,d,p[2],sm,a[35069],pst[35069],ls[2][35069],dp[2][35069];

void dnc(long long lh,long long rh,long long lb,long long rb)
{
	if(lh<=rh)
	{
		long long md=(lh+rh)/2,e;
		pair<long long,long long> mne={inf,-1};
		
		for(;p[0]>lb;)
		{
			p[0]--;
			if(ls[1][p[0]]<=p[1])
			{
				sm+=ls[1][p[0]]-p[0];
			}
		}
		for(;p[1]<md;)
		{
			p[1]++;
			if(ls[0][p[1]]>=p[0])
			{
				sm+=p[1]-ls[0][p[1]];
			}
		}
		for(;p[0]<lb;p[0]++)
		{
			if(ls[1][p[0]]<=p[1])
			{
				sm-=ls[1][p[0]]-p[0];
			}
		}
		for(;p[1]>md;p[1]--)
		{
			if(ls[0][p[1]]>=p[0])
			{
				sm-=p[1]-ls[0][p[1]];
			}
		}
		for(;1;)
		{
			mne=min(mne,{dp[0][p[0]-1]+sm,p[0]});
			if(p[0]==min(rb,md))
			{
				break;
			}
			if(ls[1][p[0]]<=p[1])
			{
				sm-=ls[1][p[0]]-p[0];
			}
			p[0]++;
		}
		dp[1][md]=mne.fr;
		e=mne.sc;
		dnc(lh,md-1,lb,e);
		dnc(md+1,rh,e,rb);
	}
}

int main()
{
	long long i,j,ii,u;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dp[0][i]=inf;
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1;i<=n;i++)
		{
			pst[i]=(n+1)*ii;
		}
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			ls[ii][i]=pst[a[i]];
			pst[a[i]]=i;
		}
	}
	for(i=1;i<=d;i++)
	{
		p[0]=1;
		p[1]=0;
		sm=0;
		dnc(i,n,i,n);
		for(j=i;j<=n;j++)
		{
			dp[0][j]=dp[1][j];
		}
	}
	printf("%lld\n",dp[0][n]);
}