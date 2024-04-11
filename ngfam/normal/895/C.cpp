#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 24010000;
const long long mod = 1e9 + 7;	

int cnt[N];
int rev[N];
int fact[N];
long long f[2][1 << 19];


bool isPrime(int x){
	for(int i = 2; i < x; ++i){
		if(x % i == 0) return false;
	}
	return true;
}

long long Qpow(long long x, long long y){
	long long ret = 1;
	for(int i = 30; i >= 0; --i){
		ret = (ret * ret) % mod;
		if(y & (1LL << i)) ret = (ret * x) % mod;
	}
	return ret;
}

long long nCk(int x, int y){
	if(y > x) return 0;
	return 1LL * (1LL * fact[x] * rev[y] % mod) * rev[x - y] % mod;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int val;
		scanf("%d", &val);
		++cnt[val];
	}

	vector < int > lst;
	for(int i = 2; i <= 70; ++i){
		if(isPrime(i)) lst.push_back(i);
	}

	fact[0] = rev[0] = 1;
	for(int i = 1; i <= n; ++i){
		fact[i] = (fact[i - 1] * 2) % mod;
	}

	int flag = 0;
	f[0][0] = 1;

	for(int i = 1; i <= 70; ++i){
		if(cnt[i] == 0) continue;

		int tmp = i, mask = 0;
		for(int j = 0; j < lst.size(); ++j){
			while(tmp % lst[j] == 0){
				mask ^= (1 << j);
				tmp /= lst[j];
			}
		}

		flag = 1 - flag;
		memset(f[flag], 0, sizeof f[flag]);

		for(int x = 0; x < (1 << 19); ++x){
			f[flag][x] += f[1 - flag][x] * fact[cnt[i] - 1] % mod;
			f[flag][x ^ mask] += f[1 - flag][x] * fact[cnt[i] - 1] % mod;

			f[flag][x] %= mod;
			f[flag][x ^ mask] %= mod;
		}
	}

	cout << (f[flag][0] - 1 + mod) % mod;

	return 0;
}