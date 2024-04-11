#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 400011;
std::vector<int>g[MAXN];
int a[MAXN],inv[MAXN];
int ans=0;
void dfs(int u,int fa)
{
	std::vector<int>seq;
	int lst=0;
	for(auto v:g[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		if(!a[v])seq.emplace_back(v);
	}
	if(seq.size())
	{
		ans+=seq.size()<<1;
		seq.emplace_back(u);
		for(int i=0;i<seq.size();++i)
		{
			int x=seq[i],y=seq[(i+1)%seq.size()];
			a[x]=y,inv[y]=x;
		}
	}
}
int main()
{
	int n=read();
	for(int i=1;i<n;++i){int u=read(),v=read();g[u].emplace_back(v),g[v].emplace_back(u);}
	dfs(1,0);
	if(!a[1])
	{
		ans+=2;
		int v=g[1][0];
		a[1]=v,a[inv[v]]=1;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	puts("");
	return 0;
}