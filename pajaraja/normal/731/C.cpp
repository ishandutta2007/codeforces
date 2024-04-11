#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
map<int,int> a;
vector<int> g[200001];
int c[200001],b,k;
long long t;
bool vi[200001];
queue<long long> q;
int dfs(int s)
{
	vi[s]=true;
	a[c[s]]++;
	q.push(c[s]);
	b++;
	for(int i=0;i<g[s].size();i++)
	{
		if(!vi[g[s][i]]) dfs(g[s][i]);
	}
}
int main(int argc, char** argv) 
{
	fill(vi,vi+200001,false);
	int n,m,t1,t2,r=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&c[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vi[i])
		{
			int max=0;
			b=0;
			t++;
			dfs(i);
			while(!q.empty())
			{
				int e=q.front();
				q.pop();
				if(a[e]>max) max=a[e];
				a[e]--;
			}
			r+=b-max;
		}
	}
	printf("%d",r);
	return 0;
}