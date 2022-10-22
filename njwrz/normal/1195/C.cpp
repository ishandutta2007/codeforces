#include<iostream>
using namespace std;
long long n,a[100001][2],dp[100001][2];
long long dfs(long long p,long long l){
	if(p>=n)return 0; 
	if(dp[p][l])return dp[p][l];
	if(p==n-1)return dp[p][l]=a[p][l];
	return dp[p][l]=a[p][l]+max(dfs(p+1,1-l),dfs(p+2,1-l));
}
int main(){
	cin>>n;
	for(long long i=0;i<n;i++)cin>>a[i][0];
	for(long long i=0;i<n;i++)cin>>a[i][1];
	cout<<max(dfs(0,0),dfs(0,1));
	return 0;
}