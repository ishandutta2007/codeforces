#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> edges[200000];
int d[200000];

void dfsDepth(int i,int par,int dd)
{
	d[i] = dd;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
			dfsDepth(edges[i][j],i,dd+1);
}

int dfs(int i,int par,int t)
{
	int v = d[i] - t/2;
	if(v<=0) return v;
	v *= 2;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
			v = max(v,2+dfs(edges[i][j],i,t+2));
	return v;
}

int main()
{
	int x,a,b;
	cin >> N >> x;
	x--;
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfsDepth(0,-1,0);
	cout << dfs(x,-1,0) << '\n';
}