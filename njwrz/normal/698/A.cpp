#include<bits/stdc++.h>
using namespace std;
int n,dp[100][3],a[100];
int hd[4][2]{
	0,0,
	0,1,
	1,0,
	1,1,
};
int dfs(int p,int last){
	int mini=100000000;
	if(p==n)return 0;
	if(dp[p][last]!=0)return dp[p][last];
	if(hd[a[p]][0]){
		if(last!=1)mini=min(mini,dfs(p+1,1));
	}
	if(hd[a[p]][1]){
		if(last!=2)mini=min(mini,dfs(p+1,2));
	}
	if(mini==100000000){
		return dp[p][last]=dfs(p+1,0)+1;
	}else return dp[p][last]=mini;
}
int main(){
	int i;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	cout<<dfs(0,0);
	return 0;
}