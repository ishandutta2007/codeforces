#include<bits/stdc++.h>
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
#define ll long long
using namespace std;
const ll N=1e6+5;
const ll M=1e6+5;
const ll inf=2333333333333333ll;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,val,nxt;
}e[M*2];
ll head[N],cnt=0;
void add(ll u,ll v,ll w)
{
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
bool vis[N];
ll n,m,dis[N];
ll tin[N*4],tout[N*4],cntt;
struct node
{
	ll pos,val;
	bool operator <(const node &a)const
	{
		return val>a.val;
	}
}qwq;
priority_queue<node>q;
void dijkstra(ll n,ll s)
{
	for (ll i=1;i<=cntt;i++) vis[i]=0;
	for (ll i=1;i<=cntt;i++) dis[i]=inf;
	dis[s]=0;
	while (!q.empty()) q.pop();
	q.push((node){s,0});
	while (!q.empty())
	{
		qwq=q.top();
		q.pop();
		ll now=qwq.pos;
		if (vis[now]) continue;
		vis[now]=1;
		for (ll i=head[now];i;i=e[i].nxt)
		{
			ll to=e[i].to,val=e[i].val;
			if (dis[to]>dis[now]+val)
			{
				dis[to]=dis[now]+val;
				q.push((node){to,dis[to]});
			}
		}
	}
}
void build(ll w,ll l,ll r)
{
	if (l==r) return void(tin[w]=tout[w]=l);
	build(ls,l,mid);
	build(rs,mid+1,r);
	tin[w]=++cntt;
	tout[w]=++cntt;
	add(tin[w],tin[ls],0);
	add(tin[w],tin[rs],0);
	add(tout[ls],tout[w],0);
	add(tout[rs],tout[w],0);
}
void addin(ll w,ll l,ll r,ll L,ll R,ll u,ll val)
{
	if (r<L||R<l) return;
	if (L<=l&&r<=R) return void(add(u,tin[w],val));
	addin(ls,l,mid,L,R,u,val);
	addin(rs,mid+1,r,L,R,u,val);
}
void addout(ll w,ll l,ll r,ll L,ll R,ll u,ll val)
{
	if (r<L||R<l) return;
	if (L<=l&&r<=R) return void(add(tout[w],u,val));
	addout(ls,l,mid,L,R,u,val);
	addout(rs,mid+1,r,L,R,u,val);
}

int main()
{
    memset(vis,0,sizeof(vis));
    memset(head,0,sizeof(head));
    ll n=read(),m=read(),s=read();
    cntt=n;
    build(1,1,n);
    for (ll i=1;i<=m;i++)
    {
    	ll opt=read(),u=read();
    	if (opt==1)
    	{
    		ll v=read(),w=read();
    		add(u,v,w);
		}
		if (opt==2)
		{
			ll l=read(),r=read(),w=read();
			addin(1,1,n,l,r,u,w);
		}
		if (opt==3)
		{
			ll l=read(),r=read(),w=read();
			addout(1,1,n,l,r,u,w);
		}
	}
	dijkstra(n,s);
	for (ll i=1;i<=n;i++)
	if (dis[i]<inf) print(dis[i],' ');
			   else print(-1,' ');

	return 0;
}