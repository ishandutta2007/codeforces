#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
struct KEdge
{
	int u,v,w;
	bool operator< (const KEdge& you)const{return w<you.w;}
}ke[MAXN];
struct DSU
{
	int fa[MAXN],size[MAXN];
	ll sum[MAXN];
	void init(ll* val,int n){for(int i=1;i<=n;++i)fa[i]=i,size[i]=1,sum[i]=val[i];}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	bool uni(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y)return 0;
		fa[x]=y,size[y]+=size[x],sum[y]+=sum[x];
		return 1;
	}
}dsu;
ll lim[MAXN];
int main()
{
	int n=read();
	for(int i=1;i<n;++i)ke[i].u=read(),ke[i].v=read(),ke[i].w=read();
	ll S=0;
	for(int i=1;i<=n;++i)lim[i]=read(),S+=lim[i];
	std::sort(ke+1,ke+n);
	dsu.init(lim,n);
	for(int i=1;i<n;++i)
	{
		int u=dsu.find(ke[i].u),v=dsu.find(ke[i].v);
		if(dsu.uni(u,v))
		{
			if(S-dsu.sum[v]<dsu.size[v])
			{
				printf("%d\n",ke[i].w);
				return 0;
			}
		}
	}
	puts("0");
	return 0;
}