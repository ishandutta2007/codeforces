#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
int n,a[1005][1005][2],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int vis[1005][1005],q[1000005][2],head,tail;
char s[1005][1005],ch[5]="LRUD";
void bfs(int sx,int sy)
{
	head=0,tail=1;
	q[1][0]=sx,q[1][1]=sy;
	vis[sx][sy]=1;
	while(head<tail)
	{
		head++;
		int x=q[head][0],y=q[head][1];
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<=0||xx>n||yy<=0||yy>n||a[x][y][0]!=a[xx][yy][0]||a[x][y][1]!=a[xx][yy][1]
			   ||vis[xx][yy]) continue;
			vis[xx][yy]=1;
			s[xx][yy]=ch[i^1];
			q[++tail][0]=xx;
			q[tail][1]=yy;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d%d",&a[i][j][0],&a[i][j][1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==a[i][j][0]&&j==a[i][j][1])
			{
				s[i][j]='X';
				bfs(i,j);
				continue;
			}
			if(a[i][j][0]!=-1||a[i][j][1]!=-1) continue;
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k],y=j+dy[k];
				if(x<=0||x>n||y<=0||y>n||a[x][y][0]!=a[i][j][0]||a[x][y][1]!=a[i][j][1]) continue;
				s[i][j]=ch[k];
				break;
			}
		}
	int fl=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!s[i][j])
				fl=1;
	if(fl)
	{
		printf("INVALID\n");
		return 0;
	}
	printf("VALID\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%c",s[i][j]);
		printf("\n");
	}
	return 0;
}