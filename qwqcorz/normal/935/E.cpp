#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e2+5;

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
struct node
{
	int ls,rs;
	int val;
	int siz;
}t[N];
int f[N][M],g[N][M],cnt=0;
char a[N];
int now=1;
int get()
{
//	print(now);
	if ('1'<=a[now]&&a[now]<='9')
	{
		t[++cnt].val=a[now++]-'0';
		return cnt;
	}
	int w=++cnt;
	now++;
	t[w].ls=get();
//	if (a[now+1]==')')
//	{
//		now++;
//		t[w].val=-1;
//		return w;
//	}
	now++;
	t[w].rs=get();
	now++;
	return w;
}
void dfs(int now)
{
	if (t[now].val) return;
	dfs(t[now].ls);
	dfs(t[now].rs);
	t[now].siz=t[t[now].ls].siz+t[t[now].rs].siz+1;
}
void dfs1(int now,int p,int q)
{
	if (!t[now].val)
	{
		int ls=t[now].ls,rs=t[now].rs;
		dfs1(ls,p,q);
		dfs1(rs,p,q);
		for (int i=0;i<=min(t[now].siz,p);i++)
		for (int j=0;j<=min(t[ls].siz,i);j++)
		{
			if (i-j-1>=0)
			f[now][i]=max(f[now][i],f[ls][j]+f[rs][i-j-1]);
			f[now][i]=max(f[now][i],f[ls][j]-g[rs][i-j]);
			if (i-j-1>=0)
			g[now][i]=min(g[now][i],g[ls][j]+g[rs][i-j-1]);
			g[now][i]=min(g[now][i],g[ls][j]-f[rs][i-j]);
		}
	}
	else f[now][0]=g[now][0]=t[now].val;
}
void solve1(int p,int q)
{
	dfs1(1,p,q);
	print(f[1][p]);
}
void dfs2(int now,int p,int q)
{
	if (!t[now].val)
	{
		int ls=t[now].ls,rs=t[now].rs;
		dfs2(ls,p,q);
		dfs2(rs,p,q);
		for (int i=0;i<=min(t[now].siz,q);i++)
		for (int j=0;j<=min(t[ls].siz,i);j++)
		{
			if (i-j-1>=0)
			f[now][i]=max(f[now][i],f[ls][j]-g[rs][i-j-1]);
			f[now][i]=max(f[now][i],f[ls][j]+f[rs][i-j]);
			if (i-j-1>=0)
			g[now][i]=min(g[now][i],g[ls][j]-f[rs][i-j-1]);
			g[now][i]=min(g[now][i],g[ls][j]+g[rs][i-j]);
		}
	}
	else f[now][0]=g[now][0]=t[now].val;
}
void solve2(int p,int q)
{
	dfs2(1,p,q);
	print(f[1][q]);
}

signed main()
{
	scanf("%s",a+1);
	int len=strlen(a+1);
	if (len==1) return putchar(a[1]),0;
	int root=get();
//	for (int i=1;i<=cnt;i++)
//	{
//		print(t[i].ls,' ');
//		print(t[i].rs,' ');
//		print(t[i].val);
//	}
//	print(root);
	memset(f,0xc0,sizeof(f));//Max
	memset(g,0x3f,sizeof(g));//Min
	dfs(1);
	int p=read(),q=read();
	if (p<=q) solve1(p,q);
		 else solve2(p,q);

	return 0;
}