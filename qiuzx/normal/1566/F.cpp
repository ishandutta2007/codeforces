//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,m,a[N],dp[N][2];
vector<pair<ll,ll> > allseg,okseg;
vector<ll> hvseg[N];
void solve()
{
	ll i,j,l,r,mn,dx,dy;
	scanf("%lld%lld",&n,&m);
	a[0]=-LINF;
	a[n+1]=LINF;
	hvseg[0].clear();
	for(i=1;i<=n;i++)
	{
		hvseg[i].clear();
		scanf("%lld",&a[i]);
	}
	hvseg[n+1].clear();
	sort(a,a+n+2);
	allseg.clear();
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&l,&r);
		allseg.push_back(make_pair(l,r));
	}
	sort(allseg.begin(),allseg.end());
	okseg.clear();
	mn=LINF;
	for(i=allseg.size()-1;i>=0;i--)
	{
		if(allseg[i].S>=mn)
		{
			continue;
		}
		mn=min(mn,allseg[i].S);
		l=lower_bound(a,a+n+2,allseg[i].F)-a;
		r=upper_bound(a,a+n+2,allseg[i].S)-a-1;
		if(l<=r)
		{
			continue;
		}
		hvseg[r].push_back(okseg.size());
		okseg.push_back(allseg[i]);
	}
	reverse(okseg.begin(),okseg.end());
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<hvseg[i].size();j++)
		{
			hvseg[i][j]=okseg.size()-hvseg[i][j]-1;
		}
		reverse(hvseg[i].begin(),hvseg[i].end());
	}
	for(i=0;i<=n+1;i++)
	{
		dp[i][0]=dp[i][1]=LINF;
	}
	dp[0][0]=dp[0][1]=0;
	for(i=1;i<=n+1;i++)
	{
		for(dx=0;dx<2;dx++)
		{
			if(dp[i-1][dx]>=LINF)
			{
				continue;
			}
			for(dy=0;dy<2;dy++)
			{
				if(hvseg[i-1].size()==0)
				{
					dp[i][dy]=min(dp[i][dy],dp[i-1][dx]);
					continue;
				}
				dp[i][dy]=min(dp[i][dy],dp[i-1][dx]+(dx+1)*(okseg[hvseg[i-1][hvseg[i-1].size()-1]].F-a[i-1]));
				dp[i][dy]=min(dp[i][dy],dp[i-1][dx]+(2-dy)*(a[i]-okseg[hvseg[i-1][0]].S));
				for(j=0;j+1<hvseg[i-1].size();j++)
				{
					dp[i][dy]=min(dp[i][dy],dp[i-1][dx]+(dx+1)*(okseg[hvseg[i-1][j]].F-a[i-1])+(2-dy)*(a[i]-okseg[hvseg[i-1][j+1]].S));
				}
			}
		}
	}
	printf("%lld\n",min(dp[n+1][0],dp[n+1][1]));
	return;
}
int main(){
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}