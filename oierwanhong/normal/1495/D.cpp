#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
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
const int MAXN = 411,mod = 998244353;
int dis[MAXN][MAXN];
std::vector<int>g[MAXN];
void Floyd(int n)
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)umin(dis[i][j],dis[i][k]+dis[k][j]);
}
int Q[MAXN],f[MAXN],pre[MAXN];
bool used[MAXN];
void bfs(int s)
{
	memset(f,0,sizeof f),memset(pre,0,sizeof pre),memset(used,0,sizeof used);
	int h=0,t=0;
	f[s]=1,Q[t++]=s;
	while(h<t)
	{
		int u=Q[h++];
		for(auto v:g[u])
			if(dis[s][u]+1==dis[s][v])
			{
				f[v]=(f[v]+f[u])%mod;
				if(!pre[v])pre[v]=u,Q[t++]=v;
			}
	}
}
int main()
{
	memset(dis,0x3f,sizeof dis);
	int n=read(),m=read();
	for(int i=1;i<=n;++i)dis[i][i]=0;
	while(m--){int u=read(),v=read();dis[u][v]=dis[v][u]=1,g[u].push_back(v),g[v].push_back(u);}
	Floyd(n);
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=n;++j)
		{
			bfs(i);
			int mul=f[j];
			for(int t=j;t!=i;t=pre[t])used[t]=1;
			used[i]=1;
			for(int u=1;u<=n;++u)
			{
				if(used[u])continue;
				int cur=0;
				for(auto v:g[u])
					if(dis[i][u]==dis[i][v]+1&&dis[j][u]==dis[j][v]+1)++cur;
				mul=ll(mul)*cur%mod;
			}
			printf("%d ",mul);
		}
	return 0;
}