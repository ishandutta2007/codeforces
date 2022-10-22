#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=3e5+1e3+7;

vector<int>e[N];

int n,x,y;

int ban[N];

vector<int>t;

void getp(int i,int f,int T)
{
	t.push_back(i);
	if(i==T)
	{
		for(int j=0;j<t.size();j++) 
			ban[t[j]]=1;
	}
	for(int j=0;j<e[i].size();j++)
	{
		int v=e[i][j];
		if(v==f)
			continue;
		getp(v,i,T);
	}
	t.pop_back();
}

int dfs(int i,int f)
{
	int ret=1;
	for(int j=0;j<e[i].size();j++)
	{
		int v=e[i][j];
		if(v==f)
			continue;
		if(ban[v])
			continue;
		ret+=dfs(v,i);
	}
	return ret;
}

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	getp(x,0,y);
	int sz1=dfs(x,0);
	int sz2=dfs(y,0);
	printf("%lld",1ll*n*(n-1)-1ll*sz1*sz2);
}