#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int mod = 1e9 + 7;
int n;
int arr[N];
int pw2[N];
int inv[N];
int ans , sum;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	sort(arr + 1 , arr + 1 + n);
	pw2[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		pw2[i] = (pw2[i - 1] << 1) % mod;
	}
	inv[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		inv[i] = (1LL * inv[i - 1] * (mod + 1 >> 1)) % mod;
	}
	ans = 0;
	sum = 0;
	for(int i = 1 ; i <= n ; ++i){
		ans = (ans + 1LL * arr[i] * (pw2[i - 1] - 1LL)) % mod;
		ans = (ans - 1LL * sum * pw2[i - 1]) % mod;
		ans = (ans + mod) % mod;
		sum = (sum + 1LL * arr[i] * inv[i]) % mod;
	}
	printf("%d\n" , ans);
}