// By: Little09
// Problem: CF226D The table
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF226D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N][N],b[N][2],ans[N][2];
int n,m;
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
void change(int x)
{
	if (x<=n)
	{
		for (int i=1;i<=m;i++)
		{
			b[i][1]-=2*a[x][i];
			a[x][i]*=-1;
		}
		b[x][0]*=-1;
		ans[x][0]^=1;
	}
	else
	{
		x-=n;
		for (int i=1;i<=n;i++)
		{
			b[i][0]-=2*a[i][x];
			a[i][x]*=-1;
		}
		b[x][1]*=-1;
		ans[x][1]^=1;
	}
}
int check()
{
	for (int i=1;i<=n;i++)
	{
		if (b[i][0]<0) return i;
	}
	for (int i=1;i<=m;i++)
	{
		if (b[i][1]<0) return i+n;
	}
	return -1;
}
void print(int x,int y)
{
	int res=0;
	for (int i=1;i<=y;i++) if (ans[i][x]) res++;
	printf("%d ",res);
	for (int i=1;i<=y;i++) if (ans[i][x]) printf("%d ",i);
	printf("\n");
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			a[i][j]=read();
			b[i][0]+=a[i][j];
			b[j][1]+=a[i][j];
		}
	}
	while (1)
	{
		int u=check();
		if (u==-1) break;
		change(u);
	}
	print(0,n),print(1,m);
	return 0;
}