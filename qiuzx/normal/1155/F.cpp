#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 15
#define M 20010
using namespace std;
bool hv[N*N];
ll n,m,dp[M],path[M],cnt=0,vis[N][M];
vector<ll> len[M],along;
vector<pair<ll,ll> > ed,vt[M];
void dfs(ll x,ll beg,ll ed,ll prep,ll mask)
{
	ll i,j;
	vis[x][mask]=cnt;
	if(ed!=-1)
	{
		along.push_back(ed);
	}
	if((prep&(1<<x))&&mask>0)
	{
		if(!(x==beg&&__builtin_popcount(mask)==2))
		{
			if(dp[prep|mask]>dp[prep]+__builtin_popcount(mask))
			{
				dp[prep|mask]=dp[prep]+__builtin_popcount(mask);
				path[prep|mask]=prep;
				len[prep|mask].clear();
				for(i=0;i<along.size();i++)
				{
					len[prep|mask].push_back(along[i]);
				}
			}
			along.pop_back();
			return;
		}
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(((prep&(1<<vt[x][i].F))||((!(prep&(1<<vt[x][i].F)))&&(!(mask&(1<<vt[x][i].F)))))&&(!(vt[x][i].F==beg&&__builtin_popcount(mask)==1))&&vis[vt[x][i].F][mask|(1<<vt[x][i].F)]!=cnt)
		{
			dfs(vt[x][i].F,beg,vt[x][i].S,prep,mask|(1<<vt[x][i].F));
			//cout<<x<<" "<<mask<<endl;
		}
	}
	if(!along.empty())
	{
		along.pop_back();
	}
	return;
}
void print_path(ll mask)
{
	if(mask==-1)
	{
		return;
	}
	ll i;
	for(i=0;i<len[mask].size();i++)
	{
		cout<<ed[len[mask][i]].F+1<<" "<<ed[len[mask][i]].S+1<<endl;
	}
	print_path(path[mask]);
	return;
}
int main(){
	ll i,j,k,x,y,mask;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
		ed.push_back(make_pair(x,y));
	}
	memset(path,-1,sizeof(path));
	memset(dp,127,sizeof(dp));
	dp[1]=0;
	for(mask=0;mask<(1<<n);mask++)
	{
		if(dp[mask]>=LINF)
		{
			continue;
		}
		cnt=mask;
		for(i=0;i<n;i++)
		{
			if(!(mask&(1<<i)))
			{
				continue;
			}
			dfs(i,i,-1,mask,0);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	print_path((1<<n)-1);
	return 0;
}