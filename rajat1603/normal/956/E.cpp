#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int n , l , r;
int a[N];
int b[N];
int h;
vector < int > zero;
vector < int > one;
int dp[N];
int main(){
	scanf("%d %d %d" , &n , &l , &r);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , b + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		h += a[i];
		if(b[i]){
			one.emplace_back(a[i]);
		}
		else{
			zero.emplace_back(a[i]);
		}
	}
	swap(l , r);
	l = h - l;
	r = h - r;
	dp[0] = 0;
	for(int i = 1 ; i < N ; ++i){
		dp[i] = -N;
	}
	for(int x : zero){
		for(int j = N - 1 ; j >= x ; --j){
			dp[j] = max(dp[j] , dp[j - x]);
		}
	}
	sort(one.begin() , one.end());
	reverse(one.begin() , one.end());
	for(int x : one){
		for(int j = N - 1 ; j >= x ; --j){
			dp[j] = max(dp[j] , dp[j - x] + (j >= l && j <= r));
		}
	}
	printf("%d\n" , *max_element(dp , dp + N));
}