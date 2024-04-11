#include "bits/stdc++.h"
using namespace std;
const int N = 505;
const int Q = N * N;
int n , m , k , q;
int x[Q] , y[Q] , t[Q];
int sum[N][N];
bool check(int qr){
	memset(sum , 0 , sizeof(sum));
	for(int i = 1 ; i <= q ; ++i){
		if(t[i] <= qr){
			int a = x[i];
			int b = y[i];
			++sum[a][b];
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for(int i = k ; i <= n ; ++i){
		for(int j = k ; j <= m ; ++j){
			if(sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k] == k * k){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d %d %d %d" , &n , &m , &k , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d %d" , x + i , y + i , t + i);
	}
	int l = -1;
	int r = 1e9 + 9;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	int ans = l + 1;
	if(ans > 1000000001){
		ans = -1;
	}
	printf("%d\n" , ans);
}