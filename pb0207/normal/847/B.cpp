#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2e5+1e3+7;

vector<int>ans[N];

struct node{
	int x;
};

bool operator< (node a,node b)
{
	return a.x>b.x;
}

vector<node>G;

int n,a[N],cnt;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans[cnt++].push_back(a[1]);
	G.push_back((node){a[1]});
	for(int i=2;i<=n;i++)
	{
		int now=a[i];
		int k=lower_bound(G.begin(),G.end(),(node){now})-G.begin();
		if(k>=cnt)
			G.push_back((node){now}),ans[cnt++].push_back(now);
		else
			G[k]=(node){now},ans[k].push_back(now);
	}
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}