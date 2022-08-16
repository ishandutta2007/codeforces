#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

vector <int> dias;
vector <int> adj[110];

int dist[110] = { 0 };
bool marked[110] = { false };

void bfs(int n)
{
	queue <int> q;
	marked[n] = true;
	q.push(n);
	dist[n] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < adj[u].size(); i ++)
		{
			if(!marked[adj[u][i]])
			{
				q.push(adj[u][i]);
				dist[adj[u][i]] = dist[u] + 1;
				marked[adj[u][i]] = true;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf(" %d", &T);
	while(T --)
	{
		int n;
		scanf(" %d", &n);
		for(int i = 0; i < n - 1; i ++)
		{
			int u, v;
			scanf(" %d %d", &u, &v);
			u --;
			v --;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bfs(0);
		int maxd = 0, maxn;
		for(int i = 0; i < n; i ++)
		{
			if(dist[i] >= maxd)
			{
				maxd = dist[i];
				maxn = i;
			}
		}
		for(int i = 0; i < 110; i ++)
		{
			dist[i] = 0;
			marked[i] = false;
		}
		bfs(maxn);
		maxd = 0;
		for(int i = 0; i < n; i ++)
		{
			if(dist[i] >= maxd)
				maxd = dist[i];
		}
		dias.push_back(maxd);
		for(int i = 0; i < 110; i ++)
		{
			dist[i] = 0;
			marked[i] = false;
		}
		for(int i = 0; i < 110; i ++)
			adj[i].clear();
	}
	int sum = 0;
	for(int i = 0; i < dias.size(); i ++)
	{
		sum += dias[i];
	}
	fclose(stdin);
	freopen("output.txt", "w", stdout);
	printf("%d\n", sum);
	fclose(stdout);
	return 0;
}