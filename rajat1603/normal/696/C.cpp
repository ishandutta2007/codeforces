#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int add(int a , int b){
	int res = a + b;
	if(res >= mod){
		return res - mod;
	}
	return res;
}
int mult(int a , int b){
	long long res = a;
	res *= b;
	if(res >= mod){
		return res % mod;
	}
	return res;
}
int power(int a , int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = mult(res , a);
		}
		a = mult(a , a);
		b >>= 1;
	}
	return res;
}
int n;
long long arr[N];
int mod6;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , &arr[i]);
	}
	mod6 = 1;
	int pw2 = 2;
	long long mx = 1;
	for(int i = 1 ; i <= n ; ++i){
		pw2 = power(pw2 , arr[i] % (mod - 1));
		mod6 = (mod6 * (arr[i] % 6)) % 6;
		mx = max(mx , arr[i]);
	}
	pw2 = mult(pw2 , power(2 , mod - 2));
	int den;
	int num;
	if(mod6 % 2 == 0){
		den = pw2;
		num = add(pw2 , 1);
		num = mult(num , power(3 , mod - 2));
	}
	else{
		if(mod6 % 2 == 1){
			den = pw2;
			num = add(pw2 , mod - 1);
			num = mult(num , power(3 , mod - 2));
		}
		else{
			den = mult(pw2 , 3);
			num = add(pw2 , mod - 1);
		}
	}
	if(mx == 1){
		den = 1;
	}
	printf("%d/%d\n" , num , den);
}