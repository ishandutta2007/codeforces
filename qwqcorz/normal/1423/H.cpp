#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct Query
{
	int opt,x,y;
}q[N];
vector<int>t[N*4],a[N];
int lst[N],ans[N];
int fa[N],siz[N],st[N],top=0;
int find(int x){return x==fa[x]?x:find(fa[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return;
	if (siz[x]>siz[y]) swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
	st[++top]=x;
}
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
void add(int w,int l,int r,int ql,int qr,int x)
{
	if (qr<l||r<ql) return;
	if (ql<=l&&r<=qr) return void(t[w].push_back(x));
	add(ls,l,mid,ql,qr,x);
	add(rs,mid+1,r,ql,qr,x);
}
void solve(int w,int l,int r)
{
	int tmp=top;
	for (int i:t[w]) merge(q[i].x,q[i].y);
	if (l<r)
		solve(ls,l,mid),
		solve(rs,mid+1,r);
	else if (q[l].opt==2) print(siz[find(q[l].x)]);
	while (top>tmp)
	{
		int x=st[top--];
		siz[fa[x]]-=siz[x];
		fa[x]=x;
	}
}
#undef mid
#undef rs
#undef ls

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),Q=read(),k=read(),day=1;
	for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for (int i=1;i<=Q;i++)
	{
		q[i].opt=read();
		if (q[i].opt==1)
		{
			q[i].x=read(),q[i].y=read();
			a[day].push_back(i);
		}
		if (q[i].opt==2) q[i].x=read();
		if (q[i].opt==3) lst[day++]=i;
	}
	lst[day]=Q;
	for (int i=1;i<=day;i++)
	{
		int fin=lst[min(i+k-1,day)];
		for (int j:a[i]) add(1,1,Q,j,fin,j);
	}
	solve(1,1,Q);
	
	return 0;
}