#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int ans[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	ans[0] = 1e9;
	for(int i = 1 ; i <= n ; ++i){
		ans[i] = ans[i - 1] + 1;
		if(!arr[i]){
			ans[i] = 0;
		}
	}
	ans[n + 1] = 1e9;
	for(int i = n ; i >= 1 ; --i){
		ans[i] = min(ans[i] , ans[i + 1] + 1);
		if(!arr[i]){
			ans[i] = 0;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n]);
	}
}