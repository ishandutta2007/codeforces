#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 9;
int n , k;
int arr[N];
bool dp[2][N][N];
set < int > res;
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	sort(arr + 1 , arr + 1 + n);
	res.clear();
	memset(dp , 0 , sizeof(dp));
	dp[0][0][0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		int cur = i & 1;
		int pre = !cur;
		for(int j = 0 ; j <= k ; ++j){
			for(int l = 0 ; l <= k ; ++l){
				dp[cur][j][l] = dp[pre][j][l];
				if(j >= arr[i]){
					dp[cur][j][l] |= dp[pre][j - arr[i]][l];
					//cout << cur << " " << j << " " << l << " " << dp[cur][j][l] << endl;
				}
				if(min(l , j) >= arr[i]){
					//cout << "BC\n";
					dp[cur][j][l] |= dp[pre][j - arr[i]][l - arr[i]];
					//cout << "WTF\n";
				}	
			}
		}
	}
	for(int i = 0 ; i <= k ; ++i){
		if(dp[n & 1][k][i]){
			res.insert(i);
		}
	}
	printf("%d\n" , int(res.size()));
	for(int x : res){
		printf("%d " , x);
	}
}