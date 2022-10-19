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
ll n,m,q,lw[N],din[N],tp[N],val[N],ddp[N],dp[N],f[N][32],cnt=0;
bool vis[N];
map<ll,ll> mp;
vector<ll> vt[N],bri,vt2[N],sz[N];
ll ksm(ll x,ll y)
{
	if(y==0)
	{
		return 1;
	}
	ll ret=ksm(x,y>>1);
	ret=(ret*ret)%MOD;
	if(y%2==1)
	{
		return (ret*x)%MOD;
	}
	return ret;
}
void dfs(ll x,ll lst)
{
	ll i;
	vis[x]=true;
	lw[x]=din[x]=++cnt;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			if(vis[vt[x][i]])
			{
				lw[x]=min(lw[x],din[vt[x][i]]);
			}
			else
			{
				dfs(vt[x][i],x);
				lw[x]=min(lw[x],lw[vt[x][i]]);
			}
		}
	}
	if(din[x]==lw[x]&&x!=0)
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
	tp[x]=cnt;
	sz[cnt].push_back(x);
	for(i=0;i<vt[x].size();i++)
	{
		if(vis[vt[x][i]]||mp[min(x,vt[x][i])*n+max(x,vt[x][i])]==1)
		{
			continue;
		}
		dfs2(vt[x][i]);
	}
	return;
}
void dfs3(ll x,ll lst,ll d)
{
	ll i;
	dp[x]=d;
	if(lst!=-1)
	{
		ddp[x]+=ddp[lst];
	}
	for(i=0;i<20;i++)
	{
		f[x][i+1]=f[f[x][i]][i];
	}
	for(i=0;i<vt2[x].size();i++)
	{
		if(vt2[x][i]!=lst)
		{
			f[vt2[x][i]][0]=x;
			dfs3(vt2[x][i],x,d+1);
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
        if(f[y][i]!=f[x][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int main(){
	ll i,x,y,z;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
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
	for(i=0;i<cnt;i++)
	{
		if(sz[i].size()<=1)
		{
			val[i]=0;
		}
		else
		{
			val[i]=1;
		}
		ddp[i]=val[i];
	}
	dfs3(0,-1,0);
	scanf("%lld",&q);
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		x=tp[x];
		y=tp[y];
		z=glca(x,y);
		printf("%lld\n",ksm((ll)2,ddp[x]+ddp[y]-2*ddp[z]+val[z]));
	}
	return 0;
}