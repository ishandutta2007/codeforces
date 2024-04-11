#include "bits/stdc++.h"
using namespace std;
const int N = 20;
int n , k;
double arr[N];
int idxx;
double dp[1 << N];
vector < int > masks;
double Solve(int idx){
	idxx = idx;
	for(auto mask : masks){
		double res = 0;
		double sum = 0;
		int pc = __builtin_popcount(mask);
		for(int i = 0 ; i < n ; ++i){
			if((mask | (1 << i)) == mask){
				sum += arr[i];
			}
			else{
				int nmask = mask | (1 << i);
				if(pc + 1 == k){
					res += ((nmask >> idx) & 1) * arr[i];
				}
				else{
					res += dp[nmask] * arr[i];
				}
			}
		}
		res *= 1.0 / (1.0 - sum);
		dp[mask] = res;
	}
	return dp[0];
}
int main(){
	scanf("%d %d" , &n , &k);
	int nzero = 0;
	for(int i = 0 ; i < n ; ++i){
		scanf("%lf" , arr + i);
		nzero += (arr[i] > 0);
	}
	k = min(k , nzero);
	int p = 1 << n;
	masks.clear();
	for(int i = p - 1 ; i >= 0 ; --i){
		if(__builtin_popcount(i) < k){
			masks.emplace_back(i);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%.9lf%c" , Solve(i - 1) , " \n"[i == n]);
	}
}