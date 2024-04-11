#include<bits/stdc++.h>
#define ls t[w].Ls
#define rs t[w].Rs
#define mid ((l+r)>>1)
#define ll long long
using namespace std;
const int N=1e5+5;
const ll Add=998244353;
const ll Mod=1919810111;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	int Ls,Rs;
	int L,R;
	ll hL,hR;
	bool check()
	{
		return L==0&&R==0;
	}
	void push(int x)
	{
		if (x>0)
		{
			R=1;
			hR=x+Add;
			L=hL=0;
		}
		else
		{
			L=1;
			hL=Add-x;
			R=hR=0;
		}
	}
	bool operator ==(const node &a)const
	{
		return L==a.L&&R==a.R;
	}
}t[N*4+233],Error={0,0,-1,-1,0,0};
int a[N],cnt;
ll Pow[N];
ll getL(int w,int len)
{
	if (len==0) return 0;
	if (len==t[w].L) return t[w].hL;
	if (len<=t[ls].L) return getL(ls,len);
	else return (t[ls].hL*Pow[len-t[ls].L]%Mod+getL(rs,t[ls].R+len-t[ls].L)-t[ls].hR*Pow[len-t[ls].L]%Mod+Mod)%Mod;
}
ll getR(int w,int len)
{
	if (len==0) return 0;
	if (len==t[w].R) return t[w].hR;
	if (len<=t[rs].R) return getR(rs,len);
	else return (t[rs].hR*Pow[len-t[rs].R]%Mod+getR(ls,t[rs].L+len-t[rs].R)-t[rs].hL*Pow[len-t[rs].R]%Mod+Mod)%Mod;
}
void push_up(int w,int Ls,int Rs)
{
	ls=Ls;
	rs=Rs;
	if (t[Ls]==Error) return (void)(t[w]=Error,ls=Ls,rs=Rs);
	if (t[Rs]==Error) return (void)(t[w]=Error,ls=Ls,rs=Rs);
	if (t[Ls].R<=t[Rs].L)
	{
		ll hash=getL(Rs,t[Ls].R);
		if (hash!=t[Ls].hR) t[w]=Error,ls=Ls,rs=Rs;
		else
		{
			t[w].L=t[Ls].L+t[Rs].L-t[Ls].R;
			t[w].hL=(t[Ls].hL*Pow[t[Rs].L-t[Ls].R]%Mod+t[Rs].hL-hash*Pow[t[Rs].L-t[Ls].R]%Mod+Mod)%Mod;
			t[w].R=t[Rs].R;
			t[w].hR=t[Rs].hR;
		}
	}
	else
	{
		ll hash=getR(Ls,t[Rs].L);
		if (hash!=t[Rs].hL) t[w]=Error,ls=Ls,rs=Rs;
		else
		{
			t[w].R=t[Rs].R+t[Ls].R-t[Rs].L;
			t[w].hR=(t[Rs].hR*Pow[t[Ls].R-t[Rs].L]%Mod+t[Ls].hR-hash*Pow[t[Ls].R-t[Rs].L]%Mod+Mod)%Mod;
			t[w].L=t[Ls].L;
			t[w].hL=t[Ls].hL;
		}
	}
}
void build(int w,int l,int r)
{
	if (l==r) return t[w].push(a[l]);
	ls=w<<1;
	rs=w<<1|1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(w,ls,rs);
}
void change(int w,int l,int r,int x,int y)
{
	if (l==r) return t[w].push(y);
	if (x<=mid) change(ls,l,mid,x,y);
		   else change(rs,mid+1,r,x,y);
	push_up(w,ls,rs);
}
int query(int w,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return w;
	if (R<=mid) return query(ls,l,mid,L,R);
	if (mid<L) return query(rs,mid+1,r,L,R);
	push_up(++cnt,query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
	return cnt;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),k=read()+1;
	for (int i=Pow[0]=1;i<=n;i++) Pow[i]=Pow[i-1]*k%Mod;
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	int Q=read();
	while (Q--)
	{
		cnt=N*4;
		int opt=read(),x=read(),y=read();
		if (opt==1) change(1,1,n,x,y);
		if (opt==2) puts(t[query(1,1,n,x,y)].check()?"Yes":"No");
	}

	return 0;
}