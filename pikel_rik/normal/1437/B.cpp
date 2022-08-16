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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<int> segs;

		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] - '0' != (i & 1)) {
				cur++;
			} else {
				if (cur) {
					segs.push_back(cur);
				}
				cur = 0;
			}
		}

		if (cur) {
			segs.push_back(cur);
		}

		int ans1 = segs.size();

		segs.clear();
		cur = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] - '0' != ((i & 1) ^ 1)) {
				cur++;
			} else {
				if (cur) {
					segs.push_back(cur);
				}
				cur = 0;
			}
		}

		if (cur) {
			segs.push_back(cur);
		}

		int ans2 = segs.size();

		cout << min(ans1, ans2) << '\n';
	}
	return 0;
}