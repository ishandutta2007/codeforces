#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int B=1e3;

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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct Query
{
	int l,r,t,k,id;
	bool operator <(const Query &a)const
	{
		if (l/B!=a.l/B) return l<a.l;
		if (r/B!=a.r/B) return r<a.r;
		return ((r/B)&1)?t<a.t:t>a.t;
	}
}q[N];
struct Change
{
	int x,y;
}c[N];
int cnt[N],tot[N],lw[N],rw[N],a[N],ans[N];
void insert(int l,int x)
{
	int r=rw[l];
	lw[x]=l,rw[x]=r;
	rw[l]=x,lw[r]=x;
}
void erase(int x)
{
	lw[rw[x]]=lw[x];
	rw[lw[x]]=rw[x];
	lw[x]=rw[x]=0;
}
void change(int x,int y)
{
	if (!tot[x+y]++) insert(y>0?x:lw[x],x+y);
	if (!--tot[x]) erase(x);
	x+=y;
}
void add(int x)
{
//	putchar('+'),print(x);
	change(cnt[x],1);
	cnt[x]++;
}
void del(int x)
{
//	putchar('-'),print(x);
	change(cnt[x],-1);
	cnt[x]--;
}
void work(int l,int r,int k)
{
	if (l<=c[k].x&&c[k].x<=r)
	{
		del(a[c[k].x]);
		add(c[k].y);
	}
	swap(a[c[k].x],c[k].y);
}
int query(int k)
{
	int ret=N,sum=0;
	for (int i=rw[0],j=i;i;i=rw[i])
	{
		sum+=tot[i];
		while (sum-tot[j]>=k) sum-=tot[j],j=rw[j];
		if (sum>=k) ret=min(ret,i-j);
	}
	return ret<N?ret:-1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	tot[0]=N;
	int n=read(),m=read(),cntc=0,cntq=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++)
	{
		int opt=read(),x=read(),y=read(),k=opt==1?read():0;
		if (opt==1) cntq++,q[cntq]=(Query){x,y,cntc,k,cntq};
			   else c[++cntc]=(Change){x,y};
	}
	sort(q+1,q+1+cntq);
	for (int i=1,l=1,r=0,t=0;i<=cntq;i++)
	{
		while (l>q[i].l) add(a[--l]);
		while (r<q[i].r) add(a[++r]);
		while (l<q[i].l) del(a[l++]);
		while (r>q[i].r) del(a[r--]);
		while (t<q[i].t) work(l,r,++t);
		while (t>q[i].t) work(l,r,t--);
//		print(l,','),print(r,' '),print(t);
		ans[q[i].id]=query(q[i].k);
	}
	for (int i=1;i<=cntq;i++) print(ans[i]);
	
	return 0;
}