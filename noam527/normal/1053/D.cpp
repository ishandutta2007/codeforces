#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int M = 2e6 + 10;

int n;
vector<int> a;
vector<int> useful;
map<int, int> have;
ll ans = 1;

int sieve[M], cnt[M];
vector<pair<int, int>> ind[M];

void preprocess() {
	int i = 2;
	for (; i * i <= M; i++) {
		if (!sieve[i]) {
			sieve[i] = i;
			for (int j = i * i; j < M; j += i)
				if (!sieve[j])
					sieve[j] = i;
		}
	}
	for (; i < M; i++)
		if (!sieve[i])
			sieve[i] = i;
}

void work(int val, int i) {
	if (val == 1) return;
	int p = sieve[val], c = 0;
	while (val % p == 0) {
		c++;
		val /= p;
	}
	ind[p].emplace_back(c, i);
	while (cnt[p] < c) {
		cnt[p]++;
		ans = (ans * p) % md;
	}
	work(val, i);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	preprocess();
	cin >> n;
	a.resize(n);
	useful.resize(n, 0);
	for (auto &i : a) cin >> i;
	sort(a.rbegin(), a.rend());

	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (have[x] >= 2) continue;
		ll cur = ans;
		work(x - have[x], i);
		have[x]++;
		if (have[x] == 1 && cur == ans) {
			ind[x].pop_back();
			work(x - 1, i);
			have[x]++;
		}
	}
	for (int i = 2; i < M; i++) {
		if (ind[i].size() == 0) continue;
		auto mx = *max_element(ind[i].begin(), ind[i].end());
		bool found = false;
		for (const auto &j : ind[i])
			if (mx.first == j.first && mx.second != j.second) found = true;
		if (!found)
			useful[mx.second] = 1;
	}
	if (*min_element(useful.begin(), useful.end()) == 0)
		ans = (ans + 1) % md;
	finish(ans);
}