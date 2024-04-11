#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 611;
const ll INF=1e16;
ll g[MAXN][MAXN],dis[MAXN][MAXN];
int id[MAXN][MAXN],l[MAXN][MAXN],up[MAXN][MAXN];
bool flag[MAXN][MAXN];
int main()
{
	memset(dis,0x3f,sizeof dis);
	int n=read(),m=read();
	for(int i=1;i<=n;++i)dis[i][i]=0;
	while(m--)
	{
		int u=read(),v=read();
		ll w=read();
		umin(dis[u][v],w),umin(dis[v][u],w);
	}
	memcpy(g,dis,sizeof g);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)umin(dis[i][j],dis[i][k]+dis[k][j]);
	int Q=read();
	for(int w=1;w<=Q;++w)
	{
		int s=read(),t=read(),lt=read();
		l[s][t]=lt;
	}
	for(int s=1;s<=n;++s)
	{
		for(int x=1;x<=n;++x)
		{
			ll val=-INF;
			for(int y=1;y<=n;++y)
				umax(val,l[s][y]-dis[x][y]);
			for(int y=1;y<=n;++y)
				if(dis[s][y]+g[y][x]<=val)flag[x][y]=flag[y][x]=1;
		}
	}
	int ans=0;
	for(int x=1;x<=n;++x)
		for(int y=x+1;y<=n;++y)ans+=flag[x][y];
	printf("%d\n",ans);
	return 0;
}