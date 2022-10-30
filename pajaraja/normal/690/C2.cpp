#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
vector<int> g[100001];
int sol;
bool t,vi[100001];
int dfs(int s)
{
	int t1=0,max1=0,max2=0;
	vi[s]=true;
	for(int i=0;i<g[s].size();i++)
	{
		if(!vi[g[s][i]]) 
		{
		t1=dfs(g[s][i]);
		if(t1>max1)
		{
			max2=max1;
			max1=t1;
		}
		else if(t1>max2) max2=t1; 
	    }
	}
	sol=max(sol,max1+max2);
	return max1+1;
}
int main(int argc, char** argv) 
{
	sol=0;
	fill(vi,vi+1001,false);
	int n,m,t1,t2,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(1); 
	printf("%d",sol);
	return 0;
}