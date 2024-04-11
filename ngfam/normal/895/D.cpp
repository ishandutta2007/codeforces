#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
const long long mod = 1e9 + 7;

int n;
char a[N];
char b[N];
int rem_a[200];
int rem_b[200];
long long rev[N];
long long fact[N];

long long solve(int *rem, int len, int fr, int to){
	if(fr > to) return 0;

	long long tot = fact[len - 1], ans = 0;

	for(int i = 'a'; i <= 'z'; ++i){
		if(rem[i] < 0) return 0;
		tot = (tot * rev[rem[i]]) % mod;
	}


	for(int i = fr; i <= to; ++i){
		if(rem[i] <= 0) continue;
		long long now = tot * fact[rem[i]] % mod;
		now = (now * rev[rem[i] - 1]) % mod;
		ans += now;
		if(ans >= mod) ans -= mod;
	}
	return ans;
}

long long Qpow(long long x, long long y){
	long long ret = 1;
	for(int i = 30; i >= 0; --i){
		ret = (ret * ret) % mod;
		if(y & (1LL << i)) ret = (ret * x) % mod;
	}
	return ret;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%s", a + 1);
	scanf("%s", b + 1);

	n = strlen(a + 1);

	fact[0] = rev[0] = 1;
	for(int i = 1; i <= n; ++i){
		fact[i] = fact[i - 1] * i % mod;
		rev[i] = Qpow(fact[i], mod - 2);
	}

	int start = 1;
	while(a[start] == b[start] && start <= n) ++ start;
	if(start > n){
		cout << 0;
		return 0;
	}

	int len = n - start + 1;

	for(int i = start; i <= n; ++i){
		rem_a[a[i]]++;
		rem_b[a[i]]++;
	}

	long long ans = solve(rem_a, n - start + 1, a[start] + 1, b[start] - 1);
	

	for(int i = start; i < n; ++i){
		--rem_a[a[i]];
		--rem_b[b[i]];	
		ans += solve(rem_a, n - i, a[i + 1] + 1, 'z');
		ans += solve(rem_b, n - i, 'a', b[i + 1] - 1);
		ans %= mod;
	}

	cout << ans;

	return 0;
}