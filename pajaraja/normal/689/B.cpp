#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int d[200001];
vector<int> g[200001];
void bfs(int s)
{
	int u,v;
	queue<int> bfsq;
	d[s]=0;
	bfsq.push(s);
	while(!bfsq.empty())
	{
		u=bfsq.front();
		bfsq.pop();
		for(int i=0;i<g[u].size();i++)
		{
			v=g[u][i];
			if(d[v]==-1)
			{
				bfsq.push(v);
				d[v]=d[u]+1;
			}
		}
	}
}
int main(int argc, char** argv) 
{
	fill(d,d+200001,-1);
	int n,t1;
	scanf("%d",&n);
	for(int i=1;i<n;i++) 
	{
	g[i].push_back(i+1);
	g[i+1].push_back(i);
    }
	for(int i=1;i<n;i++) 
	{
		scanf("%d",&t1);
		g[i].push_back(t1);
	} 

	bfs(1);
	for(int i=1;i<=n;i++) printf("%d ",d[i]);
	return 0;
}