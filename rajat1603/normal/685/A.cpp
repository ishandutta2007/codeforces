#include "bits/stdc++.h"
using namespace std;
int log7(int num){
	int ret = 0;
	while(num >= 7){
		num /= 7;
		++ret;
	}
	return ret;
}
int n , m;
int dig1 , dig2;
int ans = 0;
void solve2(int mask , int left , int num){
	if(!left){
		if(num >= m){
			return;
		}
		++ans;
	}
	for(int i = 0 ; i < 7 ; ++i){
		if(!(mask & (1 << i))){
			solve2(mask | (1 << i) , left - 1 , num * 7 + i);
		}
	}
}
void solve(int mask , int left , int num){
	if(!left){
		if(num >= n){
			return;
		}
		solve2(mask , dig2 , 0);
		return;
	}
	for(int i = 0 ; i < 7 ; ++i){
		if(!(mask & (1 << i))){
			solve(mask | (1 << i) , left - 1 , num * 7 + i);
		}
	}
}
int main(){
	cin >> n >> m;
	dig1 = 1 + log7(n - 1);
	dig2 = 1 + log7(m - 1);
	if(dig1 + dig2 > 7){
		printf("0\n");
		return 0;
	}
	solve(0 , dig1 , 0);
	printf("%d\n" , ans);
}