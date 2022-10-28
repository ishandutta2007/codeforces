#include "bits/stdc++.h"
using namespace std;
int t;
int a , b;
long long mult(long long a , long long b , long long mod){
	long long res = 0;
	while(b){
		if(b & 1){
			res = (res + a) % mod;
		}
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%d %d" , &a , &b);
		int tmp = cbrt(1LL * a * b);
		while(1LL * tmp * tmp * tmp > 1LL * a * b){
			--tmp;
		}
		while(1LL * (tmp + 1LL) * (tmp + 1LL) * (tmp + 1LL) <= 1LL * a * b){
			++tmp;
		}
		if(1LL * tmp * tmp * tmp == 1LL * a * b){
			int g = __gcd(a , b);
			long long t = 1LL * g * g;
			t = mult(t , g , 1LL * a * b);
			if(__gcd(1LL * a * b , t) == 1LL * a * b){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
		else{
			printf("No\n");
		}
	}
}