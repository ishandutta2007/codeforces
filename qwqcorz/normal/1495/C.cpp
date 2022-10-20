#include<bits/stdc++.h>
using namespace std;
const int N=505;

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
char a[N][N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		cin>>a[i][j];
		if (m<=2) for (int i=1;i<=n;i++) a[i][1]='X';
		else
		{
			for (int i=1;i<=n;i+=3)
			for (int j=1;j<=m;j++) a[i][j]='X';
			for (int i=1;i+3<=n;i+=3)
			{
				if (a[i+1][1]=='X') a[i+2][1]='X';
				if (a[i+1][2]=='X') a[i+2][2]='X';
				if (a[i+2][1]=='X') a[i+1][1]='X';
				if (a[i+2][2]=='X') a[i+1][2]='X';
				if (a[i+1][1]!='X'&&a[i+1][2]!='X') a[i+1][1]=a[i+2][1]='X';
			}
			if (n%3==0) for (int j=1;j<=m;j++) if (a[n][j]=='X') a[n-1][j]='X';
		}
		for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=m;j++)
		putchar(a[i][j]);
	}

	return 0;
}