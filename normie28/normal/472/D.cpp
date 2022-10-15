#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000000000000
ll adj[2005][2005];
vector < pair<ll,int> > adj1[2005];
vector < pair< ll,pair<int,int> > > v;
int id[2005];
ll dist1[2005];
bool mark[2005];
 
int root(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
void union1(int x,int y)
{
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}
void kruskal()
{
	for(int i=0;i<v.size();i++)
	{
		int x=v[i].second.first;
		int y=v[i].second.second;
		ll w=v[i].first;
		if(root(x)!=root(y))
		{
			union1(x,y);
			adj1[x].push_back({w,y});
			adj1[y].push_back({w,x});
		}
	}
}
void dfs(int s)
{
	mark[s]=true;
	for(int i=0;i<adj1[s].size();i++)
	{
		if(!mark[adj1[s][i].second])
		{
			if(dist1[s]+adj1[s][i].first<dist1[adj1[s][i].second])
			{
			 	dist1[adj1[s][i].second]=dist1[s]+adj1[s][i].first;
			 	dfs(adj1[s][i].second);
			}
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cin>>adj[i][j];
 
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i==j)
			{
				if(adj[i][j]!=0)
				flag=false;
			}
			else
			{
				if(adj[i][j]!=0)
				v.push_back({adj[i][j],{i,j}});
				if(adj[i][j]!=adj[j][i])
				flag=false;
			}
		}
	}
	if(!flag)
	cout<<"NO"<<endl;
	else
	{
		sort(v.begin(),v.end());
		bool flag1=true;
		for(int i=0;i<n;i++)
		id[i]=i;
		kruskal();
		for(int i=0;i<n;i++)
		{
			memset(mark,false,sizeof(mark));
			for(int j=0;j<n;j++)
			dist1[j]=inf;
			dist1[i]=0;
			dfs(i);
			for(int j=0;j<n;j++)
			{
				if(dist1[j]!=adj[i][j])
				{
					flag1=false;
					break;
				}
			}
			if(!flag1)
			break;
		}
		if(!flag1)
		cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}