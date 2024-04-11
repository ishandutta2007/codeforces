#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
int a[N][N],b[N],x[N][N],y[N][N],maxx[N],maxy[N];

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) b[j]=a[i][j];
		sort(b+1,b+1+m);
		maxx[i]=unique(b+1,b+1+m)-b-1;
		for (int j=1;j<=m;j++) x[i][j]=lower_bound(b+1,b+1+maxx[i],a[i][j])-b;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++) b[j]=a[j][i];
		sort(b+1,b+1+n);
		maxy[i]=unique(b+1,b+1+n)-b-1;
		for (int j=1;j<=n;j++) y[j][i]=lower_bound(b+1,b+1+maxy[i],a[j][i])-b;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (x[i][j]<y[i][j]) print(max(maxx[i]+y[i][j]-x[i][j],maxy[j]),j==m?'\n':' ');
					else print(max(maxx[i],maxy[j]+x[i][j]-y[i][j]),j==m?'\n':' ');
	
	return 0;
}
/*
4 5
1 1 10 1 1
1 1 20 1 1
11 13 14 15 16
1 1 10 1 1
*/