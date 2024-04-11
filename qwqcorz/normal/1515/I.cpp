#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
const ll M=20;
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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct diamond
{
	ll t,w,v,id;
	bool operator <(const diamond &a)const
	{
		return v==a.v?w<a.w:v>a.v;
	}
}a[N];
ll pos[N],lg;
void fit(ll c,ll &lg)
{
	while (lg>1&&(1<<(lg-2))>c) lg--;
}
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
struct node
{
	ll w1[M],v1[M],w2[M];
	node(diamond x=(diamond){0,0,0,0})
	{
		for (ll i=1;i<20;i++)
		{
			w1[i]=v1[i]=0,w2[i]=inf;
			if (x.w<(1<<(i-1))) w1[i]=x.w*x.t,v1[i]=x.v*x.t;
			else if (x.w<(1<<i)) w2[i]=min(x.t,1LL)*x.w;
		}
	}
}t[N*4];
node operator +(const node &a,const node &b)
{
	node ret;
	for (ll i=1;i<20;i++)
	{
		ret.w1[i]=a.w1[i]+b.w1[i];
		ret.v1[i]=a.v1[i]+b.v1[i];
		ret.w2[i]=min(a.w2[i],a.w1[i]+b.w2[i]);
	}
	return ret;
}
void fix(ll w,ll l,ll r,ll x)
{
	if (l==r) return void(t[w]=node(a[x]));
	if (x<=mid) fix(ls,l,mid,x);
		   else fix(rs,mid+1,r,x);
	t[w]=t[ls]+t[rs];
}
ll query(ll w,ll l,ll r,ll &c)
{
	if (l==r)
	{
		ll ret=min(c/a[l].w,a[l].t)*a[l].v;
		fit(c-=min(c/a[l].w,a[l].t)*a[l].w,lg);
		return ret;
	}
	if (t[w].w1[lg]<=c)
	{
		ll ret=t[w].v1[lg];
		fit(c-=t[w].w1[lg],lg);
		return ret;
	}
	if (t[w].w2[lg-1]>c&&t[w].w1[lg-1]<=c)
	{
		ll ret=t[w].v1[lg-1];
		fit(c-=t[w].w1[lg-1],lg);
		return ret;
	}
	return query(ls,l,mid,c)+query(rs,mid+1,r,c);
}
#undef ls
#undef rs
#undef mid

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read(),m=read();
	for (ll i=1;i<=n;i++) a[i].t=read(),a[i].w=read(),a[i].v=read(),a[i].id=i;
	sort(a+1,a+1+n);
	for (ll i=1;i<=n;i++) pos[a[i].id]=i;
	for (ll i=1;i<=n;i++) fix(1,1,n,i);
	for (ll i=1;i<=m;i++)
	{
		ll opt=read(),c=read(),d=opt<=2?read():0;
		if (opt<=2)
		{
			a[pos[d]].t+=opt==1?c:-c;
			fix(1,1,n,pos[d]);
		}
		else fit(c,lg=19),print(query(1,1,n,c));
	}
	
	return 0;
}