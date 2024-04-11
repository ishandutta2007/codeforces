#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , l;
int x[N];
int b[N];
double dp[N];
int nxt[N];
bool check(double r , bool print){
	dp[n] = 0;
	nxt[n] = n + 1;
	for(int i = n - 1 ; i >= 0 ; --i){
		nxt[i] = n;
		dp[i] = sqrt(abs(x[n] - x[i] - l)) - r * b[n];
		for(int j = i + 1 ; j < n ; ++j){
			double tmp = dp[j] + sqrt(abs(x[j] - x[i] - l)) - r * b[j];
			if(tmp < dp[i]){
				dp[i] = tmp;
				nxt[i] = j;
			}
		}
	}
	if(print){
		int cur = nxt[0];
		while(cur <= n){
			printf("%d " , cur);
			cur = nxt[cur];
		}
	}
	return dp[0] <= 0;
}
int main(){
	scanf("%d %d" , &n , &l);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , x + i , b + i);
	}
	double l = 0.0;
	double r = 1e3 + 3;
	for(int i = 0 ; i < 40 ; ++i){
		double mid = (l + r) / 2;
		if(check(mid , 0)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	check((l + r) / 2 , 1);
}