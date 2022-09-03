#include <cstdio>
#include <vector>
using namespace std;
int n,m;
char a[502][502];
bool vis[502][502];
int xx,yy;
vector<int> ans,ax,bx;
void dfs(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||a[x][y]=='#'||vis[x][y])
		return;
	vis[x][y]=true;
	ans.push_back('B');
	ax.push_back(x);
	bx.push_back(y);
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
	if(x!=xx||y!=yy)
	{
		ans.push_back('D');
		ans.push_back('R');
		ax.push_back(x);
		bx.push_back(y);
		ax.push_back(x);
		bx.push_back(y);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(xx=0;xx<n;xx++)
		scanf("%s",a[xx]);
	for(xx=0;xx<n;xx++)
		for(yy=0;yy<m;yy++)
			dfs(xx,yy);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%c %d %d\n",ans[i],ax[i]+1,bx[i]+1);
	return 0;
}