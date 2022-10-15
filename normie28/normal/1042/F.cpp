#include <bits/stdc++.h>
using namespace std;
int dep[1000001];
struct cmp
{
	int operator()(int a, int b)
	{
		if (dep[a]-dep[b]) return (dep[a]<dep[b]);
		return (a<b);
	}
};
set<int,cmp> buc[1000001];
int n,m,i,j,k,t,t1,u,v,a,b,res,root;
vector<int> gt[1000001],down[1000001];
void dfs(int x, int d)
{
	dep[x]=d;
	for (int g : gt[x]) if (!dep[g]){
		dfs(g,d+1); 
		down[x].push_back(g);
	}
}
void calc(int x)
{
	if (down[x].size()==0)
	{
		buc[x].insert(x);
	}
	else
	{
		for (int g : down[x]) calc(g);
		for (int g : down[x]) for (int gg : buc[g]) buc[x].insert(gg);
		while (buc[x].size()>=2)
		{
			auto it=buc[x].begin();
			int u=*it;
			it++;
			int v=*it;
			if (dep[u]+dep[v]-2*dep[x]<=m)
			{
				buc[x].erase(u);
			}
			else break;
		}
		res+=buc[x].size()-1;
		while(buc[x].size()>=2)
		{
			auto it=buc[x].end();
			it--;
			buc[x].erase(*it);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
	gt[u].push_back(v);
	gt[v].push_back(u);
	}
	for (i=1;i<=n;i++) if (gt[i].size()>1) break;
	dfs(i,1);
	calc(i);
	cout<<res+1;
}