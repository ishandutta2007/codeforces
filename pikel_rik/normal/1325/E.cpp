#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <int N>
struct sieve {
	std::array<int, N + 1> spf;

	sieve() {
		spf.fill(0);
		for (int i = 2; i * i <= N; i++) {
			if (spf[i] == 0) {
				for (int j = i * i; j <= N; j += i) {
					if (spf[j] == 0) spf[j] = i;
				}
			}
		}
		for (int i = 2; i <= N; i++) {
			if (spf[i] == 0) {
				spf[i] = i;
			}
		}
	}

	bool is_prime(int x) {
		return spf[x] == x;
	}

	std::vector<std::pair<int, int>> prime_factors(int x) {
		std::vector<std::pair<int, int>> factors;
		while (x != 1) {
			if (factors.empty() || factors.back().first != spf[x]) {
				factors.emplace_back(spf[x], 0);
			}
			factors.back().second++;
			x /= spf[x];
		}
		return factors;
	}

	std::vector<int> divisors(int x) { //linear in number of divisors
		if (x == 1) {
			return {1};
		}
		int c = 0, n = x;
		for (; spf[x] == spf[n]; n /= x, c++);
		std::vector<int> d = divisors(n);
		std::vector<int> res((c + 1) * d.size());
		for (int i = 0, j = 0, p = 1; i <= c; i++, p *= spf[x]) {
			for (int item : d) {
				res[j++] = p * item;
			}
		}
		return res;
	}
};

constexpr int N = 100000;
constexpr int A = 1000000;

sieve<A> s;

int n, a[N], f[N][2], lvl[A + 1], p[A + 1], ans = N + 1;
vector<int> q, g[A + 1];

bool solo[A + 1];

void bfs(int src) {
	q.push_back(src);
	lvl[src] = 0;
	p[src] = 0;

	for (int qi = 0; qi < int(q.size()) && lvl[q[qi]] < ans; qi++) {
		int x = q[qi];
		for (int i : g[x]) {
			if (lvl[i] == -1) {
				p[i] = x;
				lvl[i] = 1 + lvl[x];
				q.push_back(i);
			} else if (i != p[x]) {
				ans = min(ans, lvl[x] + lvl[i] + 1);
			}
		}
	}

	int solo_mn1 = N + 1, solo_mn2 = N + 1;
	for (int x : q) {
		if (solo[x]) {
			if (lvl[x] < solo_mn1) {
				solo_mn2 = solo_mn1;
				solo_mn1 = lvl[x];
			} else if (lvl[x] < solo_mn2) {
				solo_mn2 = lvl[x];
			}
		}
		lvl[x] = -1;
	}
	ans = min(ans, solo_mn1 + solo_mn2 + 2);
	q.clear();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		auto fact = s.prime_factors(a[i]);
		for (auto&[p, c] : fact) {
			for (; c >= 2; c -= 2) {
				a[i] /= p * p;
			}
		}
		auto it = remove_if(fact.begin(), fact.end(), [&](const auto &item) { return !item.second; });
		fact.erase(it, fact.end());

		for (int j = 0; j < fact.size(); j++) {
			f[i][j] = fact[j].first;
		}

		if (a[i] == 1) {
			cout << "1\n";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (lvl[a[i]]) {
			cout << "2\n";
			return 0;
		} else {
			lvl[a[i]] = 1;
			if (f[i][1]) {
				g[f[i][0]].push_back(f[i][1]);
				g[f[i][1]].push_back(f[i][0]);
			} else {
				solo[f[i][0]] = true;
			}
		}
	}

	memset(lvl, -1, sizeof(lvl));

	for (int i = 1; i * i <= A; i++) {
		if (s.is_prime(i)) {
			bfs(i);
		}
	}

	cout << (ans == N + 1 ? -1 : ans) << '\n';
	return 0;
}