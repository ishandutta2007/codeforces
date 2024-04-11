#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,wg[1069],dp[1069][2][2],inf=1e18;
pair<long long,long long> a[1069];
vector<long long> al[1069];
double pi=acos(-1);

void dfs(long long x)
{
	long long i,ii,iii,u,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		for(ii=0;ii<2;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				dp[x][ii][iii]+=max(dp[l][!ii][iii],dp[l][iii][!ii]);
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(iii=0;iii<2;iii++)
		{
			dp[x][ii][iii]+=wg[x]*wg[x]*u;
		}
	}
}

int main()
{
	long long i,j,y,x,yy,xx,ly,lx;
	pair<long long,long long> mne;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&y,&x,wg+i);
		a[i]={y,x};
	}
	for(i=1;i<=n;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		mne={inf,0};
		for(j=1;j<=n;j++)
		{
			yy=a[j].fr;
			xx=a[j].sc;
			ly=y-yy;
			lx=x-xx;
			if(wg[j]>wg[i]&&ly*ly+lx*lx<=wg[j]*wg[j])
			{
				mne=min(mne,{wg[j],j});
			}
		}
		al[mne.sc].push_back(i);
	}
	dfs(0);
	printf("%.20lf\n",pi*dp[0][1][0]);
}