#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define MOD_NUM 10

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

std::random_device rnd_dev;
std::mt19937 rnd(rnd_dev());

struct HashInfo {
	int mod;
	std::vector<int> beki;
	int base;
	HashInfo(int n) {
		mod = std::uniform_int_distribution<>(500000000, 1000000000)(rnd);
		base = std::uniform_int_distribution<>(1, mod - 1)(rnd);
		beki.resize(n + 1);
		beki[0] = 1;
		for (int i = 1; i <= n; i++) beki[i] = (int64_t) beki[i - 1] * base % mod;
	}
};

std::vector<int> build_hash(const std::string &s, const HashInfo &info) {
	std::vector<int> res(s.size() + 1);
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		cur = ((int64_t) cur * info.base + s[i]) % info.mod;
		res[i + 1] = cur;
	}
	return res;
}
int hash_substr(const std::vector<int> &hashes, const HashInfo &info, int l, int r) {
	int res = (hashes[r] - (int64_t) hashes[l] * info.beki[r - l]) % info.mod;
	return res < 0 ? res + info.mod : res;
}

int main() {
	int n = ri();
	std::string s[n];
	for (int i = 0; i < n; i++) std::cin >> s[i];
	
	std::vector<HashInfo> infos;
	for (int i = 0; i < MOD_NUM; i++) infos.emplace_back(1000000);
	std::string res = s[0];
	std::vector<int> hashes[MOD_NUM];
	for (int i = 0; i < MOD_NUM; i++) hashes[i] = build_hash(s[0], infos[i]);
	for (int i = 0; i + 1 < n; i++) {
		int connect = 10000000;
		std::vector<int> next_hash[MOD_NUM];
		for (int j = 0; j < MOD_NUM; j++) {
			next_hash[j] = build_hash(s[i + 1], infos[j]);
			int cur = 0;
			for (int k = std::min(res.size(), s[i + 1].size()); k; k--) {
				if (hash_substr(hashes[j], infos[j], res.size() - k, res.size()) ==
					hash_substr(next_hash[j], infos[j], 0, k)) {
						cur = k;
						break;
					}
			}
			connect = std::min(connect, cur);
		}
		for (int j = 0; j < MOD_NUM; j++) hashes[j].erase(hashes[j].end() - connect, hashes[j].end());
		res.erase(res.end() - connect, res.end());
		res += s[i + 1];
		for (int j = 0; j < MOD_NUM; j++) {
			int def = hashes[j].back();
			int cur = 1;
			int mod = infos[j].mod;
			bool first = 0;
			for (auto k : next_hash[j]) {
				if (!first) {
					first = 1;
					continue;
				}
				cur = (int64_t) cur * infos[j].base % mod;
				hashes[j].push_back(((int64_t) def * cur + k) % mod);
			}
		}
	}
	std::cout << res << std::endl;
	
	return 0;
}