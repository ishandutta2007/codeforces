#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
const long long mod = 1e9 + 7;

int pr[N];
int numDiv[N];
long long rev[N + N];
long long fact[N + N];

long long Qpow(long long x, long long y){
	long long ret = 1;
	for(int i = 30; i >= 0; --i){
		ret = (ret * ret) % mod;
		if(y & (1LL << i)) ret = (ret * x) % mod;
	}
	return ret;
}

long long nCk(int x, int y){
	return ((fact[x] * rev[x - y]) % mod) * rev[y] % mod;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	for(int i = 1; i < N; ++i){
		for(int j = i + i; j < N; j += i){
			numDiv[j]++;
			if(i != 1 && pr[i] == 0 && pr[j] == 0) pr[j] = i;
		}
		++numDiv[i];
		if(pr[i] == 0) pr[i] = i;
	}



	fact[0] = rev[0] = 1;
	for(int i = 1; i < N + N; ++i){
		fact[i] = (fact[i - 1] * i) % mod;
		rev[i] = Qpow(fact[i], mod - 2);
	}


	int q;
	scanf("%d", &q);

	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);

		long long nega = Qpow(2, y - 1);

		long long perm = 1;
		while(x > 1){
			int val = pr[x], cnt = 0;
			while(pr[x] == val){
				++cnt;
				x /= pr[x];
			}
			perm *= nCk(cnt + y - 1, y - 1);
			perm %= mod;
		}
		printf("%lld\n", (perm * nega) % mod);
	}

	return 0;
}