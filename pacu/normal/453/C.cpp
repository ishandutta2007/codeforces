#include <iostream>
#include <vector>
using namespace std;

bool odd[100000];
bool vis[100000];
vector<int> path;
vector<vector<int> > edges;

int id[100000];
int sz[100000];
bool hasodd[100000];

void init()
{
	for(int i=0;i<100000;i++)
	{
		id[i] = i;
		sz[i] = 1;
		hasodd[i] = odd[i];
	}
}
int find(int i)
{
	int j = i;
	while(id[j]!=j)
		j = id[j];
	id[i] = j;
	return j;
}
void join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(sz[ri]<sz[rj])
	{
		id[ri] = rj;
		sz[rj] += sz[ri];
		hasodd[rj] |= hasodd[ri];
	}
	else
	{
		id[rj] = ri;
		sz[ri] += sz[rj];
		hasodd[ri] |= hasodd[rj];
	}
}


void dfs(int cur,int par)
{
	vis[cur] = true;
	path.push_back(cur+1);
	odd[cur] ^= 1;
	for(int j=0;j<edges[cur].size();j++)
		if(!vis[edges[cur][j]])
		{
			dfs(edges[cur][j],cur);
			path.push_back(cur+1);
			odd[cur] ^= 1;
		}
	if(odd[cur] && par>-1)
	{
		path.push_back(par+1);
		path.push_back(cur+1);
		odd[par] ^= 1;
		odd[cur] ^= 1;
	}
}

int main()
{
	int N,M;
	int i,j;
	int a,b;
	cin >> N >> M;
	for(i=0;i<N;i++)
		edges.push_back(vector<int>());
	for(i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(i=0;i<N;i++)
		cin >> odd[i];
	init();
	for(i=0;i<N;i++)
		for(j=0;j<edges[i].size();j++)
			join(i,edges[i][j]);
	int comp = 0;
	int root = 0;
	for(i=0;i<N;i++)
	{
		if((find(i)==i)&&(hasodd[i]))
		{
			comp += 1;
			root = i;
		}
	}
	if(comp>1)
	{
		cout << -1 << endl;
		return 0;
	}
	dfs(root,-1);
	i = odd[root];
	cout << path.size()-i << endl;
	for(;i<path.size();i++)
		cout << path[i] << " ";
}