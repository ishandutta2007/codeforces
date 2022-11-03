#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t gcd(int64_t a, int64_t b) {
	while (a && b) {
		if (a > b) a %= b;
		else b %= a;
	}
	return a + b;
}
std::random_device rnd_dev;
std::mt19937_64 rnd(rnd_dev() ^ clock());
void solve() {
	int n = ri();
	int m = ri();
	std::vector<int64_t> cost(n);
	for (auto &i : cost) scanf("%" SCNd64, &i);
	std::vector<uint64_t> random(n);
	for (auto &i : random) i = rnd();
	std::vector<uint64_t> hashed(n);
	std::vector<bool> alive(n);
	for (int i = 0; i < m; i++) {
		int a = ri() - 1;
		int b = ri() - 1;
		hashed[b] ^= random[a];
		alive[b] = true;
	}
	std::unordered_map<uint64_t, int> map;
	for (int i = 0; i < n; i++) {
		if (map.count(hashed[i])) cost[map[hashed[i]]] += cost[i], alive[i] = false;
		else map[hashed[i]] = i;
	}
	int64_t res = 0;
	for (int i = 0; i < n; i++) if (alive[i]) res = gcd(res, cost[i]);
	printf("%" PRId64 "\n", res);
}
int main() {
	int t = ri();
	for (int i = 0; i < t; i++) solve();
	return 0;
}