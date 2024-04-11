#include<bits/stdc++.h>
#define mid ((l+r)/2)
#define ls son[w][0]
#define rs son[w][1]
#define ll long long
using namespace std;
const ll N=1e5+5;
const ll LOG=35;
const ll Max=1e9;

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
ll son[N*LOG][2];
struct node
{
	ll sum[5],tot;
	void add(ll x,ll y)
	{
		sum[1]+=x*y;
		tot+=y;
	}
}t[N*LOG];
ll cnt=0;
node operator +(const node &a,const node &b)
{
	node ret;
	ret.tot=a.tot+b.tot;
	for (ll i=0;i<5;i++) ret.sum[i]=a.sum[i];
	for (ll i=0;i<5;i++) ret.sum[(i+a.tot)%5]+=b.sum[i];
	return ret;
}
void add(ll &w,ll l,ll r,ll x,ll y)
{
	if (!w) w=++cnt;
	if (r<x||x<l) return;
	if (l==r) return t[w].add(x,y);
	add(ls,l,mid,x,y);
	add(rs,mid+1,r,x,y);
	t[w]=t[ls]+t[rs];
}

signed main(int Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll T=read(),root=0;
	while (T--)
	{
		string opt;
		cin>>opt;
		if (opt=="add") add(root,1,Max,read(),1);
		if (opt=="del") add(root,1,Max,read(),-1);
		if (opt=="sum") print(t[1].sum[3]);
	}

	return 0;
}