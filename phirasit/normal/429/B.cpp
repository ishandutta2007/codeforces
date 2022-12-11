#include <stdio.h>

#define N 1010

int dp1[N][N],dp2[N][N];
int dp3[N][N],dp4[N][N];
int arr[N][N];
int n,m;

int max(int a,int b) {
	if(a > b) {
		return a;
	}else {
		return b;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n ; i++) {
		for(int j = 1 ; j <= m ;j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i = 1; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
			if(i == 1 && j == 1) {
				dp1[i][j] = arr[i][j];
			}else if(j == 1) {
				dp1[i][j] = arr[i][j] + dp1[i-1][j];
			}else if(i == 1) {
				dp1[i][j] = arr[i][j] + dp1[i][j-1];
			}else {
				dp1[i][j] = arr[i][j] + max(dp1[i-1][j] ,dp1[i][j-1]);
			}
		}
	}
	for(int i = n; i > 0 ; i--) {
		for(int j = 1 ; j <= m ; j++) {
			if(i == n && j == 1) {
				dp2[i][j] = arr[i][j];
			}else if(j == 1) {
				dp2[i][j] = arr[i][j] + dp2[i+1][j];
			}else if(i == n) {
				dp2[i][j] = arr[i][j] + dp2[i][j-1];
			}else {
				dp2[i][j] = arr[i][j] + max(dp2[i+1][j] ,dp2[i][j-1]);
			}
		}
	}
	for(int i = 1; i <= n ; i++) {
		for(int j = m ; j > 0 ;j--) {
			if(i == 1 && j == m) {
				dp3[i][j] = arr[i][j];
			}else if(j == m) {
				dp3[i][j] = arr[i][j] + dp3[i-1][j];
			}else if(i == 1) {
				dp3[i][j] = arr[i][j] + dp3[i][j+1];
			}else {
				dp3[i][j] = arr[i][j] + max(dp3[i-1][j] ,dp3[i][j+1]);
			}
		}
	}
	for(int i = n ; i > 0 ; i--) {
		for(int j = m ; j > 0 ; j--) {
			if(i == n && j == m) {
				dp4[i][j] = arr[i][j];
			}else if(j == m) {
				dp4[i][j] = arr[i][j] + dp4[i+1][j];
			}else if(i == n) {
				dp4[i][j] = arr[i][j] + dp4[i][j+1];
			}else {
				dp4[i][j] = arr[i][j] + max(dp4[i+1][j] ,dp4[i][j+1]);
			}
		}
	}
	int ans = 0;
	for(int i = 2; i < n ; i++) {
		for(int j = 2; j < m ; j++) {
			int a = dp1[i-1][j] + dp4[i+1][j] + dp2[i][j-1] + dp3[i][j+1];
			int b = dp1[i][j-1] + dp4[i][j+1] + dp2[i+1][j] + dp3[i-1][j];
			if(a > ans) ans = a;
			if(b > ans) ans = b;
		}
	}
	printf("%d\n",ans);
	return 0;
}