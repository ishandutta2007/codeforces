#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> edges[100000];
int nxt[100000],cost[100000];
int d[100000];

void dfs(int i,int par,int depth)
{
	d[i] = depth;
	for(int j=0;j<edges[i].size();j++)
		if(nxt[edges[i][j]]!=par)
			dfs(nxt[edges[i][j]],i,depth+cost[edges[i][j]]);
}

int main()
{
	cin >> N;
	int a,b,c;
	for(int i=0;i<N-1;i++)
	{
		cin >> a >> b >> c;
		edges[a].push_back(2*i);
		edges[b].push_back(2*i+1);
		nxt[2*i] = b, nxt[2*i+1] = a;
		cost[2*i] = cost[2*i+1] = c;
	}
	dfs(0,-1,0);
	int mx = 0;
	for(int i=0;i<N;i++)
		mx = max(mx,d[i]);
	cout << mx << '\n';
}