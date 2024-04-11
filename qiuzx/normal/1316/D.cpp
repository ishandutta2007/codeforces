#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
int n,dy[4]={0,1,-1,0},dx[4]={-1,0,0,1};
char ans[N][N],d[5]={'U','R','L','D','?'};
bool book[N][N],vis[N][N],fd;
pair<int,int> vp[N][N],bad=make_pair(-2,-2);
void dfs(int x,int y,int tp)
{
	if(vp[x][y]==make_pair(x,y))
	{
		vis[x][y]=true;
		fd=true;
		ans[x][y]='X';
		return;
	}
	if(book[x][y]&&vp[x][y]==bad)
	{
		vis[x][y]=true;
		fd=true;
		return;
	}
	if(book[x][y])
	{
		return;
	}
	book[x][y]=true;
	int i,tx,ty;
	for(i=0;i<4;i++)
	{
		tx=x+dx[i];
		ty=y+dy[i];
		ans[x][y]=d[i];
		if(vp[tx][ty]==vp[x][y]&&tx>=0&&tx<n&&ty>=0&&ty<n)
		{
			if(vis[tx][ty])
			{
				vis[x][y]=true;
				fd=true;
				return;
			}
			dfs(tx,ty,i);
		}
		if(fd)
		{
			vis[x][y]=true;
			return;
		}
	}
	ans[x][y]=d[3-tp];
	return;
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d%d",&vp[i][j].F,&vp[i][j].S);
			vp[i][j].F--;
			vp[i][j].S--;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!book[i][j])
			{
				fd=false;
				dfs(i,j,-1);
				if(ans[i][j]=='?')
				{
					puts("INVALID");
					return 0;
				}
			}
		}
	}
	puts("VALID");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c",ans[i][j]);
		}
		puts("");
	}
	return 0;
}
/*
3
1 1 1 1 1 1
1 1 2 2 1 1
1 1 2 2 2 2
*/