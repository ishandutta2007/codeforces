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
void error()
{
	puts("INVALID");
	exit(0);
}
char ans[N][N];
int x[N][N],y[N][N];
void dfs(int nx,int ny,int xx,int yy)
{
	if (ans[nx+1][ny]==0&&x[nx+1][ny]==xx&&y[nx+1][ny]==yy)
	{
		ans[nx+1][ny]='U';
		dfs(nx+1,ny,xx,yy);
	}
	if (ans[nx-1][ny]==0&&x[nx-1][ny]==xx&&y[nx-1][ny]==yy)
	{
		ans[nx-1][ny]='D';
		dfs(nx-1,ny,xx,yy);
	}
	if (ans[nx][ny+1]==0&&x[nx][ny+1]==xx&&y[nx][ny+1]==yy)
	{
		ans[nx][ny+1]='L';
		dfs(nx,ny+1,xx,yy);
	}
	if (ans[nx][ny-1]==0&&x[nx][ny-1]==xx&&y[nx][ny-1]==yy)
	{
		ans[nx][ny-1]='R';
		dfs(nx,ny-1,xx,yy);
	}
}

int main()
{
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(ans,0,sizeof(ans));
	int n=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		x[i][j]=read();
		y[i][j]=read();
		if (x[i][j]>0) ans[x[i][j]][y[i][j]]='X';
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (ans[i][j]=='X') dfs(i,j,i,j);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		if (x[i][j]==-1&&(i==1||x[i-1][j]>0)&&(i==n||x[i+1][j]>0)&&(j==1||x[i][j-1]>0)&&(j==n||x[i][j+1]>0)) error();
		if (ans[i][j]=='X'&&x[i][j]<0) error();
		if (ans[i][j]=='X'&&(x[i][j]!=i||y[i][j]!=j)) error();
		if (x[i][j]>0&&ans[i][j]==0) error();
	}
	puts("VALID");
	for (int i=1;i<=n;i++)
	for (int j=1;j<n;j++)
	if (ans[i][j]==0&&ans[i][j+1]==0)
	if (x[i][j]<0&&x[i][j+1]<0)
	{
		ans[i][j]='R';
		ans[i][j+1]='L';
	}
	for (int i=1;i<n;i++)
	for (int j=1;j<=n;j++)
	if (ans[i][j]==0&&ans[i+1][j]==0)
	if (x[i][j]<0&&x[i+1][j]<0)
	{
		ans[i][j]='D';
		ans[i+1][j]='U';
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (ans[i][j]==0)
	{
		if (x[i][j-1]<0) ans[i][j]='L';
		if (x[i-1][j]<0) ans[i][j]='U';
		if (x[i][j+1]<0) ans[i][j]='R';
		if (x[i+1][j]<0) ans[i][j]='D';
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) putchar(ans[i][j]);
		puts("");
	}

	return 0;
}