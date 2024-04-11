//By OIerwanhong ,7/9
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/

const int MAXN = 611;
const ll INF = 1e18+233;
ll g[MAXN][MAXN];
ll dis[MAXN];
bool used[MAXN];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)g[i][j]=INF;
	while(m--)
	{
		int u=read()+1,v=read()+1;
		ll w=read();
		umin(g[u][v],w);
	}
	for(int s=1;s<=n;++s)
	{
		for(int i=1;i<=n;++i)dis[i]=g[s][i],used[i]=0;
		for(int w=1;w<=n;++w)
		{
			int u=-1;
			for(int i=1;i<=n;++i)
				if(!used[i]&&(u==-1||dis[i]<dis[u]))u=i;
			used[u]=1;
			for(int i=1;i<=n;++i)
				umin(dis[(i+dis[u]-1)%n+1],dis[u]+g[u][i]);
			umin(dis[u%n+1],dis[u]+1);
		}
		dis[s]=0;
		for(int i=1;i<=n;++i)printf("%lld ",dis[i]);
		puts("");
	}
	return 0;
}