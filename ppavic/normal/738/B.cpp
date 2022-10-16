#include <cstdio>

using namespace std;

int n,m;
int a[1005][1005];
int dp[1005][1005][4];

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(j-1 >= 0)dp[i][j][0] = dp[i][j-1][0];
			if(a[i][j]) dp[i][j][0] = 1;
		}
		for(int j = m-1;j>=0;j--){
			if(j+1 < m) dp[i][j][1] = dp[i][j+1][1];
			if(a[i][j]) dp[i][j][1] = 1;
		}
	}
	for(int j = 0;j<m;j++){
		for(int i = 0;i<n;i++){
			if(i-1 >= 0) dp[i][j][2] = dp[i-1][j][2];
			if(a[i][j]) dp[i][j][2] = 1;			
		}
		for(int i = n-1;i>=0;i--){
			if(i+1 < n) dp[i][j][3] = dp[i+1][j][3];
			if(a[i][j]) dp[i][j][3] = 1;
		}
	}
	int sol = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(a[i][j]) continue;
			int csol = sol;
			for(int k = 0;k<4;k++) sol += dp[i][j][k];

		}
	}
	printf("%d\n",sol);
	
}