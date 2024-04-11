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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool Ask(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	return read();
}
bool vis[N][N];
int a[N][N],n;
void dfs(int x,int y)
{
	vis[x][y]=1;
	if (y+2<=n&&!vis[x][y+2]) a[x][y+2]=a[x][y]^!Ask(x,y,x,y+2),dfs(x,y+2);
	if (y-2>=1&&!vis[x][y-2]) a[x][y-2]=a[x][y]^!Ask(x,y-2,x,y),dfs(x,y-2);
	if (x<n&&y<n&&!vis[x+1][y+1]) a[x+1][y+1]=a[x][y]^!Ask(x,y,x+1,y+1),dfs(x+1,y+1);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read();
	a[1][1]=1;
	dfs(1,1);
	dfs(1,2);
	bool flag=0;
	for (int i=1;i<=n;i+=2)
	{
		if (i>1&&(a[i][i]^a[i-1][i]^a[i-1][i-1]^a[i-2][i-1])==0)
		{
			flag=(a[i-2][i-1]^!Ask(i-2,i-1,i,i))!=a[i][i];
			break;
		}
		if (i<n&&(a[i][i]^a[i][i+1]^a[i+1][i+1]^a[i+1][i+2])==0)
		{
			flag=(a[i+1][i+2]^!Ask(i,i,i+1,i+2))!=a[i][i];
			break;
		}
	}
	if (flag)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if ((i&1)^(j&1)) a[i][j]^=1;
	puts("!");
	for (int i=1;i<=n;i++,puts(""))
	for (int j=1;j<=n;j++)
	putchar(a[i][j]+'0');
	
	return 0;
}