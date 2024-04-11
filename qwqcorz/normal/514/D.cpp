#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=6;

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
int a[N][M],q[M][N],h[M],t[M],ans[M];
int calc(int m)
{
	int ret=0;
	for (int i=1;i<=m;i++) ret+=a[q[i][h[i]]][i];
	return ret;
}

signed main()
{
	int n=read(),m=read(),k=read(),Max=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	for (int j=1;j<=m;j++) h[j]=1,t[j]=0;
	for (int l=1,r=1;r<=n;r++)
	{
		for (int i=1;i<=m;i++)
		{
			while (h[i]<=t[i]&&a[q[i][t[i]]][i]<=a[r][i]) t[i]--;
			q[i][++t[i]]=r;
		}
		while (l<=r&&calc(m)>k)
		{
			l++;
			for (int i=1;i<=m;i++)
			if (q[i][h[i]]<l)
			h[i]++;
		}
		if (r-l+1>Max)
		{
//			print(l,',');print(r);
			Max=r-l+1;
			for (int i=1;i<=m;i++) ans[i]=a[q[i][h[i]]][i];
		}
	}
	for (int i=1;i<=m;i++) print(ans[i],' ');

	return 0;
}