#include "bits/stdc++.h"
using namespace std;
const int N = 3e6 + 6;
int n;
int inp;
int freq[N];
long long ans[N];
int q;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &inp);
		++freq[inp];
	}
	for(int i = 1 ; i < N ; ++i){
		for(int j = 1 ; i * j < N ; ++j){
			ans[i * j] += 1LL * freq[i] * (freq[j] - (i == j));
		}
		ans[i] += ans[i - 1];
	}
	scanf("%d" , &q);
	while(q--){
		scanf("%d" , &inp);
		printf("%lld\n" , 1LL * n * (n - 1LL) - ans[inp - 1]);
	}
}