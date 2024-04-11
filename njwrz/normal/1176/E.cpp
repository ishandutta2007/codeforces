#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int a[200005];
vector<int> v[200005],t1,t2;
int n;
void dfs(int p,int color){
	if(a[p])return;
	a[p]=color;
	if(color==1)t1.push_back(p);else t2.push_back(p);
	for(int i=0;i<v[p].size();i++)dfs(v[p][i],3-color);
}
void solve(){
	int m;
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=n;i++){
		a[i]=0;v[i].clear();
	}
	for(int i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	t1.clear();
	t2.clear();
	dfs(1,1);
	if(t1.size()>t2.size()){
		cout<<t2.size()<<'\n';
		for(int i=0;i<t2.size();i++)cout<<t2[i]<<' ';
	}else {
		cout<<t1.size()<<'\n';
		for(int i=0;i<t1.size();i++)cout<<t1[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	int q;
	cin>>q;
	while(q--)solve();
	return 0;
}