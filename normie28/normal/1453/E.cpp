#include <bits/stdc++.h>
using namespace std;
vector<int> gt[200001],gt2[200001];
int dep[200001],minfin[200001];
int n,m,i,j,k,t,t1,u,v;
void dfs(int x, int d)
{
	dep[x]=d;
	for (int g : gt[x]) if (!dep[g])
	{
		dfs(g,d+1);
		gt2[x].push_back(g);
	}
}
int check(int x, int l)
{
	int res=1;
	for (int g : gt2[x]) if (!check(g,l)) res=0;
	if (gt2[x].size()==0)
	{
		minfin[x]=dep[x];
	} 
	else if (gt2[x].size()==1)
	{
		minfin[x]=minfin[gt2[x][0]];
	}
	else
	{
		int minn=1e9,u,maxx1=-1e9,maxx2=-1e9;
		for (int g : gt2[x])
		{
			u=minfin[g];
			if (u<minn) minn=u;
			if (u>maxx1)
			{
				maxx2=maxx1;
				maxx1=u;
			}
			else if (u>maxx2)
			{
				maxx2=u;
			}
		}
		if (maxx1-dep[x]+1<=l) minfin[x]=minn;
		else 
		{
			minfin[x]=maxx1;
			if (maxx2-dep[x]+1>l) res=0;
		}
	}
	if ((x==1)and(minfin[x]-dep[x]>l)) res=0;
	return res;
}
int bs(int l, int r)
{
	if (l==r) return l;
	int mid=(l+r)/2;
	if (check(1,mid)) return bs(l,mid); else return bs(mid+1,r);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		for (i=1;i<=n;i++)
		{
			gt[i].clear();
			gt2[i].clear();
			dep[i]=0;
		}
		for (i=1;i<n;i++)
		{
			cin>>u>>v;
			gt[u].push_back(v);
			gt[v].push_back(u);
		}
		dfs(1,1);
		cout<<bs(1,n)<<endl;
	}
}