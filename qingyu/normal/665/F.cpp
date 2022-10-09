#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int PRIME_LIMIT = int(1e6) * 5;
bool prime[PRIME_LIMIT + 1];
int prime_count_table[PRIME_LIMIT + 1];
vector<int> prs;

void init_prime() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i])
		for (int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i]) prs.push_back(i);
	for (int i = 2; i < sizeof(prime); i++) prime_count_table[i] += prime_count_table[i - 1] + prime[i];
}

const int SMALL_PRIME_PHI_TABLE_MAX = 7;
vector<int> small_prime_phi_table[SMALL_PRIME_PHI_TABLE_MAX];

void init_small_prime_phi_table() {
	int n = 2;
	small_prime_phi_table[0] = { 0, 1 };
	for (int i = 1; i < SMALL_PRIME_PHI_TABLE_MAX; i++) {
		n *= prs[i];
		for (int _ = 0; _ < prs[i]; _++) {
			small_prime_phi_table[i].insert(small_prime_phi_table[i].end(),
				small_prime_phi_table[i - 1].begin(), small_prime_phi_table[i - 1].end());
		}
		for (int j = prs[i]; j < n; j += prs[i]) {
			small_prime_phi_table[i][j] = 0;
		}
	}
	for (int i = 0; i < SMALL_PRIME_PHI_TABLE_MAX; i++) {
		for (int j = 0; j < (int)small_prime_phi_table[i].size() - 1; j++) {
			small_prime_phi_table[i][j + 1] += small_prime_phi_table[i][j];
		}
	}
}

void init() {
	init_prime();
	init_small_prime_phi_table();
}

ll prime_phi(ll x, int a) {
	a--; // fe[u0-indexedC
	if (a == 0) return (x + 1) / 2;
	if (a < SMALL_PRIME_PHI_TABLE_MAX) {
		const int n = (int)small_prime_phi_table[a].size();
		ll ret = x / n * small_prime_phi_table[a][n - 1] + small_prime_phi_table[a][x % n];
		return ret;
	}
	if (prs[a] >= x) return 1;
	// auto it = prime_phi_cache[a].find(x);
	// if (it != prime_phi_cache[a].end()) return it->second;
	ll t = prime_phi(x, a) - prime_phi(x / prs[a], a);
	//return prime_phi_cache[a][x] = t;
	return t;
}

ll int_sqrt(ll n) {
	ll ret = (ll)sqrt(n);
	while (ret * ret <= n) ret++;
	return ret - 1;
}

ll int_cbrt(ll n) {
	ll ret = (ll)cbrt(n);
	while (ret * ret <= n) ret++;
	return ret - 1;
}

ll int_fourth_rt(ll n) {
	return int_sqrt(int_sqrt(n));
}

ll lehmer_pi(ll x) {
	if (x <= PRIME_LIMIT) return prime_count_table[x];
	int a = (int)lehmer_pi(int_fourth_rt(x));
	int b = (int)lehmer_pi(int_sqrt(x));
	int c = (int)lehmer_pi(int_cbrt(x));
	ll sum = prime_phi(x, a) + ll(b + a - 2) * (b - a + 1) / 2;
	for (int i = a + 1; i <= b; i++) {
		ll w = x / prs[i - 1];
		sum -= lehmer_pi(w);
		if (i > c) continue;
		ll lim = lehmer_pi(int_sqrt(w));
		for (int j = i; j <= lim; j++) {
			sum -= lehmer_pi(w / prs[j - 1]) - (j - 1);
		}
	}
	return sum;
}


int main() {
	init();
	const int N = 1e6;
	vector<int> pnum(N, 1);
	vector<long long> ps;

	pnum[0] = pnum[1] = 0;

	for (int i = 2; i < N; i++) {
		if (pnum[i] > 0) {
			ps.push_back(i);
			for (int j = i * 2; j < N; j += i) {
				pnum[j] = 0;
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		pnum[i + 1] += pnum[i];
	}

	long long n;
	cin >> n;

	long long ans = 0;
	for (long long p : ps) {
		if (p * p * p <= n) ans++;
	}

	for (long long p : ps) {
		long long c = lehmer_pi(n / p) - pnum[p];
		ans += max(0ll, c);
	}

	cout << ans << endl;
}