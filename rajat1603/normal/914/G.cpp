#include "bits/stdc++.h"
using namespace std;
const int LN = 17;
const int N = 1 << LN;
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
int cnt[N];
void such(){
	int n;
	scanf("%d" , &n);
	while(n--){
		int inp;
		scanf("%d" , &inp);
		++cnt[inp];
	}
}
int fib[N];
void an(){
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2 ; i < N ; ++i){
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	}
}
int dp1[N];
void original(){//dp1 = how many pairs have or as i
	/*for(int i = 0 ; i < N ; ++i){
		dp1[i] = cnt[i];
	}
	for(int j = 0 ; j < LN ; ++j){
		for(int i = 0 ; i < N ; ++i){
			if((i >> j) & 1){
				dp1[i] += dp1[i ^ (1 << j)];
				dp1[i] -= (dp1[i] >= mod) * mod;
			}
		}
	}
	for(int i = 0 ; i < N ; ++i){
		dp1[i] = (1LL * dp1[i] * dp1[i]) % mod;
	}
	for(int j = 0 ; j < LN ; ++j){
		for(int i = 0 ; i < N ; ++i){
			if((i >> j) & 1){
				dp1[i] -= dp1[i ^ (1 << j)];
				dp1[i] += (dp1[i] < 0) * mod;
			}
		}
	}*/
	for(int i = 0 ; i < N ; ++i){
		int c = i ^ (N - 1);
		for(int j = c ; j ; j = (j - 1) & c){
			dp1[i ^ j] = (dp1[i ^ j] + 1LL * cnt[i] * cnt[j]) % mod;
		}
		dp1[i] = (dp1[i] + 1LL * cnt[i] * cnt[0]) % mod;
	}
}
int dp2[N];
const int fst[2] = {0 , mod};
void go(){
	for(int i = 2 ; i <= N ; i <<= 1){
		int m = i >> 1;
		int u , v , x , y;
		for(int j = 0 ; j < N ; j += i){
			for(int k = 0 ; k < m ; ++k){
				u = dp2[j + k];
				v = dp2[j + k + m];
				x = u + v;
				y = u - v;
				dp2[j + k] = x - fst[x >= mod];
				dp2[j + k + m] = y + fst[y < 0];
			}
		}
	}
}
void problem(){//how many pairs have xor as i
	for(int i = 0 ; i < N ; ++i){
		dp2[i] = cnt[i];
	}
	go();
	for(int i = 0 ; i < N ; ++i){
		dp2[i] = (1LL * dp2[i] * dp2[i]) % mod;
	}
	go();
	int inv = power(N , mod - 2);
	for(int i = 0 ; i < N ; ++i){
		dp2[i] = (1LL * dp2[i] * inv) % mod;
	}
}
int dp3[N];
void fuck(){
	for(int i = 0 ; i < N ; ++i){
		dp3[i] = cnt[i];
	}
}
void ThIs(){
	for(int i = 0 ; i < N ; ++i){
		dp1[i] = (1LL * fib[i] * dp1[i]) % mod;
		dp2[i] = (1LL * fib[i] * dp2[i]) % mod;
		dp3[i] = (1LL * fib[i] * dp3[i]) % mod;
	}
}
void doyourthing(int a[]){
	for(int j = 0 ; j < LN ; ++j){
		for(int i = 0 ; i < N ; ++i){
			if(!((i >> j) & 1)){
				a[i] += a[i | (1 << j)];
				a[i] -= (a[i] >= mod) * mod;
			}
		}
	}
}
int dp4[N];
void shit(){
	doyourthing(dp1);
	doyourthing(dp2);
	doyourthing(dp3);
	for(int i = 0 ; i < N ; ++i){
		dp4[i] = (1LL * dp1[i] * dp2[i]) % mod;
		dp4[i] = (1LL * dp3[i] * dp4[i]) % mod;
	}
	for(int j = 0 ; j < LN ; ++j){
		for(int i = 0 ; i < N ; ++i){
			if(!((i >> j) & 1)){
				dp4[i] -= dp4[i | (1 << j)];
				dp4[i] += (dp4[i] < 0) * mod;
			}
		}
	}
	int ans = 0;
	for(int i = 0 ; i < LN ; ++i){
		ans = (ans + dp4[1 << i]) % mod;
	}
	printf("%d\n" , ans);
}
int main(){
	such();
	an();
	original();
	problem();
	fuck();
	ThIs();
	shit();
}