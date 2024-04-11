#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
const ll M=1e6+5;

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
ll block;
struct Query
{
	ll l,r,id;
	bool operator <(const Query &a)const
	{
		if (l/block==a.l/block) return r<a.r;
		return l<a.l;
	}
}q[N];
ll a[N],t[M],ans[N],answer=0;
void add(ll x)
{
	x=a[x];
	answer-=t[x]*t[x]*x;
	t[x]++;
	answer+=t[x]*t[x]*x;
}
void del(ll x)
{
	x=a[x];
	answer-=t[x]*t[x]*x;
	t[x]--;
	answer+=t[x]*t[x]*x;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),m=read();
	block=sqrt(n);
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<=m;i++)
	{
		q[i].id=i;
		q[i].l=read();
		q[i].r=read();
	}
	sort(q+1,q+1+m);
	for (ll i=1,L=1,R=0;i<=m;i++)
	{
		while (L<q[i].l) del(L++);
		while (L>q[i].l) add(--L);
		while (R<q[i].r) add(++R);
		while (R>q[i].r) del(R--);
		ans[q[i].id]=answer;
	}
	for (ll i=1;i<=m;i++) print(ans[i]);

	return 0;
}