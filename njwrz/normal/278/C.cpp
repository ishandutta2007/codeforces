#include <bits/stdc++.h>
using namespace std;
vector <int> v[300];
int f[300];
void dfs(int p){
	if(f[p])return ;
	f[p]=1;
	for(int i=0;i<v[p].size();i++){
		dfs(v[p][i]);
	}
}
int main(){
	int x,a,n,m,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;if(x)b=-1;
		for(int j=1;j<=x;j++){
			cin>>a;
			v[a+110].push_back(i);
			v[i].push_back(a+110);
		}
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			b++;
			dfs(i);
		}
	}
	cout<<b;
	return 0;
}