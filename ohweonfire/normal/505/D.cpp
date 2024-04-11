#include <cstdio>
#include <vector>
using namespace std;
const int maxn=100005;
vector<int> g[maxn],g2[maxn],v;
int n,ans,m,x,y,t;
bool vis[maxn],use[maxn],ok,dd[maxn];
void dfs(int x)
{
	vis[x]=true;
	v.push_back(x);
	for(int i=0;i<g2[x].size();i++)
		if(!vis[g2[x][i]])
			dfs(g2[x][i]);
}
void dfs2(int x)
{
	use[x]=true;
	dd[x]=true;
	for(int i=0;i<g[x].size();i++)
		if(use[g[x][i]])
			ok|=true;
		else if(!dd[g[x][i]])
			dfs2(g[x][i]);
	use[x]=false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g2[x].push_back(y);
		g2[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			v.clear();
			dfs(i);
			ok&=false;
			for(int j=0;j<v.size()&&!ok;j++)
				if(!dd[v[j]])
					dfs2(v[j]);
			ans+=v.size()-(!ok);
		}
	printf("%d\n",ans);
}