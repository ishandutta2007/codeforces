#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
vector<int> g[1001];
bool t,vi[1001];
int dfs(int s)
{
	int o=0;
	vi[s]=true;
	for(int i=0;i<g[s].size();i++)
	{
		o++;
		if(!vi[g[s][i]]) o+=dfs(g[s][i]);
	}
	return o;
}
int main(int argc, char** argv) 
{
	t=true;
	fill(vi,vi+1001,false);
	int n,m,t1,t2,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	k=dfs(1);
	bool r=true;
	for(int i=1;i<=n;i++) 
	{
	    r=r&&vi[i];
	}
	if(r&&k==(2*n-2)) printf("yes");
	else printf("no");
	return 0;
}