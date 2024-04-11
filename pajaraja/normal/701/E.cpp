#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int f[200001],c[200001],k;
long long r;
bool p[200001];
vector<int> g[200001];
void dfs(int s)
{
	if(p[s]) c[s]++;
	for(int i=0;i<g[s].size();i++)
	{
		if(g[s][i]!=f[s]) 
		{
			f[g[s][i]]=s;
		    dfs(g[s][i]);
		    c[s]+=c[g[s][i]];
		}
	}
	if(s!=1) r+=c[s]<k?c[s]:2*k-c[s];
}
int main(int argc, char** argv) 
{
	f[1]=0;
	fill(c,c+200001,0);
	fill(p,p+200001,false);
	r=0;
	int n,t1,t2;
	scanf("%d%d",&n,&k);
	for(int i=0;i<2*k;i++) 
	{
		scanf("%d",&t1);
		p[t1]=true;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(1);
	printf("%lld",r);
}