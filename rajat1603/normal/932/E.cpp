#include "bits/stdc++.h"
using namespace std;
const int K = 5e3 + 9;
const int mod = 1e9 + 7;
int n , k;
int val[K];
int ans , cur;
int power(int a , int b){
	if(b < 0){
		return power(power(a , mod - 2) , -b);
	}
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
int pascal[K][K];
int powers[K];
void pre(){
	for(int i = 0 ; i < K ; ++i){
		pascal[i][0] = 1;
		for(int j = 1 ; j <= i ; ++j){
			pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % mod;
		}
	}
	for(int i = 1 ; i < K ; ++i){
		powers[i] = power(i , k);
	}
}
int solve(int n , int k){
	int res = 0;
	for(int i = 1 ; i <= n ; ++i){
		res = (res + 1LL * pascal[n][i] * powers[i]) % mod;
	}
	return res;
}
int main(){
    scanf("%d %d" , &n , &k);
    pre();
    if(n <= k + 2){
    	printf("%d\n" , solve(n , k));
    	return 0;
    }
    for(int i = 1 ; i <= k + 2 ; ++i){
    	int vall = power(2 , i - k);
    	val[i] = (1LL * solve(i , k) * power(vall , mod - 2)) % mod;
    }
    ans = 0;
    cur = 1;
    for(int i = 2 ; i <= k + 2 ; ++i){
        cur = (1LL * cur * (n - i)) % mod;
        cur = (1LL * cur * power(mod + 1 - i , mod - 2)) % mod;
    }
    for(int i = 1 ; i <= k + 2 ; ++i){
        ans = (ans + 1LL * cur * val[i]) % mod;
        cur = (1LL * cur * (n - i)) % mod;
        cur = (1LL * cur * (i - k - 2 + mod)) % mod;
        cur = (1LL * cur * power((1LL * (n - i - 1) * i) % mod , mod - 2)) % mod;
    }
    ans = (1LL * ans * power(2 , n - k)) % mod;
    printf("%d\n" , ans);
}