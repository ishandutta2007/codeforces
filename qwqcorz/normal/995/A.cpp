#include<bits/stdc++.h>
using namespace std;
const int N=55;
const int M=2e4+5;

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
int a[5][N];
int ans[M][4],cnt=0;
void push(int i,int x,int y)
{
	cnt++;
	ans[cnt][1]=i;
	ans[cnt][2]=x;
	ans[cnt][3]=y;
}

signed main()
{
	int n=read(),k=read(),tot=0;
	for (int i=0;i<=3;i++)
	for (int j=1;j<=n;j++) a[i][j]=read();
	for (int t=1;t<=2*n;t++)
	{
		for (int i=1;i<=n;i++)
		if (a[1][i]&&a[1][i]==a[0][i])
		{
			push(a[1][i],0,i);
			a[1][i]=0;
			tot++;
		}
		for (int i=1;i<=n;i++)
		if (a[2][i]&&a[2][i]==a[3][i])
		{
			push(a[2][i],3,i);
			a[2][i]=0;
			tot++;
		}
		if (tot==k) break;
		int x=-1,y=-1;
		for (int i=1;i<=2;i++)
		for (int j=1;j<=n;j++)
		if (a[i][j]==0)
		{
			x=i;
			y=j;
			break;
		}
		if (x<0) break;
		for (int i=1;i<n*2;i++)
		{
			int nx=x,ny=y;
			if (x==1&&y==1) nx=2;
			else if (x==2&&y==n) nx=1;
			else if (x==1) ny--;
			else ny++;
			if (a[x][y]==0&&a[nx][ny])
			{
				push(a[nx][ny],x,y);
				swap(a[x][y],a[nx][ny]);
			}
			x=nx;
			y=ny;
		}
	}
	if (tot<k) return puts("-1");
	print(cnt);
	for (int i=1;i<=cnt;i++)
	{
		print(ans[i][1],' ');
		print(ans[i][2]+1,' ');
		print(ans[i][3]);
	}

	return 0;
}