#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[200000];
bool vis[200000];
bool dir[200000];

void dfs(int i,int d)
{
	vis[i] = 1;
	dir[i] = d;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!vis[edges[i][j]])
			dfs(edges[i][j],d^1);
		else if(dir[edges[i][j]]!=d^1)
			cout << "PIE\n";
	}
}

int a[200000],b[200000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a[i] >> b[i];
		a[i]--,b[i]--;
		edges[a[i]].push_back(b[i]);
		edges[b[i]].push_back(a[i]);
	}
	for(int i=0;i<N;i++)
	{
		edges[2*i].push_back(2*i+1);
		edges[2*i+1].push_back(2*i);
	}
	for(int i=0;i<2*N;i++) if(!vis[i])
		dfs(i,0);
	for(int i=0;i<N;i++)
	{
		cout << dir[a[i]]+1 << ' ' << dir[b[i]]+1 << '\n';
	}
}