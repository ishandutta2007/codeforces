#include <bits/stdc++.h>
using namespace std;
int f[100005];
vector<int> v[100005];
int n,ans;
void dfs(int p){
	for(int i=0;i<v[p].size();i++){
		if(!f[v[p][i]]){
			f[v[p][i]]=1;
			ans++;
			dfs(v[p][i]);
		}
	}
}
int main(){
	int x,y,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			dfs(i);
		}
	}
	cout<<m-ans;
	return 0;
}