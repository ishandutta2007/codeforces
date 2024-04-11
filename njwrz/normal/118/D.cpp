#include<bits/stdc++.h>
using namespace std;
const int mod=1e8;
int k1,k2;
int dp[105][105][2],vis[105][105][2];
int dfs(int a,int b,bool t){
	if(a==b&&a==0)return 1;
	if(vis[a][b][t])return dp[a][b][t];
	vis[a][b][t]=1;
	int re=0;
	if(t==0){
		if(a==0)return 0;
		for(int i=1;i<=k1&&i<=a;i++){
			re+=dfs(a-i,b,1);
		} 
		re%=mod;
	}else{
		if(b==0)return 0;
		for(int i=1;i<=k2&&i<=b;i++){
			re+=dfs(a,b-i,0);
		}
		re%=mod;
	}
	return dp[a][b][t]=re;
}
int main(){
	int a,b;
	cin>>a>>b>>k1>>k2;
	cout<<(dfs(a,b,0)+dfs(a,b,1))%mod;
	return 0;
}