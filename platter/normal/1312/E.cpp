#include <bits/stdc++.h>
using namespace std;

int dp[500][500];
int dp1[500][500];
int n;
int arr[500];

int ans(int l,int r) {
	if (dp[l][r]!=0) {
		return dp[l][r];
	}
	if (l==r) {
		dp[l][r]=arr[l];
		return dp[l][r];
	}
	for(int i=l;i<r;i++) {
		if (ans(l,i)!=-1&&ans(i+1,r)!=-1&&ans(l,i)==ans(i+1,r)) {
			dp[l][r]=ans(l,i)+1;
			return dp[l][r];
		}
	}
	dp[l][r]=-1;
	return -1;
}

int len(int l,int r) {
	if (dp1[l][r]!=0) {
		return dp1[l][r];
	}
	if (ans(l,r)!=-1) {
		dp1[l][r]=1;
		return 1;
	}
	int ret=1e5;
	for(int i=l;i<=r;i++) {
		if (ans(l,i)!=-1) {
			ret=min(ret,len(i+1,r)+1);
		}
	}
	dp1[l][r]=ret;
	return ret;
}

int main(void) {
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		scanf("%d ",&arr[i]);
	}
	printf("%d",len(0,n-1));
}