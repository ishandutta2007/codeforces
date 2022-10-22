#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
const int MAXN = 400011;
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}
pii a[MAXN];
bool vis[MAXN];
int T[MAXN],cur;
int X,res[MAXN];
bool only=0;
void dfs1(int u)
{
	vis[u]=1;
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		pii f(-a[u].first,w-a[u].second);
		if(!vis[v])a[v]=f,dfs1(v);
		else if(vis[v]&&a[v]!=f)
		{
			if(a[v].first==f.first)
			{
				puts("NO");exit(0);
			}
			only=1,X=(a[v].second-f.second)/(f.first-a[v].first);
		}
	}
}
void dfs2(int u,ll& S)
{
	S+=abs(res[u]);
	T[u]=cur;
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(T[v]!=cur)res[v]=w-res[u],dfs2(v,S);
		else if((res[v]-(w-res[u]))!=0)
		{
			puts("NO");exit(0);
		}
	}
}
int main()
{
	int n=read(),m=read();
	while(m--){int u=read(),v=read(),w=read()<<1;adde(u,v,w),adde(v,u,w);}
	ll ans=0;
	for(int u=1;u<=n;++u)
		if(!vis[u])
		{
			ll S=0;
			only=0,a[u].first=1,a[u].second=0,dfs1(u);
			if(only)
			{
				++cur,res[u]=X,dfs2(u,S),ans+=S;
			}
			else
			{
				int l=-4e5,r=4e5;
				//double l=-5,r=5;
				while(r-l>5)
				{
					int lm=(l+r)/2-1,rm=(l+r)/2+1;
					ll lf=0,rf=0;
					++cur,res[u]=lm,dfs2(u,lf);
					++cur,res[u]=rm,dfs2(u,rf);
					if(lf<rf)r=rm;
					else l=lm;
				}
				ll S = 1e18;
				int best=0;
				for(int i=l;i<=r;++i)
				{
					ll f=0;
					++cur,res[u]=i,dfs2(u,f);
					if(umin(S,f))best=i;
				}
				S=0;
				++cur,res[u]=best,dfs2(u,S);
			}
		}
	puts("YES");
	for(int u=1;u<=n;++u)
	{
		if(res[u]<0)putchar('-'),res[u]=-res[u];
		if(res[u]&1)printf("%d.5 ",(res[u]/2));
		else printf("%d ",(res[u]/2));
	}
	puts("");
	return 0;
}