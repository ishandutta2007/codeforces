#include <bits/stdc++.H>
 
using namespace std;
 
int main(){
    string s;
    cin>>s;
	int n=s.size();
	
	int dp[n][n];
	for(int L=1;L<=n;L++){
		for(int i=0;i<n;i++){
			int j=i+L-1;
			if(j>=n) break;
			dp[i][j]=0;
			if(L==1) dp[i][j]=1;
			else{
				if(s[i]!=s[j]) continue;
				if(L==2) dp[i][j]=1;
				else dp[i][j]=dp[i+1][j-1];
			}
		}
	}
	
	long long dp1[n]={},dp2[n]={};
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<=i;j++){
			sum+=dp[j][i];
		}
		dp1[i]=sum;
	}
	for(int i=n-1;i>=0;i--){
		int sum=0;
		for(int j=n-1;j>=i;j--){
			sum+=dp[i][j];
		}
		dp2[i]=sum;
	}
	
	long long res=0;
	for(int i=0;i<n-1;i++){
		long coef=0;
		for(int j=i+1;j<n;j++){
			coef+=dp2[j];
		}
		res+=coef*dp1[i];
	}
	cout<<res;
}