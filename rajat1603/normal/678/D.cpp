#include "bits/stdc++.h"
using namespace std;
int a , b , x;
long long n;
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
int gpsum(int a , long long n){
	if(a == 1){
		return (n % mod);
	}
	return mult(add(power(a , n % (mod - 1)) , mod - 1) , power(a - 1 , mod - 2));
}
int ans;
int main(){
	cin >> a >> b >> n >> x;
	ans = mult(power(a , n % (mod - 1)) , x);
	ans = add(ans , mult(b , gpsum(a , n)));
	cout << ans;
}