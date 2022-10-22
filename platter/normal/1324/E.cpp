#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];
int n,h,l,r;
int arr[2005];

int ans(int ind,int t) {
	if (dp[ind][t]!=-1) {
		return dp[ind][t];
	}
	int ret=0;
	if (l<=t&&t<=r) {
		ret=1;
	}
	if (ind!=n-1)
	ret+=max(ans(ind+1,(t+arr[ind+1])%h),ans(ind+1,(t+arr[ind+1]-1)%h));
	dp[ind][t]=ret;
	return ret;
}

int main(void) {
	scanf("%d %d %d %d\n",&n,&h,&l,&r);
	for(int i=0;i<n;i++) {
		scanf("%d ",&arr[i]);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",max(ans(0,arr[0]-1),ans(0,arr[0])));
}