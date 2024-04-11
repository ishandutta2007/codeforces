#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , k;
int arr[N];
int ans;
bool check1(int val){
	int left = k;
	for(int i = 1 ; i <= n ; ++i){
		left -= max(0 , arr[i] - val);
		if(left < 0){
			return 0;
		}
	}
	return 1;
}
bool check2(int val){
	int left = k;
	for(int i = 1 ; i <= n ; ++i){
		left -= max(0 , val - arr[i]);
		if(left < 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	int l = 0;
	int r = 1e9;
	while(l < r){
		int mid = l + r >> 1;
		if(check1(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	ans = l;
	l = 0;
	r = 1e9;
	while(l < r){
		int mid = l + r >> 1;
		if(check2(mid)){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	ans -= r - 1;
	ans = max(ans , 0);
	if(ans == 0){
		int sum = 0;
		for(int i = 1 ; i <= n ; ++i){
			sum = (sum + arr[i]) % n;
		}
		if(sum){
			ans = 1;
		}
	}
	printf("%d\n" , ans);
}