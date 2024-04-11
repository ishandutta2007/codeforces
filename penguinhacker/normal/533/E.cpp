#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct my_hash {
    size_t operator()(ar<int, 2> x) const {
        return x[0] ^ x[1];
    }
};

const int MOD = 1e9 + 7;

namespace Hashing {

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const ar<int, 2> base = {BDIST(rng), BDIST(rng)};

ar<int, 2> operator+ (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		if ((a[i] += b[i]) >= MOD)
			a[i] -= MOD;
	return a;
}
ar<int, 2> operator- (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		if ((a[i] -= b[i]) < 0)
			a[i] += MOD;
	return a;
}
ar<int, 2> operator* (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		a[i] = (ll)a[i] * b[i] % MOD;
	return a;
}
ar<int, 2> make_hash(char c) {
	return {c, c};
}

vector<ar<int, 2>> pows = {{1, 1}};
void extend(int len) {
	while(pows.size() <= len)
		pows.push_back(base * pows.back());
}

struct hstring {
	string s;
	vector<ar<int, 2>> pre = {{0, 0}};
	void add(string t) {
		s += t;
		for (char c : t)
			pre.push_back(base * pre.back() + make_hash(c));
	}
	ar<int, 2> hash(int l, int r) {
		//assert(0 <= l && l <= r && r < s.size());
		int len = r - l + 1;
		return pre[r + 1] - pows[len] * pre[l];
	}
};

}
using namespace Hashing;

int n;
gp_hash_table<ar<int, 2>, null_type, my_hash> solve(string s) {
	hstring hs; hs.add(s);
	gp_hash_table<ar<int, 2>, null_type, my_hash> res({}, {}, {}, {}, {1 << 22});
	for (int i = 0; i <= n; ++i) {
		ar<int, 2> cur = pows[n - i + 1] * hs.hash(0, i - 1) + hs.hash(i, n - 1);
		for (char c = 'a'; c <= 'z'; ++c) {
			res.insert(cur + pows[n - i] * make_hash(c));
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	extend(100005);
	string s, t; cin >> n >> s >> t;
	gp_hash_table<ar<int, 2>, null_type, my_hash> a = solve(s);
	gp_hash_table<ar<int, 2>, null_type, my_hash> b = solve(t);
	int ans = 0;
	for (const auto& x : a) ans += b.find(x) != b.end();
	cout << ans;
	return 0;
}