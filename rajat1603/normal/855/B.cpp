#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int p , q , r;
int arr[N];
long long pre[N];
long long suf[N];
long long ans;
int main(){
	scanf("%d" , &n);
	scanf("%d %d %d" , &p , &q , &r);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	pre[1] = 1LL * p * arr[1];
	for(int i = 2 ; i <= n ; ++i){
		pre[i] = max(pre[i - 1] , 1LL * p * arr[i]);
	}
	suf[n] = 1LL * r * arr[n];
	for(int i = n - 1 ; i >= 1 ; --i){
		suf[i] = max(suf[i + 1] , 1LL * r * arr[i]);
	}
	ans = pre[1] + suf[1] + 1LL * q * arr[1];
	for(int i = 1 ; i <= n ; ++i){
		ans = max(ans , pre[i] + suf[i] + 1LL * q * arr[i]);
	}
	printf("%lld\n" , ans);
}