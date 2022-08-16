# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>

using namespace  std;

vector<int> adjlist[3000];

short minturn[3000][3000];
int toreverse[3000];
int stack[3000];
int neigh[3000];
char seen[3000];
int pb[3000];

int sol=3000;

void dfs1(int u,int root)
{
	pb[u]=0;
	seen[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i],w=0;
		if(v<0)
		{
			v=-1-v;
			w=1;
		}
		if(seen[v])continue;
		
		pb[u]+=w;
		toreverse[v]=toreverse[u]+w;
		minturn[root][v]=min(toreverse[u],minturn[root][u]+1-w);
		
		dfs1(v,root);
		pb[u]+=pb[v];
	}
}

void dfs2(int u,int root,int overhead)
{
	seen[u]=1;
	sol=min(sol,pb[u]+overhead+minturn[root][u]);
	
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i],w=0;
		if(v<0)v=-1-v,w=1;
		if(!seen[v])dfs2(v,root,overhead+pb[u]-pb[v]-w);
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	
	for(int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		adjlist[u].push_back(v);
		adjlist[v].push_back(-1-u);
	}

	for(int i=0;i<N;i++)
	{
		toreverse[i]=0;
		memset(seen,0,N);
		dfs1(i,i);
		memset(seen,0,N);
		dfs2(i,i,0);
	}

	printf("%d\n",sol);

	return 0;
}