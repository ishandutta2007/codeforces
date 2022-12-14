#include"bits/stdc++.h"
using namespace std;

int n;
const long long int MOD = 998244353;

class Combination {
	long long int ppow(long long int i, long long int j) {
		long long int res = 1LL;
		while (j) {
			if ((j & 1LL)) {
				res *= i;
				if (res >= MOD) {
					res %= MOD;
				}
			}
			j >>= 1;
			i *= i;
			if (i >= MOD) {
				i %= MOD;
			}
		}
		return res;
	}
public:
	vector<long long int> k;
	vector<long long int> r;
	void resize(int N) {
		k.resize(N + 2);
		r.resize(N + 2);
		k[0] = 1;
		for (int i = 1; i < N + 2; i++) {
			k[i] = k[i - 1];
			k[i] *= i;
			if (k[i] >= MOD)k[i] %= MOD;
		}
		long long int al = k[k.size() - 1];
		long long int iv = ppow(k[k.size() - 1], MOD - 2);
		r[k.size() - 1] = iv;
		for (int i = (int)(r.size()) - 2; i >= 0; i--) {
			r[i] = r[i + 1] * (i + 1);
			if (r[i] >= MOD) {
				r[i] %= MOD;
			}
		}
	}
	long long int C(int a, int b) {
		if (a < b)return 0;
		long long int up = k[a];
		long long int dw = r[b] * r[a - b];
		dw %= MOD;
		up *= dw;
		up %= MOD;
		return up;
	}
	long long int H(int a, int b) {
		return C(a + b - 1, b);
	}
	long long int catalan_number(int n) {
		return (C(2 * n, n) + MOD - C(2 * n, n - 1)) % MOD;
	}
} c;
int main() {
	cin >> n;
	c.resize(2000000);
	long long int subt = 0;
	for (int i = 1; i < n; i++) {
		long long int way = c.C(n, i);
		way *= c.k[n - i];
		way %= MOD;
		subt += way;
		if (subt >= MOD)subt %= MOD;
	}
	long long int whole = c.k[n];
	whole *= n;
	whole %= MOD;
	whole += MOD;
	whole %= MOD;
	whole += MOD - subt;
	whole %= MOD;
	printf("%lld\n", whole);
	return 0;
}