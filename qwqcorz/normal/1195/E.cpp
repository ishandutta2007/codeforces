#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e3+5;

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
int a[N][N],g[N*N],q[N],h,t;

signed main()
{
	int n=read(),m=read(),nn=read(),mm=read(),ans=0;
	g[0]=read();
	int x=read(),y=read(),z=read();
	for (int i=1;i<=n*m;i++) g[i]=(g[i-1]*x+y)%z;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=g[(i-1)*m+j-1];
	for (int i=1;i<=n;i++)
	{
		h=1;
		t=0;
		for (int j=1;j<=m;j++)
		{
			if (h<=t&&j-q[h]+1>mm) h++;
			while (h<=t&&a[i][q[t]]>=a[i][j]) t--;
			q[++t]=j;
			if (j>=mm) a[i][j-mm+1]=a[i][q[h]];
		}
	}
	for (int j=1;j<=m-mm+1;j++)
	{
		h=1;
		t=0;
		for (int i=1;i<=n;i++)
		{
			if (h<=t&&i-q[h]+1>nn) h++;
			while (h<=t&&a[q[t]][j]>=a[i][j]) t--;
			q[++t]=i;
			if (i>=nn) a[i-nn+1][j]=a[q[h]][j];
		}
	}
	for (int i=1;i<=n-nn+1;i++)
	for (int j=1;j<=m-mm+1;j++) ans+=a[i][j];
	print(ans);

	return 0;
}