#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1e5+1e3+7;

vector<int>e[N];

int n,ans[N],dep[N];

void dfs(int i,int f)
{
	for(int j=0;j<e[i].size();j++)
	{
		int v=e[i][j];
		if(v==f)
			continue;
		dep[v]=dep[i]+1;
		dfs(v,i);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		e[x].push_back(i);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans[dep[i]]+=1,ans[dep[i]]%=2;
	int Ans=0;
	for(int i=0;i<=n;i++)
		Ans+=ans[i];
	printf("%d",Ans);
}