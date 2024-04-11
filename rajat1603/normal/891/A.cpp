#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n;
int arr[N];
int ans;
int main(){
	scanf("%d" , &n);
	ans = 1e6 + 6;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == 1){
			ans = 0;
			for(int j = 1 ; j <= n ; ++j){
				if(arr[j] != 1){
					++ans;
				}
			}
			printf("%d\n" , ans);
			return 0;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		int g = arr[i];
		for(int j = i ; j <= n ; ++j){
			g = __gcd(g , arr[j]);
			if(g == 1){
				ans = min(ans , j - i + n - 1);
				break;
			}
		}
	}
	if(ans >= 100000){
		printf("-1\n");
		return 0;
	}
	printf("%d\n" , ans);
}