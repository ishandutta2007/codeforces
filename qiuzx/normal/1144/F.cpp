#include <bits/stdc++.h>
#define N 200010
#define F first
#define S second
using namespace std;
int n,m;
vector<pair<int,int> > vt[N],ed;
vector<int> ans;
bool book[N],ver[N];
void dfs(int x)
{
	book[x]=true;
	int i,t;
	for(i=0;i<vt[x].size();i++)
	{
		t=vt[x][i].F;
		if(book[t])
		{
			continue;
		}
		book[t]=true;
		ver[t]=!ver[x];
		dfs(t);
	}
}
int main(){
	int i,x,y;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		ed.push_back(make_pair(x,y));
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
	}
	dfs(0);
	for(i=0;i<m;i++)
	{
		if(ver[ed[i].F]==ver[ed[i].S])
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(ver[ed[i].F]==false)
		{
			ans.push_back(1);
		}
		else
		{
			ans.push_back(0);
		}
	}
	cout<<"YES"<<endl;
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}