#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int t[100001];
struct edge
{
	int k,w;
};
vector<edge> g[100001];
int dfs(int s,int te,int f, bool masinazaslaninu)
{
	int r=0;
	if(!masinazaslaninu) r++;
	for(int i=0;i<g[s].size();i++)
	{
		if(g[s][i].k!=f)
		{
			if(g[s][i].w+te>t[g[s][i].k])
			{
				r+=dfs(g[s][i].k,0,s,false);
			}
			else
			{
			    if(g[s][i].w+te<0)
			    {
				    r+=dfs(g[s][i].k,0,s,masinazaslaninu);
		        }
		        else
		        {
		        	r+=dfs(g[s][i].k,g[s][i].w+te,s,masinazaslaninu);
				}
		    }
		}
	}
	return r;
}
int main(int argc, char** argv) 
{
	int n,t1,t2,r;
	edge e;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
	}
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&t1,&t2);
		e.w=t2;
		e.k=t1;
		g[i].push_back(e);
		e.k=i;
		g[t1].push_back(e);
	}
	r=dfs(1,0,0,true);
	printf("%d",r);
	return 0;
}