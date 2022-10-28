#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int t;
int l , r , k;
int sum[N][10];
int g[N];
int f(int n){
	int res = 1;
	while(n){
		int tmp = n % 10;
		if(tmp){
			res *= tmp;
		}
		n /= 10;
	}
	return res;
}
void pre(){
	for(int i = 1 ; i < N ; ++i){
		if(i < 10){
			g[i] = i;
		}
		else{
			g[i] = g[f(i)];
		}
		for(int j = 0 ; j < 10 ; ++j){
			sum[i][j] = sum[i - 1][j];
		}
		++sum[i][g[i]];
	}
}
int main(){
	pre();
	scanf("%d" , &t);
	while(t--){
		scanf("%d %d %d" , &l , &r , &k);
		printf("%d\n" , sum[r][k] - sum[l - 1][k]);
	}
}