#include <bits/stdc++.h>
using namespace std;
vector <int> a[100005],ansa,ansb;
int n;
int vis[100005];bool f=1;
void dfs(int p,int color){
	if(vis[p]!=0){
		if(vis[p]!=color){
			f=0;return ;
		}else{
			return;
		}
	}
	vis[p]=color;
	if(color==1){
		ansa.push_back(p);
	}else{
		ansb.push_back(p);
	}
	for(int i=0;i<a[p].size();i++){
		dfs(a[p][i],3-color);
	}
}
int main(){
	cin>>n;int m;
	cin>>m;
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&a[i].size()){
			dfs(i,1);
			if(!f){
				cout<<-1;return 0;
			}
		}
	}
	cout<<ansa.size()<<'\n';
	for(int i=0;i<ansa.size();i++){
		cout<<ansa[i]<<' ';
	}
	cout<<'\n';
	cout<<ansb.size()<<'\n';
	for(int i=0;i<ansb.size();i++){
		cout<<ansb[i]<<' ';
	}
	return 0;
}