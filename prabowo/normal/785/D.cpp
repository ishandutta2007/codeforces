#include <bits/stdc++.h>
using namespace std;

const int N = 222222;
const int MOD = 1000000007;

int n;
char s[N];

int fact[N<<1], ifact[N];

int count(int l, int r) {
	if (r == 0) return 0;
	return 1LL * fact[l+r-1] * ifact[l] % MOD * ifact[r-1] % MOD;
}

int main() {
	fact[0] = 1;
	for (int i=1; i<N<<1; i++) fact[i] = 1LL * fact[i-1] * i % MOD;
	
	ifact[200000] = 750007460;
	for (int i=199999; i>=0; i--) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;
	
	scanf("%s", s);
	n = strlen(s);
	
	int r = 0;
	for (int i=0; i<n; i++) r += s[i] == ')';
	
	int l = 0;
	long long ans = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == '(') {
			ans += count(++l, r);
		} else r--;
	}
	
	printf("%lld\n", (ans + MOD) % MOD);
	
	return 0;	
}