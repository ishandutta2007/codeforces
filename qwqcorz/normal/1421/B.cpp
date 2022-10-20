#include<bits/stdc++.h>
using namespace std;
const int N=2e2+5;

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
char get()
{
	char c=getchar();
	while (c!='0'&&c!='1'&&c!='S'&&c!='F') c=getchar();
	return c;
}
char a[N][N];
int num[N][N],fa[N*N],x[4],y[4];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void rev(int x,int y)
{
	if (a[x][y]=='0') a[x][y]='1';
				 else a[x][y]='0';
}
void merge(int u,int v)
{
	int x=find(u),y=find(v);
	if (x!=y) fa[x]=y;
}
bool check(int n)
{
	for (int i=1;i<=n*n;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		if (i>1&&a[i][j]==a[i-1][j]) merge(num[i][j],num[i-1][j]);
		if (j>1&&a[i][j]==a[i][j-1]) merge(num[i][j],num[i][j-1]);
	}
	for (int i=0;i<=1;i++)
	for (int j=2;j<=3;j++)
	if (find(num[x[i]][y[i]])==find(num[x[j]][y[j]]))
	return 0;
	return 1;
}
void alb(int n)
{
	for (int i=0;i<4;i++)
	{
		rev(x[i],y[i]);
		if (check(n))
		{
			puts("1");
			print(x[i],' ');
			print(y[i]);
			return;
		}
		rev(x[i],y[i]);
	}
	for (int i=0;i<4;i++)
	for (int j=i+1;j<4;j++)
	{
		rev(x[i],y[i]);
		rev(x[j],y[j]);
		if (check(n))
		{
			puts("2");
			print(x[i],' ');
			print(y[i]);
			print(x[j],' ');
			print(y[j]);
			return;
		}
		rev(x[i],y[i]);
		rev(x[j],y[j]);
	}
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),cnt=0;
		x[0]=1;
		y[0]=2;
		x[1]=2;
		y[1]=1;
		x[2]=n-1;
		y[2]=n;
		x[3]=n;
		y[3]=n-1;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) num[i][j]=++cnt;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) a[i][j]=get();
		if (check(n)) puts("0");
		else alb(n);
	}

	return 0;
}