#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long binPow(long long x, long long y){
	long long ret = 1;
	while(y){
		if(y & 1) ret = (ret * x) % mod;
		y >>= 1;
		x = (x * x) % mod;
	}
	return ret;
}

const int N = 1000100;

int n;
long long rev[N];
long long fact[N];
map < int, int > c;

long long comb(int n, int k){
	return (fact[n] * rev[k] % mod) * rev[n - k] % mod; 
}

int main(){

	scanf("%d", &n);

	fact[0] = rev[0] = 1;

	for(int i = 1; i <= n; ++i){

		int val;
		scanf("%d", &val);

		++c[-val];

		fact[i] = fact[i - 1] * i % mod;
		rev[i] = binPow(fact[i], mod - 2);
	}

	int cnt = 0;

	long long ans = 0;

	for(auto p : c){
		if(cnt){

			long long ways = comb(n, cnt + p.second) * fact[n - cnt - p.second] % mod;


			long long tot = fact[cnt + p.second];
			long long none = 1LL * cnt * fact[cnt - 1 + p.second] % mod;
		
			ways = ways * (tot - none + mod) % mod;
			ans += ways * (-p.first) % mod;
			ans %= mod;
		}
		cnt += p.second;
	}

	cout << ans;

	return 0;
}