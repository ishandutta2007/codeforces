# include <cstdio>
# include <vector>
# include <cassert>
# include <cstdlib>

using namespace std;

int coin[300];
vector<int>adjlist[300];
int indeg[300];

char seen[300];
int depth[300],parsum[300];

int dfs(int i,int d)
{
	seen[i]=true;
	parsum[i]=d+coin[i];
	assert(adjlist[i].size()<2);
	if(adjlist[i].size()==0)return depth[i]=1;
	int v=adjlist[i][0];
	if(seen[v])
	{
		printf("0\n");
		exit(0);
	}
	return depth[i]=dfs(v,parsum[i])+1;
}

int sol[301][100001];

int main()
{
	int N,Q,T;
	scanf("%d%d%d",&N,&Q,&T);
	
	for(int i=0;i<N;i++)
		scanf("%d",coin+i);

	for(int i=0;i<Q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adjlist[--a].push_back(--b);
		indeg[b]++;
	}

	for(int i=0;i<N;i++)
		if(indeg[i]==0)dfs(i,0);

	for(int i=0;i<N;i++)
	{
		if(depth[i]==0)
		{
			printf("0\n");
			return 0;
		}
		T-=(depth[i]-1)*coin[i];
		if(T<0)
		{
			printf("0\n");
			return 0;
		}
	}

	const int MOD=1000000007;
	sol[0][0]=1;
	for(int i=1;i<=N;i++)
	{
		sol[i][0]=1;
		for(int j=1;j<=T;j++)
		{
			sol[i][j]=sol[i-1][j];
			if(parsum[i-1]<=j)sol[i][j]+=sol[i][j-parsum[i-1]];
			if(sol[i][j]>=MOD)sol[i][j]-=MOD;
		}
	}
	printf("%d\n",sol[N][T]);
}