#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
struct bit
{
	int t[N],n;
	void add(int x){/*putchar('A'),print(x);*/for (;x<=n;x+=x&-x) t[x]++;}
	int query(int x){/*putchar('Q'),print(x,':');*/int ret=0;for (;x;x&=x-1) ret+=t[x];/*print(ret);*/return ret;}
}t;
struct node
{
	int id,x,y;
	bool operator <(const node &a)const
	{
		return make_pair(x,y)<make_pair(a.x,a.y);
	}
	bool operator <=(const node &a)const
	{
		return make_pair(x,y)<=make_pair(a.x,a.y);
	}
}a[N],q[N];
bool vis[N],ans[N];
int b[N],cnt=0;
map<pair<int,int>,int>is;
map<int,int>A,B;
int tot=0,lst=-1;
void add(int x,int y)
{
	int w=lower_bound(b+1,b+1+cnt,y)-b;
	int tx=x-tot,ty=y-t.query(w);
//	print(tx,',');
//	print(ty);
//	print(w);
	if (tx<ty) if (!vis[w]) vis[w]=1,t.add(w);
	if (tx>ty) if (lst!=x) lst=x,tot++;
}
bool check(int x,int y)
{
	if (is[make_pair(x,y)]) return 0;
	if (A.count(x)&&A[x]<y) return 1;
	if (B.count(y)&&B[y]<x) return 1;
	int w=lower_bound(b+1,b+1+cnt,y)-b;
	int tx=x-tot,ty=y-t.query(w);
//	print(tx,' '),print(ty);
	return tx!=ty;
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if (A.count(x)) A[x]=min(A[x],y); else A[x]=y;
		if (B.count(y)) B[y]=min(B[y],x); else B[y]=x;
		is[make_pair(x,y)]=1;
		a[i]=(node){i,x,y};
	}
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		q[i]=(node){i,x,y};
	}
	sort(a+1,a+1+n);
	sort(q+1,q+1+m);
	for (int i=1;i<=n;i++) b[i]=a[i].y;
	for (int i=1;i<=m;i++) b[i+n]=q[i].y;
	sort(b+1,b+1+n+m),t.n=cnt=unique(b+1,b+1+n+m)-b-1;
	for (int i=1,j=1;i<=m;i++)
	{
		while (j<=n&&a[j]<=q[i]) add(a[j].x,a[j].y),j++;
//		print(q[i].id,':');
		ans[q[i].id]=check(q[i].x,q[i].y);
	}
	for (int i=1;i<=m;i++) puts(ans[i]?"WIN":"LOSE");
	
	return 0;
}