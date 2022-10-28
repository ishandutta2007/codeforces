#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
const int K = 11;
int n , m , k;
char a[N];
char b[N];
int dp[N][N][K][2];
int solve(int pos1 , int pos2 , int kleft , bool taken){
	if(kleft < 0){
		return -1e6;
	}
	if(pos1 > n || pos2 > m){
		if(taken){
			--kleft;
		}
		if(kleft){
			return -1e6;
		}
		return 0;
	}
	if(dp[pos1][pos2][kleft][taken] != -1){
		return dp[pos1][pos2][kleft][taken];
	}
	int res = -1e6;
	if(taken){
		if(a[pos1] == b[pos2]){
			res = max(res , 1 + solve(pos1 + 1 , pos2 + 1 , kleft , 1));
		}
		res = max(res , solve(pos1 , pos2 , kleft - 1 , 0));
	}
	else{
		if(a[pos1] == b[pos2]){
			res = max(res , 1 + solve(pos1 + 1 , pos2 + 1 , kleft , 1));
		}
		res = max(res , solve(pos1 + 1 , pos2 , kleft , 0));
		res = max(res , solve(pos1 , pos2 + 1 , kleft , 0));
	}
	return dp[pos1][pos2][kleft][taken] = res;
}
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	scanf("%s" , a + 1);
	scanf("%s" , b + 1);
	memset(dp , -1 , sizeof(dp));
	cout << solve(1 , 1 , k , 0);
}