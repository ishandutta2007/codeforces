#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;
vector<int> g[100001];
bool vi[100001];
int bfs(int s)
{
	queue<int> bfsq;
	bfsq.push(s);
	vi[s]=true;
	int u,v,k=0,t=1;
	while(!bfsq.empty())
	{
		u=bfsq.front();
		bfsq.pop();
		for(int i=0;i<g[u].size();i++)
		{
			k++;
			v=g[u][i];
			if(!vi[v])
			{
				t++;
				bfsq.push(v);
				vi[v]=true;
			}
		}
	}
	if(t==k/2+1) 
	{
	    return 1;
	}
	return 0;
}
int main(int argc, char** argv) 
{
	fill(vi,vi+100001,false);
	int z=0,n,m,tmp1,tmp2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&tmp1,&tmp2);
		g[tmp1].push_back(tmp2);
		g[tmp2].push_back(tmp1);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vi[i])
		{
			z+=bfs(i);
		}
	}
	printf("%d",z);
	return 0;
}