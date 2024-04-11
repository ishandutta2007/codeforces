#include "bits/stdc++.h"
using namespace std;
const int N = 7;
const int P = 1 << N;
const int inf = 1e9 + 9;
int n;
int p;
int arr[P][P];
double dp[P << 2][P];
double prob[P << 2][P];
void build(int l , int r , int node , int depth){
	if(l == r){
		for(int i = 1 ; i <= p ; ++i){
			dp[node][i] = -inf;
			prob[node][i] = 0;
		}
		dp[node][l] = 0;
		prob[node][l] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(l , mid , node + node , depth - 1);
	build(mid + 1 , r , node + node + 1 , depth - 1);
	for(int i = l ; i <= r ; ++i){
		dp[node][i] = 0;
	}
	for(int i = l ; i <= mid ; ++i){
		for(int j = mid + 1 ; j <= r ; ++j){
			double val1 = 0;
			double val2 = 0;
			for(int k = l ; k <= mid ; ++k){
				for(int l = mid + 1 ; l <= r ; ++l){
					val1 += prob[node + node][k] * prob[node + node + 1][l] * arr[k][l] * ((k == i) ? (1 << depth) : 0);
					val2 += prob[node + node][k] * prob[node + node + 1][l] * arr[l][k] * ((l == j) ? (1 << depth) : 0);
				}
			}
			val1 /= 100;
			val2 /= 100;
			val1 += dp[node + node][i] + dp[node + node + 1][j];
			val2 += dp[node + node][i] + dp[node + node + 1][j];
			dp[node][i] = max(dp[node][i] , val1);
			dp[node][j] = max(dp[node][j] , val2);
		}
	}
	for(int i = l ; i <= mid ; ++i){
		prob[node][i] = 0;
		for(int j = mid + 1 ; j <= r ; ++j){
			prob[node][i] += prob[node + node][i] * prob[node + node + 1][j] * arr[i][j];
		}
		prob[node][i] /= 100;
	}
	for(int i = mid + 1 ; i <= r ; ++i){
		prob[node][i] = 0;
		for(int j = l ; j <= mid ; ++j){
			prob[node][i] += prob[node + node + 1][i] * prob[node + node][j] * arr[i][j];
		}
		prob[node][i] /= 100;
	}
}
int main(){
	scanf("%d" , &n);
	p = 1 << n;
	for(int i = 1 ; i <= p ; ++i){
		for(int j = 1 ; j <= p ; ++j){
			scanf("%d" , &arr[i][j]);
		}
	}
	build(1 , p , 1 , n - 1);
	double ans = 0;
	for(int i = 1 ; i <= p ; ++i){
		ans = max(ans , dp[1][i]);
	}
	printf("%.9lf\n" , ans);
}