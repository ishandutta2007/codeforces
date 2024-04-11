



#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
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
std::vector<int>tree[MAXN];
int mod,base,rm;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
int h[MAXN],pw[MAXN],Ipw[MAXN], a[MAXN];
int dep[MAXN];
int f[MAXN],g[MAXN];

bool del[MAXN];
int Q[MAXN],pre[MAXN],size[MAXN],ms[MAXN];
int get_cen(int s)
{
	int h=0,t=0;
	Q[t++]=s;
	while(h<t)
	{
		int u=Q[h++];
		size[u]=1,ms[u]=0;
		for(auto v:tree[u])
			if(!del[v]&&v!=pre[u])pre[v]=u,Q[t++]=v;
	}
	for(int i=t-1;i;--i)
	{
		int u=Q[i];
		size[pre[u]]+=size[u];
		if(size[u]>size[ms[pre[u]]])ms[pre[u]]=u;
		pre[u]=0;
	}
	pre[s]=0;
	int all=size[s];
	while(size[ms[s]]*2>all)s=ms[s];
	return s;
}
std::vector<int>nodes[MAXN];
int up[MAXN],down[MAXN],pos[MAXN];
int tag[MAXN],cnt[MAXN];
int fx[MAXN],diff=0;
int place(int val){return std::lower_bound(fx+1,fx+diff+1,val)-fx;}
void bfs(int s,int r,int pre_up,int pre_down)
{
	nodes[r].clear();
	int h=0,t=0;
	Q[t++]=s,up[s]=(ll(pre_up)*base+a[s])%mod,down[s]=(pre_down+ll(pw[1])*a[s])%mod;
	dep[s]=1;
	while(h<t)
	{
		int u=Q[h++];
		fx[++diff]=down[u];
		nodes[r].emplace_back(u);
		for(auto v:tree[u])
			if(!del[v]&&v!=pre[u])
			{
				dep[v]=dep[u]+1,pre[v]=u;
				up[v]=(ll(up[u])*base+a[v])%mod;
				down[v]=(down[u]+ll(pw[dep[v]])*a[v])%mod;
				Q[t++]=v;
			}
	}
	for(int i=t-1;i>=0;--i)pre[Q[i]]=0;
}
void Solve(int s)
{
	s=get_cen(s);
	del[s]=1;
	//printf("del s=%d\n",s);
	int cur=1;
	nodes[1].clear(),nodes[1].emplace_back(s);
	up[s]=0,dep[s]=0,down[s]=a[s];
	diff=0,fx[++diff]=a[s];
	for(auto v:tree[s])
		if(!del[v])nodes[++cur].clear(),bfs(v,cur,0,a[s]);
	std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
	for(int x=1;x<=diff;++x)tag[x]=cnt[x]=0;
	for(int i=1;i<=cur;++i)
		for(auto u:nodes[i])pos[u]=place(down[u]);
	for(int i=1;i<=cur;++i)
	{
		//printf("new subtree %d:\n",i);
		for(auto u:nodes[i])
		{
			int v=(rm-up[u]+mod)%mod;
			v=ll(v)*Ipw[dep[u]]%mod;
			int p=place(v);
			//printf("u=%d,ask for v=%d(p=%d)\n",u,v,p);
			if(p<=diff&&fx[p]==v)g[u]+=cnt[p],++tag[p];
		}
		for(auto u:nodes[i])
		{
			int p=pos[u];
			//printf("u=%d,down=%d(p=%d)\n",u,down[u],p);
			f[u]-=tag[p],++cnt[p];
		}
	}
	for(int i=1;i<=cur;++i)
		for(auto u:nodes[i])
			f[u]+=tag[pos[u]];
	for(int x=1;x<=diff;++x)tag[x]=cnt[x]=0;
	for(int i=cur;i;--i)
	{
		//printf("new subtree %d:\n",i);
		for(auto u:nodes[i])
		{
			int v=(rm-up[u]+mod)%mod;
			v=ll(v)*Ipw[dep[u]]%mod;
			int p=place(v);
			//printf("u=%d,ask for v=%d(p=%d)\n",u,v,p);
			if(p<=diff&&fx[p]==v)g[u]+=cnt[p],++tag[p];
		}
		for(auto u:nodes[i])
		{
			int p=pos[u];
			//printf("u=%d,down=%d(p=%d)\n",u,down[u],p);
			f[u]-=tag[p],++cnt[p];
		}
	}
	for(int i=cur;i;--i)
		for(auto u:nodes[i])
			f[u]+=tag[pos[u]];
	for(int x=1;x<=diff;++x)tag[x]=cnt[x]=0;
	if(rm==a[s])++f[s],++g[s];//,printf("add %d self\n",s);
	for(auto v:tree[s])
		if(!del[v])Solve(v);
}
int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	int n=read();
	mod=read(),base=read(),rm=read();
	pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=ll(pw[i-1])*base%mod;
	int Ib=Qpow(base,mod-2);
	Ipw[0]=1;
	for(int i=1;i<=n;++i)Ipw[i]=ll(Ipw[i-1])*Ib%mod;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<n;++i){int u=read(),v=read();tree[u].emplace_back(v),tree[v].emplace_back(u); }
	Solve(1);
	ll ans=ll(n)*n*n;
	for(int u=1;u<=n;++u)
	{
		ans-=ll(f[u])*n*3;
		ans+=ll(f[u])*f[u]+ll(f[u])*g[u]+ll(g[u])*g[u];
	}
	printf("%lld\n",ans);
	return 0;
}