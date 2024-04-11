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
		string s;
		cin >> s;

		int n = int(s.length()), i = 0;
		array<int, 3> cnt = {0};

		int ans = n + 1;
		for (int j = 0; j < n; j++) {
			cnt[s[j] - '1']++;
			while (cnt[0] && cnt[1] && cnt[2]) {
				ans = min(ans, j - i + 1);
				cnt[s[i] - '1']--;
				i++;
			}
		}

		cout << (ans == n + 1 ? 0 : ans) << '\n';
	}
	return 0;
}