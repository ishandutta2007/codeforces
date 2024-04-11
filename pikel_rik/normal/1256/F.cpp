#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {
		int n;
		cin >> n;

		string s, t;
		cin >> s >> t;

		ll inv_s = 0, inv_t = 0;
		vector<int> cnt_s(26), cnt_t(26);

		bool adj_s = false, adj_t = false;

		for (int i = 0; i < n; i++) {
			for (int j = s[i] - 'a' + 1; j < 26; j++) {
				inv_s += cnt_s[j];
			}
			cnt_s[s[i] - 'a']++;
			for (int j = t[i] - 'a' + 1; j < 26; j++) {
				inv_t += cnt_t[j];
			}
			cnt_t[t[i] - 'a']++;
		}

		for (int j = 0; j < 26; j++) {
			adj_s |= cnt_s[j] > 1;
			adj_t |= cnt_t[j] > 1;
		}

		if (cnt_s == cnt_t && ((inv_s - inv_t) % 2 == 0 || adj_s || adj_t)) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
	return 0;
}