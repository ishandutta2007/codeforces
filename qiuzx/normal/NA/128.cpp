//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 600010
using namespace std;
ll n,q,conn[N],ans[N],sonsz[N],mxsz[N],dp[N][2][2],col[N];
bool bannd[N];
vector<ll> pth;
vector<pair<ll,pair<ll,ll> > > vt[N],qry[N];
void predfs(ll x,ll lst)
{
	pth.push_back(x);
	sonsz[x]=1;
	mxsz[x]=0;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst&&(!bannd[vt[x][i].F]))
		{
			predfs(vt[x][i].F,x);
			sonsz[x]+=sonsz[vt[x][i].F];
			mxsz[x]=max(mxsz[x],sonsz[vt[x][i].F]);
		}
	}
	return;
}
ll getcent()
{
	ll i,mn=INF,ret=0;
	for(i=0;i<pth.size();i++)
	{
		if(mn>max(mxsz[pth[i]],(ll)pth.size()-sonsz[pth[i]]))
		{
			mn=max(mxsz[pth[i]],(ll)pth.size()-sonsz[pth[i]]);
			ret=pth[i];
		}
	}
	return ret;
}
void dfs(ll x,ll lst,ll c)
{
	ll i,j;
	col[x]=c;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst&&(!bannd[vt[x][i].F]))
		{
			for(j=0;j<2;j++)
			{
				dp[vt[x][i].F][0][j]=min(dp[x][0][j]+vt[x][i].S.F,dp[x][1][j]+vt[x][i].S.S+conn[vt[x][i].F]);
				dp[vt[x][i].F][1][j]=min(dp[x][1][j]+vt[x][i].S.S,dp[x][0][j]+vt[x][i].S.F+conn[vt[x][i].F]);
			}
			dfs(vt[x][i].F,x,(c==-1)?vt[x][i].F:c);
		}
	}
	return;
}
void dfs2(ll x,ll lst)
{
	ll i;
	for(i=0;i<qry[x].size();i++)
	{
		if(col[qry[x][i].S.S/2]!=-INF&&col[qry[x][i].S.S/2]!=col[x])
		{
			ans[qry[x][i].F]=min(dp[x][qry[x][i].S.F&1][0]+dp[qry[x][i].S.S>>1][qry[x][i].S.S&1][0],dp[x][qry[x][i].S.F&1][1]+dp[qry[x][i].S.S>>1][qry[x][i].S.S&1][1]);
		}
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst&&(!bannd[vt[x][i].F]))
		{
			dfs2(vt[x][i].F,x);
		}
	}
}
void clrc(ll x,ll lst)
{
	col[x]=-INF;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst&&(!bannd[vt[x][i].F]))
		{
			clrc(vt[x][i].F,x);
		}
	}
	return;
}
void solve(ll x)
{
	ll i;
	pth.clear();
	predfs(x,-1);
	x=getcent();
	dp[x][0][0]=dp[x][1][1]=0;
	dp[x][0][1]=dp[x][1][0]=conn[x];
	dfs(x,-1,-1);
	dfs2(x,-1);
	clrc(x,-1);
	bannd[x]=true;
	for(i=0;i<vt[x].size();i++)
	{
		if(!bannd[vt[x][i].F])
		{
			solve(vt[x][i].F);
		}
	}
	return;
}
int main(){
	ll i,x,y,z1,z2;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		col[i]=-INF;
		scanf("%lld",&conn[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&z1,&z2);
		x--,y--;
		vt[x].push_back(make_pair(y,make_pair(z1,z2)));
		vt[y].push_back(make_pair(x,make_pair(z1,z2)));
	}
	priority_queue<pair<ll,ll> > pq;
	for(i=0;i<n;i++)
	{
		pq.push(make_pair(-conn[i],i));
	}
	while(!pq.empty())
	{
		x=pq.top().S,y=-pq.top().F;
		pq.pop();
		if(y!=conn[x])
		{
			continue;
		}
		for(i=0;i<vt[x].size();i++)
		{
			if(conn[vt[x][i].F]>y+vt[x][i].S.F+vt[x][i].S.S)
			{
				conn[vt[x][i].F]=y+vt[x][i].S.F+vt[x][i].S.S;
				pq.push(make_pair(-conn[vt[x][i].F],vt[x][i].F));
			}
		}
	}
	scanf("%lld",&q);
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		if(x/2==y/2)
		{
			ans[i]=conn[x/2];
		}
		else
		{
			qry[x/2].push_back(make_pair(i,make_pair(x,y)));
		}
	}
	solve(0);
	for(i=0;i<q;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}