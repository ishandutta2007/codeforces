#include <bits/stdc++.h>
using namespace std;
int get_dist(int x)
{
	cout<<"d "<<x<<endl;
	int u; cin>>u;
	return u;
}
int get_2nd(int x)
{
	cout<<"s "<<x<<endl;
	int u; cin>>u;
	if (u==-1) exit(0);
	return u;
}
void answer(int x)
{
	cout<<"! "<<x<<endl;
	exit(0);
}
int gr[200001],sz[200001],dep[200001],n,m,i,j,k,t,t1,u,v,a,b,depx;
vector<int> gt[200001],gtd[200001];
vector<int> lis[200001];
void dfs_init(int x , int d)
{
	sz[x]=1;
	dep[x]=d;
	for (int g  : gt[x]) if (!sz[g])
	{
		gtd[x].push_back(g);
		dfs_init(g,d+1);
		sz[x]+=sz[g];
	}
}
void dfs_calc(int x, int d)
{
	gr[x]=d;
	lis[d].push_back(x);
	sort(gtd[x].begin(),gtd[x].end(),[](int a, int b){
		return (sz[a]>sz[b]);
	});
	for (int i=0;i<gtd[x].size();i++)
	{
		if (i==0) dfs_calc(gtd[x][i],d);
		else 
		{
			t++;
			dfs_calc(gtd[x][i],t);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	dfs_init(1,0);
	t=1;
	dfs_calc(1,1);
	u=1;
	depx=get_dist(1);
	if (depx==0) answer(1);
	while (true)
	{
		if (lis[gr[u]].size()==1) answer(u);
		a=lis[gr[u]][lis[gr[u]].size()-1];
		v=get_dist(a);
		if (depx+v==dep[a]) answer( lis[gr[u]][depx-dep[u]]);
		u=lis[gr[u]][(depx+dep[a]-v)/2-dep[u]];
		u=get_2nd(u);
	}
}