#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[300000];
int nxt[600005];
bool bridge[600005];
bool art[600005];
bool vis[300000];
int lowdepth[300000],depth[300000];
int N,M;

void dfs(int i,int d,int e)
{	
	vis[i] = 1;
	lowdepth[i] = d;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!vis[nxt[edges[i][j]]])
			dfs(nxt[edges[i][j]],d+1,edges[i][j]);
		if(edges[i][j]/2 != e/2)
			lowdepth[i] = min(lowdepth[i],lowdepth[nxt[edges[i][j]]]);
	}
	if(e != -1 && lowdepth[i]==d)
	{
		bridge[e] = bridge[e^1] = 1;
	}
}

int cid[300000],sz[300000];
void init()
{
	for(int i=0;i<N;i++)
		cid[i] = i, sz[i] = 1;
}
int find(int i)
{
	if(cid[i]==i) return i;
	cid[i] = find(cid[i]);
	return cid[i];
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	if(i==j) return;
	if(sz[i] <= sz[j])
	{
		cid[i] = j;
		sz[j] += sz[i];
	}
	else
	{
		cid[j] = i;
		sz[i] += sz[j];
	}
}

int main()
{
	cin >> N >> M;
	int x,y,z;
	for(int i=0;i<M;i++)
	{
		cin >> x >> y >> z;
		x--,y--;
		edges[x].push_back(2*i);
		edges[y].push_back(2*i+1);
		nxt[2*i] = y, nxt[2*i+1] = x;
		art[2*i] = art[2*i+1] = z;
	}
	int a,b;
	cin >> a >> b;
	a--,b--;
	edges[a].push_back(2*M);
	edges[b].push_back(2*M+1);
	nxt[2*M] = b, nxt[2*M+1] = a;
	
	dfs(0,0,-1);
	
	init();
	for(int i=0;i<N;i++)
		for(int j=0;j<edges[i].size();j++)
			if(!bridge[edges[i][j]])
			{
				join(i,nxt[edges[i][j]]);
			}
	bool ok = 0;
	for(int i=0;i<2*M;i+=2)
	{
		if(!bridge[i] && art[i] && find(nxt[i])==find(a))
			ok = 1;
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}