#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll t){if(a<t)return a=t,1;return 0;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
/**********/
const int MAXN = 500011;
struct DSU
{
	int fa[MAXN],size[MAXN],s[MAXN],top=0;
	bool d[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i,size[i]=1,d[i]=1;}
	int find(int x)
	{
		while(fa[x]!=x)x=fa[x];
		return x;
	}
	bool getdep(int x)
	{
		bool res=0;
		while(fa[x]!=x)res^=d[x],x=fa[x];
		return res;
	}
	bool uni(int x,int y)
	{
		int rx=find(x),ry=find(y);
		if(rx==ry)
		{
			return !(getdep(x)^getdep(y));
		}
		if(size[rx]<size[ry])d[rx]=getdep(x)^getdep(y)^1,fa[rx]=ry,size[ry]+=size[rx],s[++top]=rx;
		else d[ry]=getdep(x)^getdep(y)^1,fa[ry]=rx,size[rx]+=size[ry],s[++top]=ry;
		return 0;
	}
	void back(int t)
	{
		while(top>t)
		{
			int u=s[top--];
			size[fa[u]]-=size[u],fa[u]=u;
		}
	}
}s[51];
int n,m,k,Q;
pii a[MAXN],c[MAXN];
int lst[MAXN],ed[MAXN],now[MAXN];
int pre[31][51];
namespace sgt
{
	std::vector<int>t[MAXN<<2|1];
#define rt t[num]
	void modify(un ql,un qr,int x,un l=1,un r=Q,un num=1)
	{
		if(ql>qr)return;
		if(ql<=l&&r<=qr){rt.push_back(x);return;}
		un mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,x,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,x,mid+1,r,num<<1|1);
	}
	void solve(un l=1,un r=Q,un num=1,un dep=0)
	{
		for(int i=1;i<=k;++i)pre[dep][i]=s[i].top;
		for(auto id:rt)
		{
			pii x=c[id];
			if(s[x.second].uni(a[x.first].first,a[x.first].second)){std::cerr<<"ERR!";puts("ERR!!!");exit(-5);}
		}
		if(l==r)
		{
			pii x=c[l];
			if(s[x.second].uni(a[x.first].first,a[x.first].second))
			{
				if(now[x.first])modify(l+1,ed[l],now[x.first]);
				puts("NO");
			}
			else now[x.first]=l,modify(l+1,ed[l],l),puts("YES");
			for(int i=1;i<=k;++i)s[i].back(pre[dep][i]);
			return;
		}
		un mid=(l+r)>>1;
		solve(l,mid,num<<1,dep+1),solve(mid+1,r,num<<1|1,dep+1);
		for(int i=1;i<=k;++i)s[i].back(pre[dep][i]);
	}
}
int main()
{
	n=read(),m=read(),k=read(),Q=read();
	for(int i=1;i<=k;++i)s[i].init(n);
	for(int i=1;i<=m;++i)a[i].first=read(),a[i].second=read();
	for(int i=1;i<=Q;++i)
	{
		int id=read(),color=read();
		if(lst[id])ed[lst[id]]=i-1;
		lst[id]=i;
		c[i]=pii(id,color);
	}
	for(int i=1;i<=Q;++i)
		if(!ed[i])ed[i]=Q;
	sgt::solve();
	return 0;
}