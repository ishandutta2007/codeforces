#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

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
struct hstring {
	string s;
	vector<ar<int, 2>> pre = {{0, 0}};
	void add(string t) {
		s += t;
		for (char c : t) pre.push_back(base * pre.back() + make_hash(c));
	}
	void extend(int len) {
		while(pows.size() <= len)
			pows.push_back(base * pows.back());
	}
	ar<int, 2> hash(int l, int r) {
		//assert(0 <= l && l <= r && r < s.size());
		int len = r - l + 1;
		extend(len);
		return pre[r + 1] - pows[len] * pre[l];
	}
};

}
using namespace Hashing;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	hstring ht;
	ht.add(t);
	// find period of t
	int period = -1;
	for (int i = 1; i <= t.size(); ++i) {
		if (ht.hash(0, t.size() - 1) == pows[i] * ht.hash(i, t.size() - 1) + ht.hash(t.size() - i, t.size() - 1)) {
			period = i;
			break;
		}
	}
	assert(period != -1);
	//cout << period << "\n";
	string ans(s.size(), '0');
	int cnt[2]; for (int i = 0; i < 2; ++i) cnt[i] = count(s.begin(), s.end(), '0' + i);
	for (int i = 0, j = 0; i < s.size(); ++i, ++j) {
		if (j >= t.size()) j -= period;
		int want = t[j] - '0';
		if (cnt[want]) {
			--cnt[want];
			ans[i] += want;
		}
		else {
			assert(cnt[want ^ 1]);
			--cnt[want ^ 1];
			ans[i] += want ^ 1;
		}
	}
	cout << ans;
	return 0;
}