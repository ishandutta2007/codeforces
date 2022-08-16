# include <cstdio>
# include <set>

using namespace std;

set<int> lang[100];
char visited[100];

void dfs(int u,int N)
{
	visited[u]=true;
	for(int i=0;i<N;i++)
	{
		if(visited[i])continue;
		for(set<int>::iterator sit=lang[i].begin();sit!=lang[i].end();sit++)
		{
			if(lang[u].count(*sit))
			{
				dfs(i,N);
				break;
			}
		}
	}
}

int main()
{
	int N,M,Ktot=0;
	scanf("%d%d",&N,&M);
	
	for(int i=0;i<N;i++)
	{
		int K,L;
		scanf("%d",&K);
		Ktot+=K;
		for(int j=0;j<K;j++)
		{
			scanf("%d",&L);
			lang[i].insert(L);
		}
	}

	int ret=(Ktot==0)?0:-1;
	for(int i=0;i<N;i++)
	{
		if(!visited[i])
		{
			dfs(i,N);
			ret++;
		}
	}
	printf("%d\n",ret);
	return 0;
}