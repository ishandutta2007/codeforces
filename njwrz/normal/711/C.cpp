#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[105][105][105],a[105],p[105][105];
int main(){
	int n,m,kk;
	cin>>n>>m>>kk;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>p[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=1;k<=m;k++)
				dp[i][j][k]=1000000000000000000;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			for(int j=1;j<=i;j++){
				for(int k=1;k<=m;k++){
					for(int i1=1;i1<=m;i1++){
						dp[i][j][k]=min(dp[i][j][k],
							dp[i-1][j-(i1!=k)][i1]+p[i][k]);
					}
				}
			}
		}else{
			for(int j=1;j<=i;j++){
				for(int k=1;k<=m;k++){
					if(a[i]==k){
						dp[i][j][a[i]]=min(dp[i-1][j][a[i]]
							,dp[i][j][a[i]]);
					}else{
						dp[i][j][a[i]]=min(dp[i-1][j-1][k]
							,dp[i][j][a[i]]);
					}
				}
			}
		}
	}
	ll ans=10000000000000000;
	for(int i=1;i<=m;i++)ans=min(ans,dp[n][ kk][i]);
	if(ans<10000000000000000){
		cout<<ans;
	}else cout<<-1;
	return 0;
}