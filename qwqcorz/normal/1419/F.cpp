#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int inf=2e9+7;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int n,x[N],y[N],fa[N],cnt;
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int a=find(x),b=find(y);
	if (a==b) return;
	fa[a]=b;
	cnt--;
}
int dis(int u,int v)
{
	return abs(x[u]-x[v])+abs(y[u]-y[v]);
}
int tmp[5],tot;
int cntp=0,m=0;
int dist(int X,int Y,int v)
{
	return abs(X-x[v])+abs(Y-y[v]);
}
struct node
{
	int x,y,w,s,a,d;
	bool operator <(const node &a)const
	{
		if (x==a.x) return y<a.y;
		return x<a.x;
	}
	bool operator !=(const node &a)const
	{
		return x!=a.x||y!=a.y;
	}
	node &operator +=(const node &A)
	{
		if (A.w)
		if (w==0||dist(x,y,w)>dist(x,y,A.w)) w=A.w;
		if (A.s)
		if (s==0||dist(x,y,s)>dist(x,y,A.s)) s=A.s;
		if (A.a)
		if (a==0||dist(x,y,a)>dist(x,y,A.a)) a=A.a;
		if (A.d)
		if (d==0||dist(x,y,d)>dist(x,y,A.d)) d=A.d;
		return *this;
	}
}p[N*N*2];
void add(int X,int Y,int a,int b)
{
	p[++cntp].x=X;
	p[cntp].y=Y;
	if (X==x[a])
	{
		if (Y<y[a]) p[cntp].d=a;
			   else p[cntp].a=a;
	}
	else
	{
		if (X<x[a]) p[cntp].s=a;
			   else p[cntp].w=a;
	}
	if (X==x[b])
	{
		if (Y<y[b]) p[cntp].d=b;
			   else p[cntp].a=b;
	}
	else
	{
		if (X<x[b]) p[cntp].s=b;
			   else p[cntp].w=b;
	}
}
void ADD(int x)
{
	for (int i=1;i<=tot;i++)
	if (tmp[i]==x) return;
	tmp[++tot]=x;
}
bool check(int mid)
{
	cnt=n;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (x[i]==x[j]||y[i]==y[j])
	if (dis(i,j)<=mid)
	merge(i,j);
	if (cnt>4) return 0;
	if (cnt==1) return 1;
	if (cnt==2)
	{
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (find(i)!=find(j))
		if (x[i]==x[j]||y[i]==y[j])
		if (dis(i,j)<=2ll*mid) return 1;
	}
	for (int i=1;i<=m;i++)
	{
		tot=0;
		if (p[i].a&&dist(p[i].x,p[i].y,p[i].a)<=mid) ADD(find(p[i].a));
		if (p[i].s&&dist(p[i].x,p[i].y,p[i].s)<=mid) ADD(find(p[i].s));
		if (p[i].d&&dist(p[i].x,p[i].y,p[i].d)<=mid) ADD(find(p[i].d));
		if (p[i].w&&dist(p[i].x,p[i].y,p[i].w)<=mid) ADD(find(p[i].w));
		if (tot==cnt) return 1;
	}
	return 0;
}

signed main()
{
	memset(p,0,sizeof(p));
	n=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read();
		y[i]=read();
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (x[i]!=x[j]&&y[i]!=y[j])
	{
		add(x[i],y[j],i,j);
		add(x[j],y[i],i,j);
	}
	sort(p+1,p+1+cntp);
	for (int i=1;i<=cntp;i++)
	if (i==1||p[i]!=p[i-1]) p[++m]=p[i];
					   else p[m]+=p[i];
	int l=1,r=inf;
	while (l<=r)
	{
//		print(l,' ');
//		print(r);
		int mid=l+(r-l+1)/2;
		if (check(mid)) r=mid-1;
				   else l=mid+1;
	}
	if (check(l)) print(l);
			 else print(-1);

	return 0;
}