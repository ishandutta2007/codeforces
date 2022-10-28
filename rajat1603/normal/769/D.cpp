#include "bits/stdc++.h"
using namespace std;
const int K = 14;
const int N = 1 << 14;
int n , k;
int inp;
int rev[N];
long long ans;
long long cnt[N];
void pre(){
	for(int i = 0 ; i < N ; ++i){
		int rev = 0;
		for(int j = 0 ; j < K ; ++j){
			if((i >> j) & 1){
				rev |= 1 << (K - j - 1);
			}
		}
		::rev[i] = rev;
	}
}
void fwht(long long a[]){
	for(int i = 0 ; i < N ; ++i){
		if(rev[i] > i){
			swap(a[i] , a[rev[i]]);
		}
	}
	for(int size = 2 ; size <= N ; size <<= 1){
		int m = size >> 1;
		for(int i = 0 ; i < N ; i += size){
			for(int j = 0 ; j < m ; ++j){
				long long u = a[i + j];
				long long v = a[i + j + m];
				a[i + j] = u + v;
				a[i + j + m] = u - v;
			}
		}
	}
}
void multiply(){
	pre();
	fwht(cnt);
	for(int i = 0 ; i < N ; ++i){
		cnt[i] *= cnt[i];
	}
	fwht(cnt);
	for(int i = 0 ; i < N ; ++i){
		cnt[i] /= N;
	}
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d" , &inp);
		++cnt[inp];
	}
	multiply();
	cnt[0] -= n;
	for(int i = 0 ; i < N ; ++i){
		cnt[i] >>= 1;
		if(__builtin_popcount(i) == k){
			ans += cnt[i];
		}
	}
	printf("%lld\n" , ans);
}