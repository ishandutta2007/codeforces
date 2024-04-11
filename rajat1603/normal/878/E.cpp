#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
const int mod = 1e9 + 7;
const int inv = (mod + 1) >> 1;
int n , q;
int arr[N];
int lft[LN][N];
int val[LN][N];
int sum[N];
int pw2[N];
int iw2[N];
int l , r;
inline int cost(int l , int r){
	int res = sum[r] - sum[l - 1];
	res += (res < 0) * mod;
	return (1LL * res * iw2[l]) % mod;
}
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	pw2[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		pw2[i] = (pw2[i - 1] << 1) % mod;
	}
	iw2[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		iw2[i] = (1LL * iw2[i - 1] * inv) % mod;
	}
	sum[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		sum[i] = (sum[i - 1] + 1LL * (arr[i] + mod) * pw2[i]) % mod;
	}
	for(int i = 1 ; i <= n ; ++i){
		long long val = 0;
		lft[0][i] = 1;
		for(int j = i ; j >= 1 ; --j){
			val = (val * 2LL + arr[j]);
			if(val <= 0){
				lft[0][i] = j;
				break;
			}
			if(val >= 1000000000){
				break;
			}
		}
		::val[0][i] = cost(lft[0][i] , i);
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(lft[i - 1][j]){
				lft[i][j] = lft[i - 1][lft[i - 1][j] - 1];
				val[i][j] = val[i - 1][j] + val[i - 1][lft[i - 1][j] - 1];
				val[i][j] -= (val[i][j] >= mod) * mod;
			}
			else{
				val[i][j] = val[i - 1][j];
			}
		}
	}
	while(q--){
		scanf("%d %d" , &l , &r);
		int ans = 0;
		for(int i = LN - 1 ; i >= 0 ; --i){
			int idx = lft[i][r];
			if(idx <= l){
				continue;
			}
			ans += val[i][r];
			ans -= (ans >= mod) * mod;
			r = idx - 1;
		}
		ans = (ans * 2LL + cost(l , r)) % mod;
		printf("%d\n" , ans);
	}
}