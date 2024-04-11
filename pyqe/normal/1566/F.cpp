#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=1e15,inf=1e18;
long long n,m,a[200069],dp[200069][3],px[200069];
vector<pair<long long,long long>> vl[200069];

int main()
{
	long long t,rr,i,j,k,l,w,w2,sz,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		n++;
		a[n]=-ma;
		n++;
		a[n]=ma;
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			vl[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			p=upper_bound(a+1,a+n+1,l)-a;
			if(a[p-1]<k)
			{
				vl[p].push_back({l,k});
			}
		}
		for(i=0;i<3;i++)
		{
			dp[1][i]=inf;
		}
		dp[1][0]=0;
		for(i=2;i<=n;i++)
		{
			sort(vl[i].begin(),vl[i].end(),greater<pair<long long,long long>>());
			sz=vl[i].size();
			px[sz]=-inf;
			for(j=sz-1;j+1;j--)
			{
				px[j]=max(px[j+1],vl[i][j].sc);
			}
			for(j=0;j<3;j++)
			{
				dp[i][j]=inf;
			}
			for(j=-1;j<sz;j++)
			{
				if(j+1<sz)
				{
					w=min({dp[i-1][0]+px[j+1]-a[i-1],dp[i-1][1]+(px[j+1]-a[i-1])*2,dp[i-1][2]+px[j+1]-a[i-1]});
				}
				else
				{
					w=min(dp[i-1][0],dp[i-1][1]);
				}
				if(j+1)
				{
					k=vl[i][j].fr;
					w2=a[i]-k;
					dp[i][1]=min(dp[i][1],w+w2);
					dp[i][2]=min(dp[i][2],w+w2*2);
				}
				else
				{
					dp[i][0]=min(dp[i][0],w);
				}
			}
		}
		printf("%lld\n",dp[n][0]);
	}
}