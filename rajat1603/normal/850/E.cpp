#include "bits/stdc++.h"
using namespace std;
const int N = 20;
const int P = 1 << N;
const int mod = 1e9 + 7;
int power(int a , int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}
int n;
char str[P + 1];
int a[P];
int p;
const int fst[2] = {0 , mod};
int ans;
void go(){
	for(int i = 2 ; i <= p ; i <<= 1){
		int m = i >> 1;
		int u , v , x , y;
		for(int j = 0 ; j < p ; j += i){
			for(int k = 0 ; k < m ; ++k){
				u = a[j + k];
				v = a[j + k + m];
				x = u + v;
				y = u - v;
				a[j + k] = x - fst[x >= mod];
				a[j + k + m] = y + fst[y < 0];
			}
		}
	}
}
int main(){
	scanf("%d" , &n);
	scanf("%s" , str);
	p = 1 << n;
	for(int i = 0 ; i < p ; ++i){
		a[i] = str[i] - '0';
	}
	go();
	for(int i = 0 ; i < p ; ++i){
		a[i] = (1LL * a[i] * a[i]) % mod;
	}
	go();
	int inv = power(p , mod - 2);
	for(int i = 0 ; i < p ; ++i){
		a[i] = (1LL * a[i] * inv) % mod;
	}
	for(int i = 0 ; i < p ; ++i){
		int tot = a[i];
		for(int j = 0 ; j < n ; ++j){
			if(!((i >> j) & 1)){
				tot <<= 1;
				tot -= fst[tot >= mod];
			}
		}
		ans += tot;
		ans -= fst[ans >= mod];
	}
	ans = (ans * 3LL) % mod;
	printf("%d\n" , ans);
}