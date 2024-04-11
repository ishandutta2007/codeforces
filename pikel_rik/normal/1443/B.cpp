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
		int a, b;
		cin >> a >> b;

		string s;
		cin >> s;
		while (!s.empty() && s.back() == '0') {
			s.pop_back();
		}
		reverse(s.begin(), s.end());
		while (!s.empty() && s.back() == '0') {
			s.pop_back();
		}
		int n = s.length();

		vector<int> seg;
		int c = 0, cur = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '1' && (i == 0 || s[i - 1] != '1')) {
				c++;
				if (cur) seg.push_back(cur);
				cur = 0;
			} else if (s[i] == '0') {
				cur++;
			}
		}

		int ans = a * c;
		sort(seg.begin(), seg.end());

		cur = 0;
		for (int l : seg) {
			cur += b * l;
			c--;
			ans = min(ans, cur + a * c);
		}
		cout << ans << '\n';
	}
	return 0;
}