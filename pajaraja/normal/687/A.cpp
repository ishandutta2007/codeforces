#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> g[100001],p,c;
int b[100001],bp,bc;
bool puko;
void dfs(int s,int k)
{
	b[s]=k;
	if(k==1)
	{
	    p.push_back(s);
	    bp++;
	}
	else 
	{
	    c.push_back(s);
	    bc++;
	}
	for(int i=0;i<g[s].size();i++)
	{
		if(b[g[s][i]]==2) dfs(g[s][i],1-k);
		else
		{
			if(b[g[s][i]]==b[s]) puko=true;
		}
	}
}
int main(int argc, char** argv) 
{
	puko=false;
	bp=bc=0;
	fill(b,b+100001,2);
	int n,m,t1,t2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	for(int i=1;i<=n;i++) if(b[i]==2) dfs(i,0);
	if(puko)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n",bp);
	for(int i=0;i<p.size();i++) printf("%d ",p[i]);
	printf("\n%d\n",bc);
	for(int i=0;i<c.size();i++) printf("%d ",c[i]);
	return 0;
}