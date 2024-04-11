#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

vector<int> deletions(int n) {
	mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

	vector<int> pf(n+1);
	vector<u64> phash(n+1);
	iota(begin(pf), end(pf), 0);
	for (int i = 2; i <= n; i++) if (pf[i] == i) {
		phash[i] = gen();
		for (int j = 2*i; j <= n; j += i) pf[j] = min(pf[j], i);
	}

	vector<u64> hash(n+1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j > 1; j /= pf[j]) {
			hash[i] ^= phash[pf[j]];
		}
		hash[i] ^= hash[i-1];
	}
	
	u64 H = accumulate(begin(hash), end(hash), 0ULL, bit_xor<u64>());

	unordered_map<u64,int> which;
	for (int i = 1; i <= n; i++) {
		which[hash[i]] = i;
	}

	if (H == 0) return {};

	if (which.contains(H)) return {which[H]};

	for (auto [h,i]: which) {
		if (which.contains(H^h)) return {i, which[H^h]};
	}

	assert(n%4 == 3);
	return {2, (n-1)/2, n};
}

int main() {
	int n; cin >> n;

	set<int> res;
	for (int k = 1; k <= n; k++) {
		res.insert(k);
	}

	for (int k: deletions(n)) res.erase(k);

	cout << size(res) << '\n';
	for (int k: res) cout << k << ' ';
	cout << '\n';
}