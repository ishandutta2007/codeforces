#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

vector<int>ans[N];

int ne[N],r[N],a[N],n,f,vis[N];

bool cmp(int x,int y)
{
	return a[x]<a[y];
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],r[i]=i;
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=n;i++)
		ne[r[i]]=i;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			f++;
			for(int j=i;!vis[j];j=ne[j])
				ans[f].push_back(j),vis[j]=true;
		}
	}
	cout<<f<<endl;
	for(int i=1;i<=f;i++)
	{
		cout<<ans[i].size()<<" ";
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}