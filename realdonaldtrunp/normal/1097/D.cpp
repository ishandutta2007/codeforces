#include"bits/stdc++.h"
using namespace std;
long long int n;
long long int k2;
vector<long long int> v;
vector<vector<int> > go;
#define MOD 1000000007
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
long long int p[1000];

vector<long long int> pr;

vector<vector<int> > f;
vector<int> enc(long long int num) {
	vector<int> ret(pr.size(), 0);
	for (int i = 0; i < pr.size(); i++) {
		while (num%pr[i] == 0LL) {
			ret[i]++;
			num /= pr[i];
		}
	}
	return ret;
}
long long int dp[52][52];

int main() {
	scanf("%lld%lld", &n, &k2);
	for (int i = 1; i < 1000; i++) {
		p[i] = ppow(i, MOD - 2);
	}
	for (long long int i = 1; i*i <= n; i++) {
		if (n%i == 0LL) {
			v.push_back(i);
			if (n / i != i) {
				v.push_back(n / i);
			}
		}
	}
	long long int val = n;
	for (long long int i = 2; i*i <= val; i++) {
		while (val%i == 0LL) {
			pr.push_back(i);
			while (val%i == 0LL) {
				val /= i;
			}
		}
	}
	if (val > 1LL) {
		pr.push_back(val);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		f.push_back(enc(v[i]));
	}
	for (int i = 0; i < pr.size(); i++) {
		if (dp[f.back()[i]][f.back()[i]] == 0LL) {
			int lim = f.back()[i];
			dp[lim][lim] = 1;
			for (int cn = 0; cn < k2; cn++) {
				long long int way = 0;
				for (int j = lim; j >= 0; j--) {
					way += dp[lim][j] * p[j + 1];
					if (way >= MOD)way %= MOD;
					dp[lim][j] = way;
				}
			}
		}
	}
	long long int O = 0;
	for (int i = 0; i < v.size(); i++) {
		long long int ans = 1;
		for (int k = 0; k < f[i].size(); k++) {
			ans *= dp[f.back()[k]][f[i][k]];
			if (ans >= MOD)ans %= MOD;
		}
		v[i] %= MOD;
		ans *= v[i];
		O += ans;
		O %= MOD;
	}
	printf("%lld\n", O);
	return 0;
}