#include<bits/stdc++.h>
using namespace std;
const int N=55;

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
int a[N][N],b[N][N];
bool check(int n,int m)
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		if (i>1) if (a[i][j]<=a[i-1][j]) return 0;
		if (j>1) if (a[i][j]<=a[i][j-1]) return 0;
		if (i>1) if (b[i][j]<=b[i-1][j]) return 0;
		if (j>1) if (b[i][j]<=b[i][j-1]) return 0;
	}
	return 1;
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) b[i][j]=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i][j]>b[i][j])
	swap(a[i][j],b[i][j]);
	if (check(n,m)) puts("Possible");
			   else puts("Impossible");

	return 0;
}