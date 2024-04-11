#include "bits/stdc++.h"
using namespace std;
const int N = 3e2 + 2;
const int mod = 1e9 + 7;
int n;
int arr[N];
int fact[N];
int ifact[N];
map < int , int > cnt;
int convert(int num){
	int res = 1;
	for(int i = 2 ; i * i <= num ; ++i){
		if(num % i == 0){
			int cur = 0;
			while((num % i) == 0){
				num /= i;
				cur ^= 1;
			}
			if(cur){
				res *= i;
			}
		}
	}
	return res * num;
}
int poly[N];
int deg;
int temp[N];
int res[N];
void mult(int n){
	memset(res , 0 , sizeof(int) * (n + deg));
	for(int i = 0 ; i < deg ; ++i){
		for(int j = 0 ; j < n ; ++j){
			res[i + j] = (res[i + j] + 1LL * poly[i] * temp[j]) % mod;
		}
	}
	memcpy(poly , res , sizeof(int) * (n + deg));
	deg += n - 1;
}
int ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	cnt.clear();
	for(int i = 1 ; i <= n ; ++i){
		++cnt[convert(arr[i])];
	}
	fact[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		fact[i] = (1LL * fact[i - 1] * i) % mod;
	}
	ifact[N - 1] = 985319076;
	for(int i = N - 2 ; i >= 0 ; --i){
		ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
	}
	poly[0] = 1;
	deg = 1;
	for(auto it : cnt){
		for(int i = 0 ; i < it.second ; ++i){
			temp[i] = fact[it.second - 1];
			temp[i] = (1LL * temp[i] * ifact[it.second - i]) % mod;
			temp[i] = (1LL * temp[i] * ifact[i]) % mod;
			temp[i] = (1LL * temp[i] * ifact[it.second - 1 - i]) % mod;
		}
		temp[it.second] = 0;
		mult(it.second);
	}
	ans = 0;
	for(int i = 0 ; i < deg ; ++i){
		if(i & 1){
			ans = (ans - 1LL * poly[i] * fact[n - i]) % mod;
			ans += (ans < 0) * mod;
		}
		else{
			ans = (ans + 1LL * poly[i] * fact[n - i]) % mod;
		}
	}
	for(auto it : cnt){
		ans = (1LL * ans * fact[it.second]) % mod;
	}
	printf("%d\n" , ans);
}