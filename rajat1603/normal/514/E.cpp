#include "bits/stdc++.h"
using namespace std;
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
const int SZ = 102;
struct matrix{
	int arr[SZ][SZ];
	void reset(){
		memset(arr , 0 , sizeof(arr));
	}
	void makeiden(){
		reset();
		for(int i = 0 ; i < SZ ; ++i){
			arr[i][i] = 1;
		}
	}
	matrix operator + (const matrix &o) const {
		matrix res;
		for(int i = 0 ; i < SZ ; ++i){
			for(int j = 0 ; j < SZ ; ++j){
				res.arr[i][j] = add(arr[i][j] , o.arr[i][j]);
			}
		}
		return res;
	}
	matrix operator * (const matrix &o) const {
		matrix res;
		for(int i = 0 ; i < SZ ; ++i){
			for(int j = 0 ; j < SZ ; ++j){
				res.arr[i][j] = 0;
				for(int k = 0 ; k < SZ ; ++k){
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};
matrix power(matrix a , int b){
	matrix res;
	res.makeiden();
	while(b){
		if(b & 1){
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
pair < matrix , matrix > powersum(const matrix &a , int b){
	if(b == 1){
		return make_pair(a , a);
	}
	auto res = powersum(a , b >> 1);
	res.second = res.second + res.second * res.first;
	res.first = res.first * res.first;
	if(b & 1){
		res.first = res.first * a;
		res.second = res.second + res.first;
	}
	return res;
}
matrix sum(const matrix &a , int b){
	matrix res;
	if(!b){
		res.reset();
		return res;
	}
	return powersum(a , b).second;
}
int n , x;
int freq[SZ];
int dp[SZ];
int inp;
matrix base;
int main(){
	scanf("%d %d" , &n , &x);
	while(n--){
		scanf("%d" , &inp);
		++freq[inp];
	}
	dp[0] = 1;
	for(int i = 1 ; i < SZ ; ++i){
		for(int j = 1 ; j <= i ; ++j){
			dp[i] = add(dp[i] , mult(dp[i - j] , freq[j]));
		}
	}
	base.reset();
	for(int i = 0 ; i < 99 ; ++i){
		base.arr[i + 1][i] = 1;
	}
	for(int i = 0 ; i < 100 ; ++i){
		base.arr[i][99] = freq[100 - i];
	}
	base = sum(base , x);
	int res = 1;
	for(int i = 0 ; i < 100 ; ++i){
		res = add(res , mult(dp[i] , base.arr[i][0]));
	}
	printf("%d\n" , res);
}