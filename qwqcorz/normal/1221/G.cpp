#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=45;
const ll S=1LL<<20;

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
ll e[N],fa[N],siz[N],n,m,cnt=0,cnt2=0;
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(ll x,ll y)
{
	if ((x=find(x))==(y=find(y))) return;
	siz[y]+=siz[x];
	fa[x]=y;
}
ll vis[N];
bool dfs(ll now,ll x)
{
	vis[now]=x;
	for (ll i=0;i<n;i++)
	if ((e[now]>>i)&1)
	{
		if (!~vis[i]) {if (!dfs(i,!x)) return 0;}
		else if (x==vis[i]) return 0;
	}
	return 1;
}
bool check()
{
	for (ll i=0;i<n;i++)
	if (!~vis[i]&&!dfs(i,0))
	return 0;
	return 1;
}
ll ans=-1,sum[S];
bool check(ll s,ll l,ll r)
{
	s<<=l;
	for (ll i=l;i<r;i++) if (((s>>i)&1)&&(e[i]&s)) return 0;
	return 1;
}
ll get(ll s,ll l,ll r)
{
	s<<=l;
	ll ret=0;
	for (ll i=l;i<r;i++) if ((s>>i)&1) ret|=e[i];
	return ~ret&((1LL<<l)-1);
}
void dfs0(ll l,ll r)
{
	ll m=r-l;
	for (ll i=0;i<(1LL<<m);i++) if (check(i,l,r)) sum[i]=1;
}
void dfs1(ll l,ll r)
{
	ll m=r-l;
	for (ll i=0;i<(1LL<<m);i++) if (check(i,l,r)) ans+=sum[get(i,l,r)];
}
ll solve()
{
	if (~ans) return ans;
	ans=0;
	dfs0(0,n/2);
	for (ll j=0;j<n/2;j++)
	for (ll i=0;i<(1LL<<(n/2));i++)
	if ((i>>j)&1) sum[i]+=sum[i^(1LL<<j)];
	dfs1(n/2,n);
	return ans;
}
ll calc(){return 1LL<<n;}
ll calc0(){return solve();}
ll calc1(){return 1LL<<cnt;}
ll calc2(){return solve();}
ll calc01(){return 1LL<<cnt2;}
ll calc02(){memset(vis,-1,sizeof(vis)); return check()?(1LL<<cnt):0;}
ll calc12(){return 1LL<<cnt2;}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),m=read();
	if (!m) return puts("0"),0;
	for (ll i=0;i<n;i++) fa[i]=i,siz[i]=1;
	for (ll i=0;i<m;i++)
	{
		ll u=read()-1,v=read()-1;
		e[u]|=1LL<<v;
		e[v]|=1LL<<u;
		merge(u,v);
	}
	for (ll i=0;i<n;i++) if (fa[i]==i) cnt++;
	for (ll i=0;i<n;i++) if (fa[i]==i&&siz[i]==1) cnt2++;
//	printf("<>%lld\n",calc());
//	printf("<0>%lld\n",calc0());
//	printf("<1>%lld\n",calc1());
//	printf("<2>%lld\n",calc2());
//	printf("<01>%lld\n",calc01());
//	printf("<02>%lld\n",calc02());
//	printf("<12>%lld\n",calc12());
	print(calc()-calc0()-calc1()-calc2()+calc01()+calc02()+calc12());
	
	return 0;
}