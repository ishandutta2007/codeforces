#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

using ll = long long;

const int SIZE = 100010;

vector<ll> eular;
vector<ll> eular_psum;
vector<ll> cache;

ll c(int l, int r) {
	if (l == 1 && cache[r] >= 0) {
		return cache[r];
	}
	ll ret = 0;
	int m = r / l;
	for (int y = 2; y <= m; ++y) {
		int d = r / y;
		int z = min(m, r / d);
		ret += (eular_psum[z + 1] - eular_psum[y]) * d;
		y = z;
	}
	ret -= (ll)(l - 1) * (eular_psum[r / l + 1] - eular_psum[2]);
	if (l == 1) {
		cache[r] = ret;
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	vector<int> prime(SIZE);
	for (int p = 2; p < SIZE; ++p) {
		if (prime[p] == 0) {
			for (int q = p; q < SIZE; q += p) {
				prime[q] = p;
			}
		}
	}
	eular = vector<ll>(SIZE);
	eular[1] = 1;
	for (int i = 2; i < SIZE; ++i) {
		int p = prime[i];
		eular[i] = p - 1;
		int j = i / p;
		while (j % p == 0) {
			j /= p;
			eular[i] *= p;
		}
		eular[i] *= eular[j];
	}
	eular_psum = vector<ll>(eular.size() + 1);
	for (int i = 0; i < eular.size(); ++i) {
		eular_psum[i + 1] = eular_psum[i] + eular[i];
	}
	cache = vector<ll>(SIZE, -1);

	const ll INF = (1ll << 60);
	vector<vector<ll>> f(2);
	f[1] = vector<ll>(SIZE);
	for (int i = 1; i < SIZE; ++i) {
		f[1][i] = c(1, i);
	}
	for (int k = 2; ; ++k) {
		vector<ll> new_f(SIZE, INF);
		vector<int> g(SIZE);
		vector<pair<int, int>> tasks;
		tasks.push_back({k, SIZE - 1});
		while (!tasks.empty()) {
			int s = tasks.back().first;
			int t = tasks.back().second;
			tasks.pop_back();
			if (s > t) {
				continue;
			}
			int m = (s + t) / 2;
			int min_p = (s == k ? k : g[s - 1]);
			int max_p = (t == SIZE - 1 ? m : min(m, g[t + 1]));
			for (int p = min_p; p <= max_p; ++p) {
				ll t = f[k - 1][p - 1] + c(p, m);
				if (t <= new_f[m]) {
					new_f[m] = t;
					g[m] = p;
				}
			}
			tasks.push_back({ s, m - 1 });
			tasks.push_back({ m + 1, t });
		}
		f.push_back(std::move(new_f));
		if (f.back()[SIZE - 1] == 0) {
			break;
		}
	}
	int t;
	for (cin >> t; t > 0; --t) {
		int n, k;
		cin >> n >> k;
		ll ret = n;
		if (k < f.size()) {
			ret += f[k][n];
		}
		printf("%lld\n", ret);
	}
	return 0;
}