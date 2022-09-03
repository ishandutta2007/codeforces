#include <bits/stdc++.h>
using namespace std;
const int maxn=55;
char str[maxn][maxn];
int n,m;
bool use[maxn][maxn];
void dfs(int x,int y,int fx,int fy)
{
	if(str[x][y]!=str[fx][fy])
		return;
	if(use[x][y])
	{
		puts("Yes");
		exit(0);
	}
	use[x][y]=true;
	if(x-1>0&&x-1!=fx)dfs(x-1,y,x,y);
	if(y-1>0&&y-1!=fy)dfs(x,y-1,x,y);
	if(x+1<n&&x+1!=fx)dfs(x+1,y,x,y);
	if(y+1<m&&y+1!=fy)dfs(x,y+1,x,y);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",str[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			memset(use,0,sizeof(use));
			dfs(i,j,i,j);
		}
	puts("No");
	return 0;
}