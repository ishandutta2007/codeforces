#include "bits/stdc++.h"
using namespace std;
const int N = 42;
const int M = 21;
const int P = 1 << M;
int n , k;
long long graph[N];
int dp1[P];
int dp2[P];
int com[P];
int ans;
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 0 ; i < n ; ++i){
		int val;
		for(int j = 0 ; j < n ; ++j){
			scanf("%d" , &val);
			graph[i] |= (1LL * val) << j;
		}
	}
	long long lmask = 0;
	long long rmask = 0;
	int lsize = 0;
	int rsize = 0;
	for(int i = 0 ; i < n ; ++i){
		if(i + i < n){
			lmask |= 1LL << i;
			++lsize;
		}
		else{
			rmask |= 1LL << i;
			++rsize;
		}
	}
	dp1[0] = 0;
	ans = 0;
	int msb = 0;
	for(int i = 1 ; i < (1 << lsize) ; ++i){
		if((2 << msb) <= i){
			++msb;
		}
		dp1[i] = max(dp1[i ^ (1 << msb)] , 1 + dp1[i & graph[msb]]);
		ans = max(ans , dp1[i]);
	}
	dp2[0] = 0;
	msb = 0;
	for(int i = 1 ; i < (1 << rsize) ; ++i){
		if((2 << msb) <= i){
			++msb;
		}
		dp2[i] = max(dp2[i ^ (1 << msb)] , 1 + dp2[i & (graph[msb + lsize] >> lsize)]);
		ans = max(ans , dp2[i]);
	}
	com[0] = lmask;
	msb = 0;
	for(int i = 1 ; i < (1 << rsize) ; ++i){
		if((2 << msb) <= i){
			++msb;
		}
		com[i] = (graph[msb + lsize] & lmask) & com[i ^ (1 << msb)];
	}
	for(int i = 1 ; i < (1 << rsize) ; ++i){
		ans = max(ans , dp2[i] + dp1[com[i]]);
	}
	double final = (1.0 * k * k) / (1.0 * ans * ans);
	final *= ans * (ans - 1);
	final /= 2;
	printf("%.6lf\n" , final);
}