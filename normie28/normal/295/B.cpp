#include <bits/stdc++.h>
using namespace std;
const int MAXN = 550;
long long G[MAXN][MAXN];
long long note[MAXN],ans[MAXN];
long long dis[MAXN][MAXN];
bool vis[MAXN];
 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>G[i][j];
			dis[i][j]=G[i][j];
		}
	}
	for(int i=n;i>=1;i--){
		scanf("%d",&note[i]);
	}
	fill(vis,vis+n+1,false);
	fill(ans,ans+n+1,0);
	for(int t=1;t<=n;t++){
		int k = note[t];
		vis[note[t]]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
				if(vis[i] && vis[j]){
					ans[t]+=dis[i][j];
				}
			}
		}
	}
	for(int i=n;i>=1;i--){
		 cout<<ans[i]<<endl;
	}
}