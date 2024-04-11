#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edges[500000];

vector<int> ans[500000];
int cnt = 0;

int prev[500000],nxt[500000];
bool vis[500000];
int fst;
int N,M,a,b;

void rem(int i)
{
	if(prev[i]!=-1) nxt[prev[i]] = nxt[i];
	else fst = nxt[i];
	if(nxt[i]!=N) prev[nxt[i]] = prev[i];
}

void dfs(int i)
{
	ans[cnt].push_back(i);
	vis[i] = 1;
	vector<int> v;
	int j = 0;
	for(int cur=fst;cur!=N;cur=nxt[cur])
	{
		while(j<edges[i].size() && edges[i][j]<cur)
			j++;
		if(j==edges[i].size() || edges[i][j]>cur)
		{
			rem(cur);
			v.push_back(cur);
		}
	}
	for(int j=0;j<v.size();j++)
		dfs(v[j]);
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i=0;i<N;i++)
		sort(edges[i].begin(),edges[i].end());
	for(int i=0;i<N;i++)
	{
		prev[i] = i-1, nxt[i] = i+1;
	}
	fst = 0;
	for(int i=0;i<N;i++)
		if(!vis[i])
		{
			rem(i);
			dfs(i);
			cnt++;
		}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
	{
		printf("%d",ans[i].size());
		for(int j=0;j<ans[i].size();j++)
			printf(" %d",ans[i][j]+1);
		printf("\n");
	}
}