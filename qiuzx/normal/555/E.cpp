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
#define N 200010
using namespace std;
ll n,m,q,lw[N],din[N],tp[N],fa[N],ans,cnt=0,dp[N],f[N][32],dup[N],ddo[N],aup[N],ado[N];
bool vis[N];
vector<ll> vt2[N],bri,bco[N];
vector<pair<ll,ll> > vt[N];
map<ll,ll> mp;
void dfs(ll x,ll lst,ll le)
{
	vis[x]=true;
	lw[x]=din[x]=++cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].S!=le)
		{
			if(vis[vt[x][i].F])
			{
				lw[x]=min(lw[x],din[vt[x][i].F]);
			}
			else
			{
				dfs(vt[x][i].F,x,vt[x][i].S);
				lw[x]=min(lw[x],lw[vt[x][i].F]);
			}
		}
	}
	if(lw[x]==din[x]&&x!=0)
	{
		bri.push_back(min(x,lst)*n+max(x,lst));
		mp[min(x,lst)*n+max(x,lst)]=1;
	}
	return;
}
void dfs2(ll x)
{
	ll i;
	vis[x]=true;
	bco[cnt].push_back(x);
	tp[x]=cnt;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i].F]&&mp[min(x,vt[x][i].F)*n+max(x,vt[x][i].F)]!=1)
		{
			dfs2(vt[x][i].F);
		}
	}
	return;
}
void dfs3(ll x,ll lst,ll d,ll vx)
{
	ll i;
	vis[x]=true;
	fa[x]=vx;
	dp[x]=d;
	for(i=0;i<20;i++)
	{
		f[x][i+1]=f[f[x][i]][i];
	}
	for(i=0;i<vt2[x].size();i++)
	{
		if(vt2[x][i]!=lst)
		{
			f[vt2[x][i]][0]=x;
			dfs3(vt2[x][i],x,d+1,vx);
		}
	}
	return;
}
ll glca(ll x,ll y)
{
	ll i;
	if(dp[x]<dp[y])
	{
		swap(x,y);
	}
	for(i=20;i>=0;i--)
	{
		if(dp[f[x][i]]>=dp[y])
		{
			x=f[x][i];
		}
		if(x==y)
		{
			return x;
		}
	}
	for(i=20;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
void dfs4(ll x,ll lst)
{
	ll i;
	aup[x]=dup[x];
	ado[x]=ddo[x];
	for(i=0;i<vt2[x].size();i++)
	{
		if(vt2[x][i]!=lst)
		{
			dfs4(vt2[x][i],x);
			aup[x]+=aup[vt2[x][i]];
			ado[x]+=ado[vt2[x][i]];
		}
	}
	return;
}
int main(){
	ll i,j,x,y,z;
	scanf("%lld%lld%lld",&n,&m,&q);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
	}
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i,-1,-1);
		}
	}
	memset(vis,false,sizeof(vis));
	cnt=0;
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs2(i);
			cnt++;
		}
	}
	for(i=0;i<bri.size();i++)
	{
		x=bri[i]/n;
		y=bri[i]%n;
		x=tp[x];
		y=tp[y];
		vt2[x].push_back(y);
		vt2[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	for(i=0;i<cnt;i++)
	{
		if(!vis[i])
		{
			dfs3(i,-1,0,i);
		}
	}
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		x=tp[x];
		y=tp[y];
		if(fa[x]!=fa[y])
		{
			puts("No");
			return 0;
		}
		if(x==y)
		{
			continue;
		}
		z=glca(x,y);
		dup[z]--;
		dup[x]++;
		ddo[z]--;
		ddo[y]++;
	} 
	dfs4(0,-1);
	for(i=0;i<cnt;i++)
	{
		if(aup[i]>0&&ado[i]>0)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}