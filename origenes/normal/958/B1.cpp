#include <bits/stdc++.h>
using namespace std;
const int maxn=1234;
vector<int> G[maxn];
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<n; i++){
		int u, v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		if(G[i].size()==1) ans++;
	}
	cout<<ans<<endl;
	return 0;
}