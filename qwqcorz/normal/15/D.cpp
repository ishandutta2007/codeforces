#include<bits/stdc++.h>
#define int long long
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
bool vis[N][N];
int a[N][N],sum[N][N],Min[N][N],val[N][N],q[N];
struct node
{
	int x,y;
	bool operator <(const node &a)const
	{
		if (val[x][y]==val[a.x][a.y]) return x==a.x?y<a.y:x<a.x;
		return val[x][y]<val[a.x][a.y];
	}
}c[N*N],ans[N*N];

signed main()
{
	int n=read(),m=read(),x=read(),y=read(),answer=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=sum[i][j]=Min[i][j]=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	for (int i=1;i<=n;i++)
	for (int j=1,h=1,t=0;j<=m;j++)
	{
		while (h<=t&&Min[i][j]<Min[i][q[t]]) t--;
		q[++t]=j;
		while (h<=t&&j-q[h]+1>y) h++;
		if (j>=y) Min[i][j-y+1]=Min[i][q[h]];
	}
	for (int j=1;j<=m-y+1;j++)
	for (int i=1,h=1,t=0;i<=n;i++)
	{
		while (h<=t&&Min[i][j]<Min[q[t]][j]) t--;
		q[++t]=i;
		while (h<=t&&i-q[h]+1>x) h++;
		if (i>=x) Min[i-x+1][j]=Min[q[h]][j];
	}
	for (int i=1;i<=n-x+1;i++)
	for (int j=1;j<=m-y+1;j++)
	val[i][j]=sum[i+x-1][j+y-1]-sum[i+x-1][j-1]-sum[i-1][j+y-1]+sum[i-1][j-1]-Min[i][j]*x*y;
//	for (int i=1;i<=n-x+1;i++,puts(""))
//	for (int j=1;j<=m-y+1;j++) print(sum[i+x-1][j+y-1]-sum[i+x-1][j-1]-sum[i-1][j+y-1]+sum[i-1][j-1],' ');
//	puts("");
//	for (int i=1;i<=n-x+1;i++,puts(""))
//	for (int j=1;j<=m-y+1;j++) print(Min[i][j],' ');
//	puts("");
//	for (int i=1;i<=n-x+1;i++,puts(""))
//	for (int j=1;j<=m-y+1;j++) print(val[i][j],' ');
//	puts("");
	int cnt=0;
	for (int i=1;i<=n-x+1;i++)
	for (int j=1;j<=m-y+1;j++)
	c[++cnt]=(node){i,j};
	sort(c+1,c+1+cnt);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=cnt;i++)
	if (!vis[c[i].x][c[i].y])
	{
		int nx=c[i].x,ny=c[i].y;
		for (int j=max(nx-x+1,1ll);j<=nx+x-1;j++)
		for (int k=max(ny-y+1,1ll);k<=ny+y-1;k++) vis[j][k]=1;
		ans[++answer]=(node){nx,ny};
	}
	print(answer);
	for (int i=1;i<=answer;i++)
	{
		print(ans[i].x,' ');
		print(ans[i].y,' ');
		print(val[ans[i].x][ans[i].y]);
	}

	return 0;
}