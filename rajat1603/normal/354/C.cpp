#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , k;
int cnt[N];
int inp;
int mn;
int main(){
	scanf("%d %d" , &n , &k);
	mn = N;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &inp);
		++cnt[inp];
		mn = min(mn , inp);
	}
	if(mn <= k + 1){
		printf("%d\n" , mn);
		return 0;
	}
	for(int i = 1 ; i < N ; ++i){
		cnt[i] += cnt[i - 1];
	}
	for(int i = N - 1 ; i >= k + 1 ; --i){
		int tot = 0;
		for(int j = i ; j < N ; j += i){
			tot += cnt[min(j + k , N - 1)] - cnt[j - 1];
		}
		if(tot == n){
			printf("%d\n" , i);
			return 0;
		}
	}
	assert(0);
}