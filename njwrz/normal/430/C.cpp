#include <bits/stdc++.h>
using namespace std;
queue<int> ans;
int a[100005],b[100005];
vector<int> v[100005];
int n,vis[100005];
void dfs(int p,bool f1,bool f2,bool d){
	if(vis[p])return;
	vis[p]=1;
	if(f1&&!d)a[p]=1-a[p];
	if(f2&&d)a[p]=1-a[p];
	if(a[p]!=b[p]){
		ans.push(p);
		a[p]=1-a[p];
		if(d)f2=1-f2;else f1=1-f1;
	}
	for(int i=0;i<v[p].size();i++)dfs(v[p][i],f1,f2,1-d);
}
int main(){
	int x,y;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		if(y<x)swap(x,y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	dfs(1,0,0,0);
	cout<<ans.size()<<'\n';
	while(!ans.empty()){
		int t=ans.front();
		ans.pop();
		cout<<t<<'\n';
	}
	return 0;
}