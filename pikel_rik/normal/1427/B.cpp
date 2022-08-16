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
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		vector<int> l;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') {
				cur++;
			} else {
				if (cur) {
					l.push_back(cur);
				}
				cur = 0;
			}
		}

		int score = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'W') {
				if (i and s[i - 1] == 'W') {
					score += 2;
				} else {
					score += 1;
				}
			}
		}

		if (cur) {
			l.push_back(cur);
		}

		if (score == 0) {
			cout << max(0, 2 * k - 1) << '\n';
			continue;
		}

		int extra = 0;
		if (s.front() == 'L') {
			extra += l.front();
			l.erase(l.begin());
		}
		if (s.back() == 'L') {
			extra += l.back();
			l.pop_back();
		}

		sort(l.begin(), l.end());
		int ans = score + 2 * min(k, extra);
		for (int i : l) {
			if (i <= k) {
				score += 2 * i + 1;
				k -= i;
				ans = max(ans, score + 2 * min(k, extra));
			} else {
				ans = max(ans, score + 2 * k);
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}