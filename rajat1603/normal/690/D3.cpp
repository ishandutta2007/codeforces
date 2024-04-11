#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int mod = 1e6 + 3;
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
const int SZ = N;
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
int c , w , h;
matrix base;
int dp[N];
void pre1(){
	dp[0] = 1;
	for(int i = 1 ; i <= w ; ++i){
		dp[i] = 0;
		int cur = 1;
		for(int j = 0 ; j <= w ; ++j){
			dp[i] = add(dp[i] , mult(((i - j - 1) >= 0) ? dp[i - j - 1] : ((i - j) == 0) , cur));
			cur = mult(cur , h);
		}
	}
}
int main(){
	scanf("%d %d %d" , &c , &w , &h);
	pre1();
	if(c <= w){
		printf("%d\n" , dp[c]);
		return 0;
	}
	base.reset();
	base.arr[0][0] = 1;
	for(int i = 1 ; i <= w ; ++i){
		base.arr[0][i] = mult(base.arr[0][i - 1] , h);
	}
	for(int i = 1 ; i <= w ; ++i){
		base.arr[i][i - 1] = 1;
	}
	base = power(base , c - w);
	int ans = 0;
	for(int i = 0 ; i <= w ; ++i){
		ans = add(ans , mult(base.arr[0][i] , dp[w - i]));
	}
	printf("%d\n" , ans);
}