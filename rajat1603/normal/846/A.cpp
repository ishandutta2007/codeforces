#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
int ans;
bool solve(int zeroes , int ones){
	for(int i = 1 ; i <= n ; ++i){
		if(zeroes){
			zeroes -= !arr[i];
		}
		else if(ones){
			ones -= !!arr[i];
		}
	}
	return (!zeroes) & (!ones);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 0 ; i + j <= n ; ++j){
			if(solve(i , j)){
				ans = max(ans , i + j);
			}
		}
	}
	printf("%d\n" , ans);
}