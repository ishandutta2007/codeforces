#include <bits/stdc++.h>

using namespace std;

const int N = 2000100;
const long long mod = 1e9 + 7;

long long binpow(long long u, long long v){
	long long ret = 1;
	for(int i = 60; i >= 0; --i){
		ret = (ret * ret) % mod;
		if(v & (1LL << i)) ret = (ret * u) % mod;
	}
	return ret;
}

int n, k;
int mobius[N];
int etharos[N];
long long change[N];
long long prePow[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	fill(mobius + 1, mobius + N, 1);

	cin >> n >> k;

	for(int i = 2; i < N; ++i){
		bool isPrime = !etharos[i];
		for(int j = i; j < N; j += i){
			etharos[j] = 1;
			if(isPrime){
				if((j / i) % i == 0) mobius[j] = 0;
				mobius[j] = -mobius[j];
			}
		}
	}

	for(int i = 1; i <= k; ++i){
		prePow[i] = binpow(i, n);
	}

	for(int i = 1; i < N; ++i){
		for(int j = i; j < N; j += i){
			int times = j / i;
			int previous = (times - 1) * i;

			change[j] += -mobius[i] * prePow[times - 1] + mobius[i] * prePow[times];
			change[j] += mod * mod * 2;
			change[j] %= mod; 
		}
	}

	long long ans = 0, last = 1;

	for(int i = 2; i <= k; ++i){
		last = last + change[i];
		last %= mod;

		
		ans += last ^ i;
		ans %= mod;
	}

	cout << ans;

	return 0;
}