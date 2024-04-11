#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int ans;
int sum;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	sum = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] >= 0){
			sum += arr[i];
		}
	}
	ans = -2e9;
	if(sum & 1){
		ans = sum;
	}
	else{
		for(int i = 1 ; i <= n ; ++i){
			if(arr[i] >= 0){
				if((sum - arr[i]) & 1){
					ans = max(ans , sum - arr[i]);
				}
			}
			else{
				if((sum + arr[i]) & 1){
					ans = max(ans , sum + arr[i]);
				}
			}
		}
	}
	printf("%d\n" , ans);
}