#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int R = N * 105;
int n , r;
int f[N] , s[N] , per[N];
double p[N];
double dp[N][R];
int calc[N][R];
int tc;
double dp10;
double solve(int pos , int tim){
	if(tim > r){
		return dp10;
	}
	if(pos > n){
		return 0;
	}
	if(calc[pos][tim] == tc){
		return dp[pos][tim];
	}
	double res = dp10;
	res = min(res , (solve(pos + 1 , tim + f[pos]) + f[pos]) * p[pos] + (solve(pos + 1 , tim + s[pos]) + s[pos]) * (1 - p[pos]));
	calc[pos][tim] = tc;
	return dp[pos][tim] = res;
}
bool check(double val){
	dp10 = val;
	++tc;
	return solve(1 , 0) < dp10;
}
int main(){
	scanf("%d %d" , &n , &r);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , f + i , s + i , per + i);
		p[i] = (1.0 * per[i]) / 100.0;
	}
	double l = 0;
	double r = 1e9 + 9;
	for(int i = 0 ; i < 60 ; ++i){
		double mid = (l + r) / 2;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	printf("%.9lf\n" , (l + r) / 2.0);
}