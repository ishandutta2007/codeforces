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

const int MAXN = 200011;
std::vector<int>g[MAXN];
int L[MAXN],R[MAXN];
ll f[MAXN][2];
void dfs(int u,int fa)
{
	f[u][0]=f[u][1]=0;
	for(auto v:g[u])
		if(v!=fa)
		{
			dfs(v,u);
			f[u][0]+=max(f[v][0]+abs(L[u]-L[v]),f[v][1]+abs(L[u]-R[v]));
			f[u][1]+=max(f[v][0]+abs(R[u]-L[v]),f[v][1]+abs(R[u]-R[v]));
		}
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)g[i].clear(),L[i]=read(),R[i]=read();
		for(int i=1;i<n;++i){int u=read(),v=read();g[u].push_back(v),g[v].push_back(u);}
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
	return 0;
}