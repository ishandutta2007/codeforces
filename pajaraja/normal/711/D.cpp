#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
vector <int> g[200001];
int tu,w,aaa,tmp[200001];
long long st[200001],dist[200001],r=1,p=1;
bool vi[200001];
void dfs(int s,int f)
{
	tu++;
	vi[s]=true;
	for(int i=0;i<g[s].size();i++) 
	{
	    if(g[s][i]!=f)
		{
			if(vi[g[s][i]]) w=s;
		    else dfs(g[s][i],s);
		}
	}
}
void dfsprim(int s,int f, int d)
{
	dist[s]=d;
	for(int i=0;i<g[s].size();i++) 
	{
	    if(g[s][i]!=f) 
		{
			if(dist[g[s][i]]==0) aaa=d+1;
		    else dfsprim(g[s][i],s,d+1);
		}
	}
}
int main(int argc, char** argv) 
{
	fill(vi,vi+200001,false);
	fill(dist,dist+200001,-1);
	st[0]=1;
	for(int i=1;i<200001;i++) 
	{
	    st[i]=2*st[i-1]%MOD;
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp[i]);
		g[i].push_back(tmp[i]);
		g[tmp[i]].push_back(i);
    }
	for(int i=1;i<=n;i++)
	{
		if(!vi[i])
		{
			if(tmp[tmp[i]]==i)
			{
				tu=0;
				dfs(i,0);
				r=r*st[tu-1]%MOD;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vi[i])
		{
			tu=0;
			dfs(i,0);
			dfsprim(w,0,0);
			r=r*((st[aaa]-2)*st[tu-aaa]%MOD)%MOD;
		}
	}
	printf("%I64d",r);
	return 0;
}