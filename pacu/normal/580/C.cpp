#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[100000];
int N,C;
int nup[100000];
bool cat[100000];
int ans;

void dfs(int i,int par)
{
	nup[i] = cat[i];
	if(par != -1 && cat[i])
		nup[i] += nup[par];
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j] != par)
			dfs(edges[i][j],i);
}

void dfs2(int i,int par)
{
	if(par != -1)
		nup[i] = max(nup[i],nup[par]);
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j] != par)
			dfs2(edges[i][j],i);
	if(edges[i].size() == 1 && par != -1 && nup[i] <= C)
		ans++;
}

int main()
{
	cin >> N >> C;
	int a,b;
	for(int i=0;i<N;i++)
		cin >> cat[i];
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,-1);
	dfs2(0,-1);
	cout << ans << '\n';
}