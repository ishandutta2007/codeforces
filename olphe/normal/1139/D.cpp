#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 1);
	vector<int>p(N + 1, 1);
	p[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (!p[i])continue;
		for (int j = i; j <= N; j += i) {
			v[j]^=1;
			p[j] = 0;
		}
	}
	for (auto &i : v) {
		i <<= 1;
		i--;
	}
	for (int i = 2; i*i <= N; i++) {
		for (int j = i * i; j <= N; j += i * i)v[j] = 0;
	}
	long long int ans = 1;
	for (int i = 2; i <= N; i++) {
		if (!v[i])continue;
		long long int box = N / i;
		box *= power(N - box, MOD - 2, MOD);
		box %= MOD;
		ans += box * v[i];
	}
	ans += MOD * MOD;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}