#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int M=1e6+5;
const int inf=114514;

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
bool get()
{
	char c=getchar();
	while (c!='0'&&c!='1') c=getchar();
	return c-'0';
}
int f[N][N],p[M],dp[M],pre[N];
void Print(int x)
{
	if (x==pre[x])
	{
		print(p[x],' ');
		return;
	}
	Print(pre[x]);
	print(p[x],' ');
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) f[i][j]=get()?1:inf;
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int m=read();
	for (int i=1;i<=m;i++) p[i]=read();
	dp[1]=pre[1]=1;
	for (int j=1,i=2;i<=m;i++)
	{
		while (i-j!=f[p[j]][p[i]]) j++;
		pre[i]=j;
		dp[i]=dp[j]+1;
	}
	print(dp[m]);
	Print(m);

	return 0;
}