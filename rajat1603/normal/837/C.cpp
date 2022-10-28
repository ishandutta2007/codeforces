#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , a , b;
int x[N] , y[N];
int ans;
int solve(int a , int b , int i , int j){
	for(int gg = 0 ; gg < 2 ; ++gg){
		for(int hh = 0 ; hh < 2 ; ++hh){
			if(x[i] + x[j] <= a && max(y[i] , y[j]) <= b){
				return 1;
			}
			if(y[i] + y[j] <= b && max(x[i] , x[j]) <= a){
				return 1;
			}
			swap(x[j] , y[j]);
		}
		swap(x[i] , y[i]);
	}
	return 0;
}
int main(){
	scanf("%d %d %d" , &n , &a , &b);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , x + i , y + i);
	}
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = i + 1 ; j <= n ; ++j){
			if(solve(a , b , i , j) || solve(b , a , i , j) || solve(a , b , i , j) || solve(b , a , i , j)){
				ans = max(ans , x[i] * y[i] + x[j] * y[j]);
			}
		}
	}
	printf("%d\n" , ans);
}