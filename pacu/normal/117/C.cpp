#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > edges;
int vis[5000];
int ans[3];

bool dfs(int i,int par,int depth,int start)
{
	if(vis[i]&(1<<depth)) return 0;
	vis[i] |= 1<<depth;
	if(depth==2)
	{
		for(int j=0;j<edges[i].size();j++)
			if(edges[i][j]==start)
			{
				ans[0] = start;
				ans[1] = par;
				ans[2] = i;
				return 1;
			}
		return 0;
	}
	for(int j=0;j<edges[i].size();j++)
		if(dfs(edges[i][j],i,depth+1,start))
			return 1;
	return 0;
}

int main()
{
	char tmp[5001];
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		edges.push_back(vector<int>());
	for(int i=0;i<N;i++)
	{
		scanf("%s",&tmp);
		for(int j=0;j<N;j++)
			if(tmp[j]=='1')
				edges[i].push_back(j);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			vis[i] = 0;
		if(dfs(i,-1,0,i))
		{
			printf("%d %d %d\n",ans[0]+1,ans[1]+1,ans[2]+1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}