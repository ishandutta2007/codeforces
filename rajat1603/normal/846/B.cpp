#include "bits/stdc++.h"
using namespace std;
const int N = 50;
int n , k , m;
int arr[N];
int solve(int full){
	int tot = 0;
	for(int i = 1 ; i <= k ; ++i){
		tot += arr[i];
	}
	tot *= full;
	if(tot > m){
		return 0;
	}
	int res = (k + 1) * full;
	int lft = m - tot;
	for(int i = 1 ; i <= k ; ++i){
		for(int j = full + 1 ; j <= n ; ++j){
			if(lft >= arr[i]){
				lft -= arr[i];
				++res;
			}
		}
	}
	return res;
}
int main(){
	scanf("%d %d %d" , &n , &k , &m);
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d" , arr + i);
	}
	sort(arr + 1 , arr + 1 + k);
	int ans = 0;
	for(int i = 0 ; i <= n ; ++i){
		ans = max(ans , solve(i));
	}
	printf("%d\n" , ans);
}