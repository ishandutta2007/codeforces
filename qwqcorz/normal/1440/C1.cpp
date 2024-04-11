#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;

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
int cnt;
struct answer
{
	int x1,y1,x2,y2,x3,y3;
	void Print()
	{
		print(x1,' ');
		print(y1,' ');
		print(x2,' ');
		print(y2,' ');
		print(x3,' ');
		print(y3);
	}
}ans[N*N];
bool a[N][N];
void reverse(int x1,int y1,int x2,int y2,int x3,int y3)
{
	a[x1][y1]^=1;
	a[x2][y2]^=1;
	a[x3][y3]^=1;
	cnt++;
	ans[cnt].x1=x1;
	ans[cnt].y1=y1;
	ans[cnt].x2=x2;
	ans[cnt].y2=y2;
	ans[cnt].x3=x3;
	ans[cnt].y3=y3;
}
void fuck(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	reverse(x1,y1,x2,y2,x3,y3);
	reverse(x1,y1,x2,y2,x4,y4);
	reverse(x1,y1,x3,y3,x4,y4);
}

signed main()
{
	int T=read();
	while (T--)
	{
		cnt=0;
		int n=read(),m=read();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=get();
		for (int i=1;i<=n-2;i++)
		for (int j=1;j<=m;j++)
		if (a[i][j])
		{
			int y;
			if (j<m) y=j+1;
				else y=m-1;
			reverse(i,j,i+1,j,i+1,y);
		}
		if (a[n][m]) reverse(n,m,n,m-1,n-1,m-1);
		if (a[n-1][m]) reverse(n-1,m,n,m-1,n-1,m-1);
		for (int i=1;i+1<=m;i+=2)
		{
			//4
			if (a[n-1][i]&&a[n-1][i+1]&&a[n][i]&&a[n][i+1]) reverse(n-1,i,n-1,i+1,n,i);
			//3
			if (a[n-1][i]&&a[n-1][i+1]&&a[n][i]) reverse(n-1,i,n-1,i+1,n,i);
			if (a[n-1][i]&&a[n-1][i+1]&&a[n][i+1]) reverse(n-1,i,n-1,i+1,n,i+1);
			if (a[n-1][i]&&a[n][i]&&a[n][i+1]) reverse(n-1,i,n,i,n,i+1);
			if (a[n-1][i+1]&&a[n][i]&&a[n][i+1]) reverse(n-1,i+1,n,i,n,i+1);
			//2
			if (a[n][i]&&a[n][i+1]) reverse(n-1,i+1,n,i,n,i+1);
			if (a[n-1][i+1]&&a[n][i+1]) reverse(n-1,i+1,n,i,n,i+1);
			if (a[n-1][i+1]&&a[n][i]) reverse(n-1,i+1,n,i,n,i+1);
			if (a[n-1][i]&&a[n][i+1]) reverse(n-1,i,n,i,n,i+1);
			if (a[n-1][i]&&a[n][i]) reverse(n-1,i,n,i,n,i+1);
			if (a[n-1][i]&&a[n-1][i+1]) reverse(n-1,i,n-1,i+1,n,i+1);
			//1
			if (a[n-1][i]  ) fuck(n-1,i,n-1,i+1,n,i,n,i+1);
			if (a[n-1][i+1]) fuck(n-1,i+1,n-1,i,n,i,n,i+1);
			if (a[n][i]    ) fuck(n,i,n-1,i,n-1,i+1,n,i+1);
			if (a[n][i+1]  ) fuck(n,i+1,n-1,i,n-1,i+1,n,i);
		}
		print(cnt);
		for (int i=1;i<=cnt;i++) ans[i].Print();
	}

	return 0;
}