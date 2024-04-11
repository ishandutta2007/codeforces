#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[1000];
int vis[1000];

bool dfs(int i,int d)
{
	if(vis[i] == -d)
		return 0;
	if(vis[i] == d)
		return 1;
	vis[i] = d;
	bool okay = 1;
	for(int j=0;j<edges[i].size();j++)
		okay &= dfs(edges[i][j],-d);
	return okay;
}

int que[1000];
int inque[1000];
int cur,len;
int N;

int bfs(int i)
{
	for(int j=0;j<N;j++)
		inque[j] = 0;
	cur = 0, len = 1;
	que[0] = i;
	inque[i] = 1;
	while(cur < len)
	{
		for(int j=0;j<edges[que[cur]].size();j++)
			if(inque[edges[que[cur]][j]] == 0)
			{
				que[len++] = edges[que[cur]][j];
				inque[edges[que[cur]][j]] = 1+inque[que[cur]];
			}
		cur++;
	}
	return inque[que[len-1]]-1;
}

int cid[1000];
int ans[1000];
void init(int n)
{
	for(int i=0;i<n;i++) cid[i] = i;
}
int find(int i)
{
	if(cid[i] == i) return i;
	return find(cid[i]);
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	cid[i] = j;
}

int main()
{
	int M;
	cin >> N>> M;
	int a,b;
	init(N);
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
		join(a,b);
	}
	for(int i=0;i<N;i++)
		if(!vis[i])
			if(!dfs(i,1))
			{
				cout << -1 << '\n';
				return 0;
			}
	for(int i=0;i<N;i++)
		ans[find(i)] = max(ans[find(i)],bfs(i));
	int tAns = 0;
	for(int i=0;i<N;i++)
		if(find(i) == i)
			tAns += ans[i];
	cout << tAns << '\n';
}