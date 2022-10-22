#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef __int128 I128;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}
#define from(u) for(int i=last[u],v=e[i].v,w=e[i].w;i;i=e[i].nxt,v=e[i].v,w=e[i].w)
int Q[MAXN],size[MAXN],ms[MAXN], pre[MAXN],mod;
int pw[MAXN];
bool vis[MAXN];
int get_cen(int s)
{
	int h=0,t=0;
	Q[t++]=s;
	while(h<t)
	{
		int u=Q[h++];
		size[u]=1,ms[u]=0;
		from(u)
			if(!vis[v]&&v!=pre[u])pre[v]=u,Q[t++]=v;
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
std::map<int,int> f;
void exgcd(int a,int b,int& x,int& y)
{
	if(!b){x=1,y=0;return;}
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
ll ans=0;
void calc(int u,int fa,int h,int dep)
{
	int x,y;
	exgcd(pw[dep],mod,x,y);
	x=(ll(-x)*h%mod+mod)%mod;
	ans+=f[x];
	from(u)
		if(!vis[v]&&v!=fa)calc(v,u,(h*10ll+w)%mod,dep+1);
}
void push(int u,int fa,int h,int dep)
{
	++f[h];
	from(u)
		if(!vis[v]&&v!=fa)push(v,u,(h+ll(w)*pw[dep])%mod,dep+1);
}
void solve(int u)
{
	u=get_cen(u);
	vis[u]=1;
	f.clear();
	std::vector<pii>seq;
	from(u)
		if(!vis[v])calc(v,u,w,1),push(v,u,w,1),seq.push_back(pii(v,w));
	ans+=f[0];
	f.clear(),++f[0];
	std::reverse(seq.begin(),seq.end());
	for(auto x:seq)calc(x.first,u,x.second,1),push(x.first,u,x.second,1);
	for(auto x:seq)solve(x.first);
}
int main()
{
	int n=read();
	mod=read();
	for(int i=1;i<n;++i){int u=read()+1,v=read()+1,w=read()%mod;adde(u,v,w),adde(v,u,w);}
	pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=ll(pw[i-1])*10%mod;
	solve(1);
	printf("%lld\n",ans);
	return 0;
}