#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1.5e5+5;

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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,nxt;
}e[N*2];
ll head[N],cnt=0;
void add(ll u,ll v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
bool vis[N];
ll a[N],tot,ans=0;
ll Max[N],siz[N],num,root;
void findroot(ll now,ll father)
{
	Max[now]=0;
	siz[now]=1;
	for (ll i=head[now];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if (to==father||vis[to]) continue;
		findroot(to,now);
		siz[now]+=siz[to];
		Max[now]=max(Max[now],siz[to]);
	}
	Max[now]=max(Max[now],num-siz[now]);
	if (Max[now]<=num/2) root=now;
}
ll st[N],top;
struct node
{
	ll len,sum0,sum1,sum2;
};
vector<node>c[N];
void dfs(ll t,ll now,ll father,ll len,ll sum0,ll sum1,ll sum2,ll val,bool flag)
{
	c[t].push_back((node){len,sum0,sum1,sum2});
	if (flag) return dfs(t,now,father,len+1,sum0+sum1+a[now]+val,sum1+a[now],sum2+a[now]*len,val,0);
	for (ll i=head[now];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if (to==father||vis[to]) continue;
		dfs(t,to,now,len+1,sum0+sum1+a[to]+val,sum1+a[to],sum2+a[to]*len,val,0);
	}
}
ll k[N],b[N],cntl=0;
ll t[N*4];
#define mid ((l+r)/2)
#define ls (w*2)
#define rs (w*2+1)
bool cmp(ll u,ll v,ll x)
{
	return k[u]*x+b[u]>k[v]*x+b[v];
}
void insert(ll w,ll l,ll r,ll x)
{
	if (!t[w]) return void(t[w]=x);
	if (cmp(x,t[w],mid)) swap(t[w],x);
	if (l==r) return;
	if (cmp(x,t[w],l)) insert(ls,l,mid,x);
	if (cmp(x,t[w],r)) insert(rs,mid+1,r,x);
}
ll query(ll w,ll l,ll r,ll x)
{
//	print(k[t[w]],' ');
//	print(b[t[w]]);
//	print(x);
	if (l==r) return k[t[w]]*x+b[t[w]];
	if (x<=mid) return max(k[t[w]]*x+b[t[w]],query(ls,l,mid,x));
		   else return max(k[t[w]]*x+b[t[w]],query(rs,mid+1,r,x));
}

void solve(ll now)
{
//	print(now);
	vis[now]=1;
	top=tot=0;
	for (ll i=head[now];i;i=e[i].nxt) if (!vis[e[i].to]) st[++top]=e[i].to;
	if (top==0) return;
	for (ll i=1;i<=top+1;i++) c[i].clear();
	for (ll i=1;i<=top;i++) dfs(i,st[i],now,1,a[now],0,0,a[now],1);
	if (top==1) c[++top].push_back((node){1,a[now],0,0});
	cntl=0;
	for (ll i=1;i<=num*4;i++) t[i]=0;
	for (ll i=1;i<=top;i++)
	{
//		for (ll j=0;j<(ll)c[i].size();j++)
//		{
//			print(c[i][j].len,' ');
//			print(c[i][j].sum0,' ');
//			print(c[i][j].sum1,' ');
//			print(c[i][j].sum2);
//		}
//		puts("-------------------------");
		for (ll j=0;j<(ll)c[i].size();j++) ans=max(ans,query(1,1,num,c[i][j].len)+c[i][j].sum0)/*,puts("")*/;
		for (ll j=1;j<(ll)c[i].size();j++)
		{
			cntl++;
			k[cntl]=c[i][j].sum1;
			b[cntl]=c[i][j].sum2;
			insert(1,1,num,cntl);
		}
	}
	cntl=0;
	for (ll i=1;i<=num*4;i++) t[i]=0;
	for (ll i=top;i>=1;i--)
	{
		for (ll j=0;j<(ll)c[i].size();j++) ans=max(ans,query(1,1,num,c[i][j].len)+c[i][j].sum0);
		for (ll j=1;j<(ll)c[i].size();j++)
		{
			cntl++;
			k[cntl]=c[i][j].sum1;
			b[cntl]=c[i][j].sum2;
			insert(1,1,num,cntl);
		}
	}
	for (ll i=head[now];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if (vis[to]) continue;
		findroot(to,0);
		num=siz[to];
		root=0;
		findroot(to,0);
		solve(root);
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=num=read();
	for (ll i=1;i<n;i++)
	{
		ll u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for (ll i=1;i<=n;i++) a[i]=read();
	findroot(1,0);
	solve(root);
	print(ans);

	return 0;
}