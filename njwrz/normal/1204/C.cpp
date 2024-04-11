#include <bits/stdc++.h>
using namespace std;
int g[105][105],a[1000005];
vector <int> ans;
int main(){
	char c;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			if(c=='0'||i==j){
				g[i][j]=1000000000;
			}else g[i][j]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	ans.push_back(a[1]);
	int last=1;
	for(int i=2;i<m;i++){
		if(g[a[last]][a[i]]+g[a[i]][a[i+1]]!=g[a[last]][a[i+1]]
			||a[last]==a[i+1]){
			ans.push_back(a[i]);last=i;
		}
	}
	ans.push_back(a[m]);
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	return 0;
}