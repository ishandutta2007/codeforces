#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int eend[10000];
int weight[10000];
vector<vector<int> > edges;
bool vis[5000];
int par[5000];
int cap[5000];
int remcap[5000];

int pr[5000];
int loc[5000];
int pid[5000];
int ans[5000];

void dfs(int i,int p,int c)
{
	par[i] = p;
	cap[i] = c;
	vis[i] = 1;
	for(int j=0;j<edges[i].size();j++)
		if(!vis[eend[edges[i][j]]])
			dfs(eend[edges[i][j]],i,weight[edges[i][j]]);
}

bool cmp(int a,int b)
{
	return pr[a]<pr[b];
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&pr[i]);
		edges.push_back(vector<int>());
	}
	int a,b,c;
	for(int i=1;i<N;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		a--,b--;
		edges[a].push_back(2*i);
		eend[2*i] = b;
		weight[2*i] = c;
		edges[b].push_back(2*i+1);
		eend[2*i+1] = a;
		weight[2*i+1] = c;
	}
	dfs(0,-1,-1);
	for(int i=0;i<N;i++)
	{
		loc[i] = i;
		pid[i] = i;
	}
	sort(pid,pid+N,cmp);
	int cur;
	int *ip;
	for(int i=0;i<N;i++)
		ans[i] = 1000000;
	bool atDest = 0;
	for(int i=0;(!atDest);i++)
	{
		atDest = 1;
		for(int j=0;j<N;j++)
			remcap[j] = cap[j];
		for(int j=0;j<N;j++)
		{
			cur = pid[j];
			ip = loc+cur;
			if((*ip)==0)
				ans[cur] = min(ans[cur],i);
			else if(remcap[*ip]>0)
			{
				remcap[*ip]--;
				*ip = par[*ip];
				atDest = 0;
			}
		}
	}
	for(int i=0;i<(N-1);i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[N-1]);
	return 0;
}