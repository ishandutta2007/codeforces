#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,d,a[100069],ca[100069];
vector<pair<pair<long long,long long>,pair<long long,long long>>> vl[100069];
vector<pair<long long,long long>> dp[100069];

int main()
{
	long long t,rr,i,j,r,ii,u,y,x,y2,x2,w,sz,sz2,x3,w2,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			vl[i].clear();
			dp[i].clear();
		}
		for(i=0;i<d;i++)
		{
			scanf("%lld%lld%lld%lld%lld",&y,&x,&y2,&x2,&w);
			vl[y].push_back({{x,y2},{x2,w}});
		}
		dp[1].push_back({1,0});
		vl[n].push_back({{m,n+1},{1,0}});
		dp[n+1].clear();
		for(i=1;i<=n;i++)
		{
			sort(vl[i].begin(),vl[i].end());
			sort(dp[i].begin(),dp[i].end());
			sz=vl[i].size();
			sz2=dp[i].size();
			for(j=0;j<sz;j++)
			{
				ca[j]=inf;
			}
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				mn=inf;
				for(r=(sz2-1)*ii,j=(sz-1)*ii;j>=0&&j<sz;j+=u)
				{
					x=vl[i][j].fr.fr;
					for(;r>=0&&r<sz2&&dp[i][r].fr*u<=x*u;r+=u)
					{
						x3=dp[i][r].fr;
						w2=dp[i][r].sc;
						if(w2!=inf)
						{
							mn=min(mn,w2-x3*a[i]*u);
						}
					}
					if(mn!=inf)
					{
						ca[j]=min(ca[j],x*a[i]*u+mn);
					}
				}
			}
			for(j=0;j<sz;j++)
			{
				y2=vl[i][j].fr.sc;
				x2=vl[i][j].sc.fr;
				w=vl[i][j].sc.sc;
				w2=inf;
				if(ca[j]!=inf)
				{
					w2=ca[j]-w;
				}
				dp[y2].push_back({x2,w2});
			}
		}
		if(dp[n+1][0].sc!=inf)
		{
			printf("%lld\n",dp[n+1][0].sc);
		}
		else
		{
			printf("NO ESCAPE\n");
		}
	}
}