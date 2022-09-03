#include <bits/stdc++.h>
using namespace std;
vector<int> g[405],gr[405];
bool vis[405][405],use[405];
string heng,shu;
int n,m;
void dfs(int x)
{
	use[x]=true;
	for(int i=0;i<n;i++)
		if(!use[i]&&vis[x][i])
			dfs(i);
}
void dfs2(int x)
{
	use[x]=true;
	for(int i=0;i<n;i++)
		if(!use[i]&&vis[i][x])
			dfs2(i);
}
bool scc()
{
	dfs(0);
	for(int i=0;i<n;i++)
		if(!use[i])
			return false;
	memset(use,0,sizeof(use));
	dfs2(0);
	for(int i=0;i<n;i++)
		if(!use[i])
			return false;
	return true;
}
int main()
{
	cin>>n>>m>>heng>>shu;
	for(int i=0;i<n;i++)
		if(heng[i]=='>')
			for(int j=0;j<m-1;j++)
			{
				int x=i+j*n,y=x+n;
				vis[x][y]=true;
			}
		else
			for(int j=0;j<m-1;j++)
			{
				int x=i+j*n,y=x+n;
				vis[y][x]=true;
			}
	for(int j=0;j<m;j++)
		if(shu[j]=='v')
			for(int i=0;i<n-1;i++)
			{
				int x=i+j*n,y=x+1;
				vis[x][y]=true;
			}
		else
			for(int i=0;i<n-1;i++)
			{
				int x=i+j*n,y=x+1;
				vis[y][x]=true;
			}
	n*=m;
	if(scc())
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}