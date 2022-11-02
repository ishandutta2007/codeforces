#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e13 + 7, mod = 998244353;
vector<int> primes;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int binpow(int a, int b) {
	int res = 1;
	while(b) {
		if (b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}

	return res;
} 

int reverse(int a) {
	return binpow(a, mod - 2);
}



int fact[100], rev_fact[100];

int f(int a) {
	int res = 1;
	int cnt = 0;
	for(int i : primes) {
		int temp = 0;
		while(a % i == 0) {
			a /= i;
			temp++;
		}
		cnt += temp;
		res = res * rev_fact[temp] % mod; 
	}

	return res * fact[cnt] % mod;
} 

int solve(int a, int b) {
	int g = gcd(a, b);

	return f(a / g) * f(b / g) % mod; 
}

void solve() {

	fact[0] = 1;
	rev_fact[0] = 1;
	for(int i = 1;i < 100;i++) {
		fact[i] = fact[i - 1] * i % mod;
		rev_fact[i] = reverse(fact[i]);
	}

	int d, q;
	cin >> d >> q;
	for(int i = 2;i * i <= d;i++) {
		if (d % i != 0) continue;
		while(d % i == 0) d /= i;
		primes.emplace_back(i);
	}

	if (d != 1) primes.emplace_back(d);

	while(q--) {
		int v1, v2;
		cin >> v1 >> v2;

		cout << solve(v1, v2) << '\n';
	}
}



signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

 	solve();
}