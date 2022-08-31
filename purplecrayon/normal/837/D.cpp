#include<bits/stdc++.h>
using namespace std;
const int N=201;
long long n,k,dp[N][N*30],t,f,j,i,ans,x;
int main(){
	cin>>n>>k;
	memset(dp,-1,sizeof dp);
	dp[0][0]=0;
	for(int s=0;s<n;s++){
		cin>>x;
		t=f=0;
		while(x%2==0)t++,x/=2;
		while(x%5==0)f++,x/=5;
		for(i=k-1;i>=0;i--)
			for(j=0;j<N*30;j++)
				if(~dp[i][j])
					dp[i+1][j+f]=max(dp[i+1][j+f],dp[i][j]+t);
		
	}
	for(j=0;j<N*30;j++)ans=max(ans,min(j,dp[k][j]));
	cout<<ans<<endl;
}