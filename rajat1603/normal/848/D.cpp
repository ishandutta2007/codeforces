#include "bits/stdc++.h"
using namespace std;
/*

 0 ->    ()====()
 1 ->    ()=====O=====()

*/
const int N = 55;
const int mod = 1e9 + 7;
int n , m;
int dp0[N][N];
int dp1[N][N];
int fact[N];
int ifact[N];
int tmp[N][N];
inline int get(int n , int r){
	int res = ifact[r];
	for(int i = n - r + 1 ; i <= n ; ++i){
		res = (1LL * res * i) % mod;
	}
	return res;
}
int main(){
	fact[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		fact[i] = (1LL * fact[i - 1] * i) % mod;
	}
	ifact[N - 1] = 956708188;
	for(int i = N - 2 ; i >= 0 ; --i){
		ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
	}
	scanf("%d %d" , &n , &m);
	dp0[0][1] = 1;
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 1 ; j <= n + 1 ; ++j){
			if(i + i < n){
				dp1[i + i + 1][j] = (dp1[i + i + 1][j] + 1LL * dp0[i][j] * dp0[i][j]) % mod;
			}
			for(int k = 0 ; k <= i && i + k < n ; ++k){
				for(int l = 1 ; l <= ((k < i) ? (n + 1) : (j - 1)) ; ++l){
					dp1[i + k + 1][min(j , l)] = (dp1[i + k + 1][min(j , l)] + 2LL * dp0[i][j] * dp0[k][l]) % mod;
				}
			}
			if(!dp1[i][j]){
				continue;
			}
			memcpy(tmp , dp0 , sizeof(tmp));
			for(int cnt = 1 ; cnt * i <= n ; ++cnt){
				int val = get(dp1[i][j] + cnt - 1 , cnt);
				for(int k = 0 ; k + i * cnt <= n ; ++k){
					for(int l = 1 ; l + j * cnt <= n + 1 ; ++l){
						tmp[k + i * cnt][l + j * cnt] = (tmp[k + i * cnt][l + j * cnt] + 1LL * val * dp0[k][l]) % mod;
					}
				}
			}
			memcpy(dp0 , tmp , sizeof(dp0));
		}
	}
	printf("%d\n" , dp0[n][m]);
}