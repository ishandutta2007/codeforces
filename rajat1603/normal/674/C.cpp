#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int K = 55;
int n , k;
int arr[N];
long long tsum[N];
double p[N];
double psum[N];
double dp[K][N];
inline double cost(int i , int j){
	return p[j] * (tsum[j] - tsum[i - 1]) - (psum[j] - psum[i - 1]);
}
void compute(int i , int l , int r , int ql , int qr){
    if(r < l){
        return;
    }
    int mid = l + r >> 1;
    int idx = -1;
    double val = 1e18;
    for(int j = ql ; j <= min(qr , mid) ; ++j){
        double tmp = dp[i - 1][j - 1] + cost(j , mid);
        if(tmp < val){
            val = tmp;
            idx = j;
        }
    }
    dp[i][mid] = val;
    compute(i , l , mid - 1 , ql , idx);
    compute(i , mid + 1 , r , idx , qr);
}
int main(){
	scanf("%d %d" , &n , &k);
	//n = 2e5;
	//k = 50;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		//arr[i] = ((arr[i - 1] ^ rand()) % 100000) + 1;
	}
	p[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		p[i] = p[i - 1] + (1.0 / arr[i]);
	}
	psum[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		psum[i] = psum[i - 1] + arr[i] * p[i - 1];
	}
	tsum[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		tsum[i] = tsum[i - 1] + arr[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		dp[1][i] = cost(1 , i);
	}
	for(int i = 2 ; i <= k ; ++i){
		compute(i , 1 , n , 1 , n);
	}
	printf("%.6lf\n" , dp[k][n]);
}