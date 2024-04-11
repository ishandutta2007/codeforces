#include "bits/stdc++.h"
using namespace std;
const int N = 5e6 + 6;
const int mod = 1e9 + 7;
int t , l , r;
int arr[N];
long long ans[N];
int cur;
int tot;
int main(){
	scanf("%d %d %d" , &t , &l , &r);
	arr[1] = 1;
	for(int i = 2 ; i < N ; ++i){
		if(!arr[i]){
			for(int j = i ;  j < N ; j += i){
				arr[j] += (!arr[j]) * i;
			}
		}
	}
	ans[1] = 0;
	for(int i = 2 ; i < N ; ++i){
		int x = arr[i];
		ans[i] = (1LL * (x - 1LL) * i) / 2LL + ans[i / x];
	}
	tot = 0;
	cur = 1;
	for(int i = l ; i <= r ; ++i){
		ans[i] %= mod;
		tot = (tot + 1LL * cur * ans[i]) % mod;
		cur = (1LL * cur * t) % mod;
	}
	printf("%d\n" , tot);
}