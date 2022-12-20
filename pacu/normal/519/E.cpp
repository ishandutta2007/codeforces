#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > edges;
bool used[100000];
int depth[100000];
int sz[100000];
int par[100000][20];

void dfs(int i,int d)
{
	used[i] = 1;
	depth[i] = d;
	sz[i] = 1;
	int c = 0;
	while(c<19)
	{
		if(par[i][c] != -1)
			par[i][c+1] = par[par[i][c]][c];
		else
			par[i][c+1] = -1;
		c++;
	}
	for(int j=0;j<edges[i].size();j++)
	{
		if(!used[edges[i][j]])
		{
			par[edges[i][j]][0] = i;
			dfs(edges[i][j],d+1);
			sz[i] += sz[edges[i][j]];
		}
	}
}

int lca(int a,int b)
{
	int c = 19;
	while(c>=0)
	{
		if((depth[a]-(1<<c))>=depth[b])
		{
			a = par[a][c];
		}
		c--;
	}
	c = 19;
	while(c>=0)
	{
		if((depth[b]-(1<<c))>=depth[a])
		{
			b = par[b][c];
		}
		c--;
	}
	c = 19;
	if(a==b) return a;
	while(c>=0)
	{
		if(par[a][c] != par[b][c])
		{
			a = par[a][c];
			b = par[b][c];
		}
		c--;
	}
	if(par[a][0] != par[b][0])
		cout << "BADBAD" << endl;
	return par[a][0];
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
		used[i] = 0;
	}
	int a,b;
	for(int i=0;i<N-1;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	par[0][0] = -1;
	dfs(0,0);
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> a >> b;
		a--,b--;
		if(depth[a]<depth[b])
			swap(a,b);
		int l = lca(a,b);
		int dist = depth[a]+depth[b]-2*depth[l];
		if(dist%2)
		{
			cout << 0 << endl;
		}
		else if(a==b)
		{
			cout << N << endl;
		}
		else if(depth[a]==depth[b])
		{
			int cdist = dist/2 - 1;
			int c=19;
			while(c>=0)
			{
				if((1<<c) <= cdist)
				{
					a = par[a][c];
					cdist -= 1<<c;
				}
				c--;
			}
			cdist = dist/2 - 1;
			c=19;
			while(c>=0)
			{
				if((1<<c) <= cdist)
				{
					b = par[b][c];
					cdist -= 1<<c;
				}
				c--;
			}
			cout << N-sz[a]-sz[b] << endl;
		}
		else
		{
			dist /= 2;
			dist--;
			int c=19;
			while(c>=0)
			{
				if((1<<c) <= dist)
				{
					a = par[a][c];
					dist -= 1<<c;
				}
				c--;
			}
			cout << sz[par[a][0]]-sz[a] << endl;
		}
	}
}