#include<bits/stdc++.h>
using namespace std;
struct Bian
{
	int s,t,last;
}bian[600010];
int last[300010],maxbian=0;
void addbian(int s,int t)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
int vis[300010];
vector<int> v[300010];
int c[300010];
int k[300010];
void dfs(int i)
{
	vis[i]=1;
	int o=1;
	for(int j=0;j<v[i].size();j++)
	{
	//	cout<<c[v[i][j]]<<endl;
		if(c[v[i][j]])
			k[c[v[i][j]]]=i;
	}
	//cout<<i<<' '<<k[1]<<endl;
	for(int j=0;j<v[i].size();j++)
		if(c[v[i][j]]==0)
		{
			while(k[o]==i)
				o++;
			c[v[i][j]]=o;
			o++;
		}
	for(int j=last[i];j;j=bian[j].last)
		if(vis[bian[j].t]==0)
			dfs(bian[j].t);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int t1,t2;
		cin>>t1;
		for(int j=1;j<=t1;j++)
		{
			cin>>t2;
			v[i].push_back(t2);
		}
	}
	for(int i=1;i<n;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		addbian(t1,t2);
		addbian(t2,t1);
	}
	dfs(1);
	int mx=0;
	for(int i=1;i<=m;i++)
	{
		if(c[i]==0)
			c[i]=1;
		mx=max(mx,c[i]);
	}
	cout<<mx<<endl;
	for(int i=1;i<=m;i++)
		cout<<c[i]<<' ';
}