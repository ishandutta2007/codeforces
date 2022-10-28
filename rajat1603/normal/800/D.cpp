#include "bits/stdc++.h"
using namespace std;
const int N = 1e6;
const int mod = 1e9 + 7;
int n;
int inp;
int a[N];
int b[N];
int c[N];
int pow2[N];
int A[N];
int B[N];
int C[N];
int D[N];
long long ans;
inline int dig(int num , int d){
	for(int i = 0 ; i < d ; ++i){
		num /= 10;
	}
	return num % 10;
}
long long dp1[N][7];
long long dp2[N][7];
void pre(int a[] , int res[]){
	for(int i = 999999 ; i > 0 ; --i){
		dp1[i][0] = a[i];
		int num = i;
		int pw = 1;
		for(int j = 0 ; j < 6 ; ++j){
			int d = num % 10;
			dp1[i][j + 1] = 0;
			for(int k = 0 ; k < 10 - d ; ++k){
				dp1[i][j + 1] += dp1[i + k * pw][j];
			}
			dp1[i][j + 1] %= mod;
			num /= 10;
			pw *= 10;
		}
		res[i] = dp1[i][6];
	}
}
void pre2(int a[] , int res[]){
	for(int i = 999999 ; i > 0 ; --i){
		dp2[i][0] = 0;
		int num = i;
		int pw = 1;
		for(int j = 0 ; j < 6 ; ++j){
			int d = num % 10;
			dp2[i][j + 1] = 0;
			for(int k = 0 ; k < 10 - d ; ++k){
				dp2[i][j + 1] += dp2[i + k * pw][j];
			}
			dp2[i][j + 1] %= mod;
			num /= 10;
			pw *= 10;
		}
		res[i] = (a[i] - dp2[i][6] + mod) % mod;
		dp2[i][0] = res[i];
		num = i;
		pw = 1;
		for(int j = 0 ; j < 6 ; ++j){
			int d = num % 10;
			dp2[i][j + 1] = 0;
			for(int k = 0 ; k < 10 - d ; ++k){
				dp2[i][j + 1] += dp2[i + k * pw][j];
			}
			dp2[i][j + 1] %= mod;
			num /= 10;
			pw *= 10;
		}
	}
}
long long solve(int x){
	long long s = B[x];
	long long ss = C[x];
	int n = A[x];
	if(n == 0){
		return 0;
	}
	long long res = 0;
	res += (1LL * pow2[n - 1] * ss) % mod;
	if(n > 1){
		res += (1LL * pow2[n - 2] * ((((s * s - ss) % mod) + mod) % mod)) % mod;
	}
	return res % mod;
}
int main(){
	scanf("%d" , &n);
	pow2[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &inp);
		++a[inp];
		b[inp] = (b[inp] + inp) % mod;
		c[inp] = (c[inp] + 1LL * inp * inp) % mod;
		pow2[i] = (2LL * pow2[i - 1]) % mod;
	}
	pre(a , A);
	pre(b , B);
	pre(c , C);
	for(int i = 1 ; i < 1000000 ; ++i){
		D[i] = solve(i);
	}
	pre2(D , a);
	for(int i = 1 ; i < 1000000 ; ++i){
		ans ^= 1LL * i * a[i];
	}
	printf("%lld\n" , ans);
}