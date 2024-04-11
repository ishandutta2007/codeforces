#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
const long long inf = 1e17 + 17;
int n , m;
int x[N];
pair < int , int > arr[N];
long long sum[N];
void pre(int j){
	sum[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		sum[i] = sum[i - 1] + max(x[i] - arr[j].first , arr[j].first - x[i]);
	}
}
long long dp[2][N];
void compute(int l , int r , int ql , int qr , int j){
	if(l > r){
		return;
	}
	int mid = l + r >> 1;
	int opt = mid - 1;
	long long val = dp[!(j & 1)][mid] + sum[mid - 1];
	int mx = min(n , mid + arr[j].second - 1);
	for(int i = max(mid , ql) ; i <= min(qr , mx) ; ++i){
		long long tmp = sum[i] + dp[!(j & 1)][i + 1];
		if(tmp < val){
			val = tmp;
			opt = i;
		}
	}
	dp[j & 1][mid] = val - sum[mid - 1];
	compute(l , mid - 1 , ql , opt , j);
	compute(mid + 1 , r , opt , qr , j);
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , x + i);
	}
	sort(x + 1 , x + 1 + n);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &arr[i].first , &arr[i].second);
	}
	sort(arr + 1 , arr + 1 + m);
	for(int i = 1 ; i <= n ; ++i){
		dp[!(m & 1)][i] = inf;
	}
	dp[!(m & 1)][n + 1] = 0;
	for(int j = m ; j >= 1 ; --j){
		pre(j);
		compute(1 , n , 1 , n , j);
	}
	if(dp[1][1] >= inf){
		dp[1][1] = -1;
	}
	printf("%lld\n" , dp[1][1]);
}