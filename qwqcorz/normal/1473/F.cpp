#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e3+5;
const ll inf=1LL<<60;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
namespace Flow
{
	const ll N=3e5+5;
	const ll M=13*3e3+5;
	ll n,S,T;
	struct edge
	{
		ll to,nxt,w;
	}e[M*2];
	ll head[N],cnt,cur[N];
	inline void add_edge(ll u,ll v,ll w)
	{
		e[++cnt].to=v;
		e[cnt].w=w;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	inline void add(ll u,ll v,ll w)
	{
		add_edge(u,v,w);
		add_edge(v,u,0);
	}
	ll q[N],dis[N];
	inline bool bfs()
	{
		for (ll i=0;i<=n;i++) cur[i]=head[i];
		for (ll i=0;i<=n;i++) dis[i]=-1;
		ll h=1,t=1;
		q[1]=S;
		dis[S]=0;
		while (h<=t)
		{
			ll now=q[h++];
			#define to e[i].to
			for (ll i=head[now];~i;i=e[i].nxt)
			if (e[i].w)
			if (dis[to]<0)
			{
				dis[to]=dis[now]+1;
				q[++t]=to;
			}
			#undef to
		}
		return dis[T]>=0;
	}
	ll dfs(ll now,ll flow)
	{
		if (!flow) return 0;
		if (now==T) return flow;
		ll ret=0,tmp;
		#define to e[i].to
		for (ll i=cur[now];~i;cur[now]=i=e[i].nxt)
		if (dis[to]==dis[now]+1)
		if ((tmp=dfs(to,min(flow,1LL*e[i].w))))
		{
			ret+=tmp;
			flow-=tmp;
			e[i].w-=tmp;
			e[i^1].w+=tmp;
			if (!flow) return ret;
		}
		#undef to
		return ret;
	}
	inline ll Dinic()
	{
		ll ans=0;
		while (bfs()) ans+=dfs(S,inf);
		return ans;
	}
	inline void send(ll _n,ll _S,ll _T)
	{
		cnt=-1;
		n=_n;
		S=_S;
		T=_T;
		memset(head,-1,sizeof(head));
	}
}
ll a[N],b[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read(),ans=0;
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<=n;i++) b[i]=read();
	ll S=0,T=n+1;
	Flow::send(T,S,T);
	for (ll i=1;i<=n;i++)
	if (b[i]>0) Flow::add(S,i,b[i]),ans+=b[i];
		   else Flow::add(i,T,-b[i]);
	ll id[105];
	memset(id,0,sizeof(id));
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=a[i];j++) if (a[i]%j==0&&id[j]) Flow::add(i,id[j],inf);
		id[a[i]]=i;
	}
	print(ans-Flow::Dinic());
	
	return 0;
}