#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
const int N=3e5+5;

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
int t[N],nn;
void add(int x,int y)
{
	for (;x<=nn;x+=x&-x) t[x]+=y;
}
int query(int x)
{
	int ret=0;
	for (;x;x-=x&-x) ret+=t[x];
	return ret;
}
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
struct Query
{
	int l,r,id;
	bool operator <(const Query &a)const
	{
		return r==a.r?l<a.l:r<a.r;
	}
}q[N];
map<pair<int,int>,int>Map;
int x[N],y[N],col[N],pre[N],b[N],ans[N],ed[N];

signed main()
{
	memset(t,0,sizeof(t));
	Map.clear();
	int n=read(),cntcol=0,cnt=0;
	for (int i=1;i<=n;i++)
	{
		int m=read();
		x[1]=read();
		y[1]=read();
		for (int j=2;j<=m;j++)
		{
			x[j]=read();
			y[j]=read();
			int X=x[j]-x[j-1],Y=y[j]-y[j-1];
			int g=gcd(abs(X),abs(Y));
			X/=g;
			Y/=g;
			if (!Map.count(mk(X,Y))) Map[mk(X,Y)]=++cntcol;
			col[++cnt]=Map[mk(X,Y)];
		}
		int X=x[1]-x[m],Y=y[1]-y[m];
		int g=gcd(abs(X),abs(Y));
		X/=g;
		Y/=g;
		if (!Map.count(mk(X,Y))) Map[mk(X,Y)]=++cntcol;
		col[++cnt]=Map[mk(X,Y)];
		ed[i]=cnt;
	}
	nn=cnt;
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		q[i].id=i;
		q[i].l=read();
		q[i].r=read();
	}
	sort(q+1,q+1+Q);
	memset(b,0,sizeof(b));
//	for (int i=1;i<=cnt;i++) print(col[i],' ');puts("");
	for (int i=1;i<=cnt;i++)
	{
		pre[i]=b[col[i]];
		b[col[i]]=i;
	}
//	for (int i=1;i<=cnt;i++) print(pre[i],' ');puts("");
	int now=1;
	for (int i=1;i<=Q;i++)
	{
		while (now<=ed[q[i].r])
		{
			if (pre[now]) add(pre[now],-1);
			add(now,1);
			now++;
		}
//		print(q[i].id,':');
//		print(q[i].l,' ');
//		print(q[i].r);
		ans[q[i].id]=query(ed[q[i].r])-query(ed[q[i].l-1]);
	}
	for (int i=1;i<=Q;i++) print(ans[i]);

	return 0;
}