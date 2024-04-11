#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int LOG=200;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int n,st[N][20],Log[N],Min,rt;
int query(int l,int r)
{
	int k=Log[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int pos(ll x){return (x-1)%n+1;}
int bel(ll x){return (x-1)/n+1;}
#define mid ((l+r)/2)
int cnt=0;
struct node
{
	int mn,tag,ls,rs;
	node(){}
	node(ll l,ll r)
	{
		ls=rs=0;
		tag=-1;
		int bl=bel(l),br=bel(r);
		if (bl==br) mn=query(pos(l),pos(r));
		else if (bl+1==br) mn=min(query(pos(l),n),query(1,pos(r)));
		else mn=Min;
	}
	void cov(int x){mn=tag=x;}
}t[N*LOG];
void push_up(int w){t[w].mn=min(t[t[w].ls].mn,t[t[w].rs].mn);}
void push_down(int w)
{
	if (t[w].tag<0||!w) return;
	if (!t[w].ls) t[w].ls=++cnt;
	if (!t[w].rs) t[w].rs=++cnt;
	t[t[w].ls].cov(t[w].tag);
	t[t[w].rs].cov(t[w].tag);
	t[w].tag=-1;
}
void cover(int &w,ll l,ll r,ll ql,ll qr,int x)
{
	if (!w) t[w=++cnt]=node(l,r);
	if (qr<l||r<ql) return;
	if (ql<=l&&r<=qr) return t[w].cov(x);
	push_down(w);
	cover(t[w].ls,l,mid,ql,qr,x);
	cover(t[w].rs,mid+1,r,ql,qr,x);
	push_up(w);
}
int query(int w,ll l,ll r,ll ql,ll qr)
{
	if (qr<l||r<ql) return 1e9+7;
	if (ql<=l&&r<=qr) return w?t[w].mn:node(l,r).mn;
	push_down(w);
	return min(query(t[w].ls,l,mid,ql,qr),query(t[w].rs,mid+1,r,ql,qr));
}
#undef mid

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read();
	ll k=n*read();
	for (int i=1;i<=n;i++) st[i][0]=read();
	for (int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
	for (int j=1;j<=17;j++)
	for (int i=1;i+(1<<j)-1<=n;i++) st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	Min=query(1,n);
	int Q=read();
	while (Q--)
	{
		ll opt=read(),l=read(),r=read(),x=opt==1?read():0;
		if (opt==1) cover(rt,1,k,l,r,x);
		if (opt==2) print(query(rt,1,k,l,r));
	}
	
	return 0;
}