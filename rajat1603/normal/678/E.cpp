#include "bits/stdc++.h"
using namespace std;
const int N = 20;
int n;
double arr[N][N];
double dp[1 << N];
bool calc[1 << N];
double solve(int mask){
	if(calc[mask]){
		return dp[mask];
	}
	if(__builtin_popcount(mask) == 1){
		if(mask & 2){
			return 1.0;
		}
		else{
			return 0.0;
		}
	}
	double res = 0.0;
	for(int i = 1 ; i <= n ; ++i){
		if(mask & (1 << i)){
			for(int j = 1 ; j <= n ; ++j){
				if(j != i && (mask & (1 << j))){
					int nmask1 = mask ^ (1 << j);
					int nmask2 = mask ^ (1 << i);
					res = max(res , solve(nmask1) * arr[i][j] + solve(nmask2) * arr[j][i]);
				}
			}
		}
	}
	calc[mask] = 1;
	return dp[mask] = res;
}
int main(){
	scanf("%d" , &n);
	int tmp = 0;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			scanf("%lf" , &arr[i][j]);
		}
		tmp |= (1 << i);
	}
	printf("%.9lf\n" , solve(tmp));
}