#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<random>
#include<chrono>
#include<ctime>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 1500011,INF = 1e9+233;
bool used[MAXN];
namespace LCT
{
	int fa[MAXN],son[MAXN][2],val[MAXN],mx[MAXN],tag[MAXN],T[MAXN],minT[MAXN];
	bool rev[MAXN];
	bool not_root(int x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
	void pushup(int x){mx[x]=max(max(val[x],mx[son[x][0]]),mx[son[x][1]]),minT[x]=min(min(T[x],minT[son[x][0]]),minT[son[x][1]]);}
	void pushdown(int x)
	{
		int &l=son[x][0],&r=son[x][1];
		if(rev[x])std::swap(l,r),rev[l]^=1,rev[r]^=1,rev[x]=0;
		if(tag[x]&&l)val[l]+=tag[x],mx[l]+=tag[x],tag[l]+=tag[x];
		if(tag[x]&&r)val[r]+=tag[x],mx[r]+=tag[x],tag[r]+=tag[x];
		tag[x]=0;
	}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y],k=(son[y][1]==x);
		if(not_root(y))son[z][son[z][1]==y]=x;
		fa[x]=z;
		son[y][k]=son[x][!k],fa[son[x][!k]]=y;
		son[x][!k]=y,fa[y]=x;
		pushup(y),pushup(x);
	}
	int s[MAXN];
	void splay(int x)
	{
		int top=0;
		s[++top]=x;
		for(int y=x;not_root(y);y=fa[y])s[++top]=fa[y];
		while(top)pushdown(s[top--]);
		while(not_root(x))
		{
			int y=fa[x];
			if(not_root(y))rotate((son[y][1]==x)==(son[fa[y]][1]==y)?y:x);
			rotate(x);
		}
		pushup(x);
	}
	void access(int x)
	{
		for(int y=0;x;y=x,x=fa[x])
			splay(x),son[x][1]=y,pushup(x);
	}
	void make_root(int x){access(x),splay(x),rev[x]^=1;}
	void link(int x,int y){make_root(x),fa[x]=y;}
	void split(int x,int y)
	{
		make_root(x),access(y),splay(y);
	}
	int get_root(int x)
	{
		access(x),splay(x);
		while(son[x][0])x=son[x][0];
		return x;
	}
	int Qmax(int x,int y)
	{
		if(get_root(x)!=get_root(y))return -INF;
		split(x,y);
		return mx[y];
	}
	void Add(int x,int y,int k){split(x,y),val[y]+=k,mx[y]+=k,tag[y]+=k;}
	int Find(int x,int k)
	{
		if(T[x]==k)return x;
		if(minT[son[x][0]]==k)return Find(son[x][0],k);
		return Find(son[x][1],k);
	}
	int replace(int x,int y,int k)
	{
		if(get_root(x)!=get_root(y))
		{
			T[k]=k,used[k]=1;
			link(x,k),link(y,k);
			splay(k);
			return 0;
		}
		split(x,y);
		int p=minT[y];
		splay(p),fa[son[p][0]]=fa[son[p][1]]=0,son[p][0]=son[p][1]=0;
		used[p]=0,used[k]=1,T[k]=k;
		link(x,k),link(y,k);
		return p;
	}
	void cut(int x,int y)
	{
		split(x,y);
		fa[x]=0,son[y][0]=0,pushup(y);
	}
}
pii ed[MAXN];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;++i)ed[i].first=read(),ed[i].second=read();
	for(int i=0;i<=n;++i)LCT::T[i]=INF,LCT::minT[i]=INF,LCT::val[i]=-INF,LCT::mx[i]=-INF;
	ll ans=0;
	int r=1;
	for(int l=1;l<=m;++l)
	{
		while(r<=m&&LCT::Qmax(ed[r].first,ed[r].second)<=0)
		{
			int p=LCT::replace(ed[r].first,ed[r].second,n+r);
			if(p)
				LCT::Add(ed[p-n].first,ed[p-n].second,1);
			++r;
		}
		ans+=r-l;
		if(used[n+l])
		{
			LCT::cut(ed[l].first,n+l),LCT::cut(ed[l].second,n+l);
		}
		else LCT::Add(ed[l].first,ed[l].second,-1);
	}
	printf("%lld\n",ans);
	return 0;
}