#include<bits/stdc++.h>
#define mo 998244353
using namespace std;
int n,a[100010],dp[2][2][220],res;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	if (a[0]==-1){
		for (int i=1;i<=200;i++) dp[0][0][i]=1;
	}
	else dp[0][0][a[0]]=1;
	int now;
	for (int i=0;i<n-1;i++){
		now=i&1;
		for (int j=1;j<=200;j++){
			dp[now][0][j]=(dp[now][0][j]+dp[now][0][j-1])%mo;
			dp[now][1][j]=(dp[now][1][j]+dp[now][1][j-1])%mo;
			dp[now^1][0][j]=dp[now^1][1][j]=0;
		}
		if (a[i+1]==-1){
			for (int j=1;j<=200;j++){
				dp[now^1][0][j]=(dp[now][1][j-1]+dp[now][0][j-1])%mo;
				dp[now^1][1][j]=(((dp[now][1][200]-dp[now][1][j-1]+mo)%mo+dp[now][0][j]-dp[now][0][j-1])%mo+mo)%mo;
			}
		}
		else{
			dp[now^1][0][a[i+1]]=(dp[now][1][a[i+1]-1]+dp[now][0][a[i+1]-1])%mo;
			dp[now^1][1][a[i+1]]=(((dp[now][1][200]-dp[now][1][a[i+1]-1]+mo)%mo+dp[now][0][a[i+1]]-dp[now][0][a[i+1]-1])%mo+mo)%mo;
		}
	}
	now=(n-1)&1;
	for (int i=1;i<=200;i++) res=(res+dp[now][1][i])%mo;
	printf("%d\n",res);
}