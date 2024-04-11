#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int arr[N];
long long ans;
int main(){
	scanf("%d %d" , &n , &k);
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	int mn = arr[1];
	for(int i = 2 ; i <= n ; ++i){
		if((arr[i] % k) != (arr[1] % k)){
			printf("-1\n");
			return 0;
		}
		mn = min(mn , arr[i]);
	}
	for(int i = 1 ; i <= n ; ++i){
		ans += (arr[i] - mn) / k;
	}
	printf("%lld\n" , ans);
}