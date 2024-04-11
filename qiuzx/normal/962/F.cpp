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
#define N 100010 
using namespace std;
ll n,m,lw[N],din[N],cnt=0,cnt2=0;
bool vis[N];
vector<pair<ll,ll> > vt[N],ed;
vector<ll> sz[N],ans,edsz[N],bcc[N];
stack<ll> stk;
void dfs(ll x,ll lst)
{
	vis[x]=true;
	lw[x]=din[x]=++cnt;
	ll i,j;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			if(vis[vt[x][i].F])
			{
				lw[x]=min(lw[x],din[vt[x][i].F]);
			}
			else
			{
				stk.push(vt[x][i].F);
				dfs(vt[x][i].F,x);
				lw[x]=min(lw[x],lw[vt[x][i].F]);
				if(lw[vt[x][i].F]>=din[x])
				{
					while(stk.top()!=vt[x][i].F)
					{
						bcc[stk.top()].push_back(cnt2);
						sz[cnt2].push_back(stk.top());
						stk.pop();
					}
					bcc[stk.top()].push_back(cnt2);
					sz[cnt2].push_back(stk.top());
					stk.pop();
					bcc[x].push_back(cnt2);
					sz[cnt2++].push_back(x);
				}
			}
		}
	}
	return;
}
int main(){
	ll i,j,x,y;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
		ed.push_back(make_pair(x,y));
	}
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i,-1);
		}
	}
	for(i=0;i<m;i++)
	{
		x=ed[i].F;
		y=ed[i].S;
		if(bcc[x].size()>bcc[y].size())
		{
			swap(x,y);
		}
		for(j=0;j<bcc[x].size();j++)
		{
			if(bcc[y][lower_bound(bcc[y].begin(),bcc[y].end(),bcc[x][j])-bcc[y].begin()]==bcc[x][j])
			{
				edsz[bcc[x][j]].push_back(i);
				break;
			}
		}
	}
	for(i=0;i<cnt2;i++)
	{
		if(edsz[i].size()==sz[i].size())
		{
			for(j=0;j<edsz[i].size();j++)
			{
				ans.push_back(edsz[i][j]);
			}
		}
	}
	sort(ans.begin(),ans.end());
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]+1);
	}
	puts("");
	return 0;
}