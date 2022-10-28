#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int K = 2e3 + 3;
const int S = 23;
const int mod = 1e9 + 7;
int n , m , k , s;
pair < int , int > arr[K];
bool ok1 , ok2;
int dp[2][K];
int fact[N];
int ifact[N];
int ans;
int done;
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
void pre(){
	fact[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		fact[i] = (1LL * fact[i - 1] * i) % mod;
	}
	ifact[N - 1] = power(fact[N - 1] , mod - 2);
	for(int i = N - 2 ; i >= 0 ; --i){
		ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
	}
}
inline int ways(int x , int y){
	if(x < 0 || y < 0){
		return 0;
	}
	return (1LL * ((1LL * fact[x + y] * ifact[x]) % mod) * ifact[y]) % mod;
}
inline int get(pair < int , int > a , pair < int , int > b){
	return ways(b.first - a.first , b.second - a.second);
}
int main(){
	pre();
	scanf("%d %d %d %d" , &n , &m , &k , &s);
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d %d" , &arr[i].first , &arr[i].second);
		if(arr[i] == make_pair(1 , 1)){
			ok1 = 1;
		}
		if(arr[i] == make_pair(n , m)){
			ok2 = 1;
		}
	}
	if(!ok1){
		arr[++k] = make_pair(1 , 1);
		s <<= 1;
	}
	if(!ok2){
		arr[++k] = make_pair(n , m);
		s <<= 1;
	}
	sort(arr + 1 , arr + 1 + k);
	for(int i = 1 ; i <= k ; ++i){
		dp[1][i] = i == k;
	}
	s = s + 1 >> 1;
	ans = (1LL * s * dp[1][1]) % mod;
	done = dp[1][1];
	for(int i = 2 ; i < S ; ++i){
		for(int j = k ; j >= 1 ; --j){
			int cur = 0;
			for(int l = j + 1 ; l <= k ; ++l){
				cur = (cur + 1LL * get(arr[j] , arr[l]) * (dp[!(i & 1)][l] - dp[i & 1][l] + mod)) % mod;
			}
			dp[i & 1][j] = cur;
		}
		s = s + 1 >> 1;
		ans = (ans + 1LL * s * dp[i & 1][1]) % mod;
		done = (done + dp[i & 1][1]) % mod;
	}
	done = (ways(n - 1 , m - 1) - done + mod) % mod;
	ans = (ans + done) % mod;
	ans = (1LL * ans * power(ways(n - 1 , m - 1) , mod - 2)) % mod;
	printf("%d\n" , ans);
}