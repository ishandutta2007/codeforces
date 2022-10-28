#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int C = 16;
const int mod = 1e9 + 7;
int n;
long long k;
long long a[N] , b[N];
int c[N];
struct vec{
	int c;
	int arr[C];
};
struct mat{
	int c;
	int arr[C][C];
	inline mat operator * (const mat &other){
		mat res;
		res.c = c;
		for(int i = 0 ; i <= c ; ++i){
			for(int j = 0 ; j <= c ; ++j){
				res.arr[i][j] = 0;
				for(int k = 0 ; k <= c ; ++k){
					res.arr[i][j] = (res.arr[i][j] + 1LL * arr[i][k] * other.arr[k][j]) % mod;
				}
			}
		}
		return res;
	}
	inline vec operator * (const vec &other){
		vec res;
		res.c = c;
		for(int i = 0 ; i <= c ; ++i){
			res.arr[i] = 0;
			for(int j = 0 ; j <= c ; ++j){
				res.arr[i] = (res.arr[i] + 1LL * arr[i][j] * other.arr[j]) % mod;
			}
		}
		return res;
	}
};
mat get(int c){
	mat res;
	res.c = c;
	for(int i = 0 ; i <= c ; ++i){
		for(int j = 0 ; j <= c ; ++j){
			res.arr[i][j] = abs(i - j) <= 1;
		}
	}
	return res;
}
vec cur;
void power(mat a , long long b){
	while(b){
		if(b & 1){
			cur = a * cur;
		}
		a = a * a;
		b >>= 1;
	}
}
int main(){
	scanf("%d %lld" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld %lld %d" , a + i , b + i , c + i);
	}
	cur.c = c[1];
	for(int i = 0 ; i <= cur.c ; ++i){
		cur.arr[i] = !i;
	}
	b[n] = k;
	for(int i = 1 ; i <= n ; ++i){
		if(c[i] < cur.c){
			for(int j = c[i] + 1 ; j <= cur.c ; ++j){
				cur.arr[j] = 0;
			}
			cur.c = c[i];
		}
		else{
			for(int j = cur.c + 1 ; j <= c[i] ; ++j){
				cur.arr[j] = 0;
			}
			cur.c = c[i];
		}
		power(get(cur.c) , b[i] - a[i]);
	}
	printf("%d\n" , cur.arr[0]);
}