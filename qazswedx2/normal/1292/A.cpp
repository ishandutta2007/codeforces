#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,vis[1000005][2],ans;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		swap(x,y);
		vis[x][y]^=1;
		if(vis[x][y]==0) ans-=vis[x-1][y^1]+vis[x][y^1]+vis[x+1][y^1];
		else ans+=vis[x-1][y^1]+vis[x][y^1]+vis[x+1][y^1];
		if(!ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}