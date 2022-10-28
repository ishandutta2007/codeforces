#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
const int mod = 1e9 + 	7;
inline int power(int a , int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}
int n , d;
int parent[N];
vector < int > v[N];
int dp[N][N];
int val[N];
int pascal[N];
int ans;
int main(){
	scanf("%d %d" , &n , &d);
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d" , parent + i);
		v[parent[i]].emplace_back(i);
	}
	for(int i = n ; i >= 1 ; --i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = 1;
			for(int next : v[i]){
				dp[i][j] = (1LL * dp[i][j] * dp[next][j]) % mod;
			}
			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
		}
	}
	int cur = d;
	pascal[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		int tmp = dp[1][i];
		for(int j = i ; j >= 1 ; --j){
			pascal[j] += pascal[j - 1];
			pascal[j] -= (pascal[j] >= mod) * mod;
		}
		for(int j = 1 ; j < i ; ++j){
			tmp = (tmp - 1LL * val[i - j] * pascal[j]) % mod;
		}
		ans = (ans + 1LL * tmp * cur) % mod;
		val[i] = tmp;
		cur = (1LL * cur * (d - i)) % mod;
		cur = (1LL * cur * power(i + 1 , mod - 2)) % mod;
	}
	ans = (ans + mod) % mod;
	printf("%d\n" , ans);
}