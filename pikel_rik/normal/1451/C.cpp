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

	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;

		string s, t;
		cin >> s >> t;

		vector<int> cnt0(26), cnt1(26);
		for (char ch : s) {
			cnt0[ch - 'a']++;
		}
		for (char ch : t) {
			cnt1[ch - 'a']++;
		}

		bool ok = true;
		for (int i = 0; i < 25; i++) {
			if (cnt0[i] < cnt1[i]) {
				ok = false;
				break;
			}
			cnt0[i] -= cnt1[i];
			if (cnt0[i] % k != 0) {
				ok = false;
				break;
			}
			cnt0[i + 1] += cnt0[i];
		}
		ok &= cnt0.back() == cnt1.back();
		cout << (ok ? "Yes" : "No") << '\n';
	}
	return 0;
}