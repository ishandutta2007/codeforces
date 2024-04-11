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
		for (char c : t)
			pre.push_back(base * pre.back() + make_hash(c));
	}
	void extend(int len) {
		while(pows.size() <= len)
			pows.push_back(base * pows.back());
	}
	ar<int, 2> hash(int l, int r) {
		assert(0 <= l && l <= r && r < s.size());
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
	string s; cin >> s;
	int n = s.size();
	vector<int> p(n);
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while(j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j]) ++j;
		p[i] = j;
	}
	if (p[n - 1] == 0) {cout << "Just a legend"; return 0;}
	hstring hs;
	hs.add(s);
	int len = p[n - 1];
	for (int i = 1; i + len - 1 < n - 1; ++i)
		if (hs.hash(0, len - 1) == hs.hash(i, i + len - 1)) {
			cout << s.substr(0, len);
			return 0;
		}
	len = p[len - 1];
	cout << (len > 0 ? s.substr(0, len) : "Just a legend");
	return 0;
}