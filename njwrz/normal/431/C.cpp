#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll dp[105]={};
	dp[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m&&i>=j;j++){
			dp[i]+=dp[i-j];
			dp[i]%=1000000007;
		}
	}
	k--;
	ll p[105]={};
	p[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k&&i>=j;j++){
			p[i]+=p[i-j];
			p[i]%=1000000007;
		}
	}
	cout<<(dp[n]+1000000007-p[n])%1000000007;
	return 0;
}