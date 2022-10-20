#include<bits/stdc++.h>
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
#define ll long long
using namespace std;
const ll N=1e5+5;
const ll M=23;

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
ll n,q,x,a[N];
struct node
{
	ll Lcnt,Lx[M],Ly[M];
	ll Rcnt,Rx[M],Ry[M];
	ll val;
	ll ans;
	void push(ll y)
	{
		ans=y>=x;
		val=Lx[1]=Rx[1]=y;
		Lcnt=Rcnt=1;
		Ly[1]=Ry[1]=1;
	}
}t[N*4],null;
node operator +(const node &a,const node &b)
{
	node ret;
	ret.Lx[0]=ret.Rx[0]=-1;
	////////////////////val////////////////////
	ret.val=a.val|b.val;
	////////////////////ans////////////////////
	ret.ans=a.ans+b.ans;
	for (ll l=1,r=b.Lcnt,sum=0;l<=a.Rcnt;l++)
	{
		while (r&&(a.Rx[l]|b.Lx[r])>=x) sum+=b.Ly[r--];
		ret.ans+=sum*a.Ry[l];
	}
	/////////////////////L/////////////////////
	ret.Lcnt=a.Lcnt;
	for (ll i=1;i<=a.Lcnt;i++)
	{
		ret.Lx[i]=a.Lx[i];
		ret.Ly[i]=a.Ly[i];
	}
	for (ll i=1;i<=b.Lcnt;i++)
	if (ret.Lx[ret.Lcnt]==(b.Lx[i]|a.val)) ret.Ly[ret.Lcnt]+=b.Ly[i];
	else
	{
		ret.Lx[++ret.Lcnt]=b.Lx[i]|a.val;
		ret.Ly[ret.Lcnt]=b.Ly[i];
	}
	/////////////////////R/////////////////////
	ret.Rcnt=b.Rcnt;
	for (ll i=1;i<=b.Rcnt;i++)
	{
		ret.Rx[i]=b.Rx[i];
		ret.Ry[i]=b.Ry[i];
	}
	for (ll i=1;i<=a.Rcnt;i++)
	if (ret.Rx[ret.Rcnt]==(a.Rx[i]|b.val)) ret.Ry[ret.Rcnt]+=a.Ry[i];
	else
	{
		ret.Rx[++ret.Rcnt]=a.Rx[i]|b.val;
		ret.Ry[ret.Rcnt]=a.Ry[i];
	}
	return ret;
}
void build(ll w,ll l,ll r)
{
	if (l==r) return t[w].push(a[l]);
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
//	print(l,' ');
//	print(r,':');
//	print(t[w].ans);
//	for (ll i=1;i<=t[w].Lcnt;i++) print(t[w].Lx[i],' ');puts("");
//	for (ll i=1;i<=t[w].Lcnt;i++) print(t[w].Ly[i],' ');puts("");
//	for (ll i=1;i<=t[w].Rcnt;i++) print(t[w].Rx[i],' ');puts("");
//	for (ll i=1;i<=t[w].Rcnt;i++) print(t[w].Ry[i],' ');puts("");
//	puts("");
}
void change(ll w,ll l,ll r,ll x,ll y)
{
	if (l==r) return t[w].push(y);
	if (x<=mid) change(ls,l,mid,x,y);
		   else change(rs,mid+1,r,x,y);
	t[w]=t[ls]+t[rs];
}
node query(ll w,ll l,ll r,ll L,ll R)
{
	if (r<L||R<l) return null;
	if (L<=l&&r<=R) return t[w];
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}

int main()
{
	memset(t,0,sizeof(t));
	n=read();
	q=read();
	x=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for (ll i=1;i<=q;i++)
	{
		ll opt=read(),x=read(),y=read();
		if (opt==1) change(1,1,n,x,y);
		if (opt==2) print(query(1,1,n,x,y).ans);
	}

	return 0;
}