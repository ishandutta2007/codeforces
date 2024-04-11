#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::vector<int> P;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

const int MAXN = 300011,mod = 1e9+7;
std::vector<int>t[MAXN];
int dep[MAXN],val[MAXN],fa[MAXN],size[MAXN];
int f[MAXN][2],cnt[2];
void dfs1(int u)
{
	dep[u]=dep[fa[u]]^1,++f[u][dep[u]],size[u]=1;
	for(auto v:t[u])
		if(v!=fa[u])fa[v]=u,dfs1(v),f[u][0]+=f[v][0],f[u][1]+=f[v][1],size[u]+=size[v];
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)val[i]=(read()%mod+mod)%mod;
	for(int i=1;i<n;++i){int u=read(),v=read();t[u].push_back(v),t[v].push_back(u);}
	dfs1(1);
	cnt[0]=f[1][0],cnt[1]=f[1][1];
	ll ans=0;
	for(int u=1;u<=n;++u)
	{
		bool k=dep[u];
		ll s= ll((cnt[k]-f[u][k])-(cnt[!k]-f[u][!k]))*size[u]+n;
		for(auto v:t[u])
			if(v!=fa[u])
			{
				s=(s+ll(f[v][k]-f[v][!k])*(n-size[v]))%mod;
			}
		ans=(ans+s*val[u])%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}