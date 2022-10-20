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
bool get()
{
	char c=getchar();
	while (c!='.'&&c!='#') c=getchar();
	return c=='#';
}
bool a[N][N];
int fa[N*2];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n+m;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i][j]=get())
	fa[find(i)]=find(j+n);
//	for (int i=1;i<=n;i++,puts(""))
//	for (int j=1;j<=m;j++) print(a[i][j],' ');
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		for (int k=1;k<=n;k++)
		if (a[i][j]&&a[k][j])
		fa[find(i)]=find(k);
		for (int k=1;k<=m;k++)
		if (a[i][j]&&a[i][k])
		fa[find(j+n)]=find(k+n);
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (!a[i][j]&&find(i)==find(j+n))
	return puts("No");
	puts("Yes");

	return 0;
}