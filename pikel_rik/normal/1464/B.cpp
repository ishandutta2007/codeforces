#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string s;
int n, x, y, pref[N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> x >> y;
	n = s.length();

	if (x < y) {
		swap(x, y);
		reverse(s.begin(), s.end());
	}

	if (s[0] != '?') {
		pref[0][s[0] - '0']++;
	}
	for (int i = 1; i < n; i++) {
		pref[i][0] = pref[i - 1][0];
		pref[i][1] = pref[i - 1][1];
		if (s[i] != '?') {
			pref[i][s[i] - '0']++;
		}
	}

	vector<int> pos;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			pos.push_back(i);
		}
	}

	long long cur = 0;

	for (int i = 0, c0 = 0, c1 = 0; i < n; i++) {
		if (s[i] == '0' || s[i] == '?') {
			cur += (long long)y * c1;
			c0 += 1;
		} else {
			cur += (long long)x * c0;
			c1 += 1;
		}
	}

	long long ans = cur;

	int zero = count(s.begin(), s.end(), '?'), one = 0;

	for (int i : pos) {
		cur -= (long long)((i == 0 ? 0 : pref[i - 1][1]) + one) * y + (long long)(pref[n - 1][1] - pref[i][1]) * x;
		zero -= 1;
		one += 1;
		cur += (long long)(i == 0 ? 0 : pref[i - 1][0]) * x + (long long)(pref[n - 1][0] - pref[i][0] + zero) * y;
		ans = min(ans, cur);
	}

	cout << ans << '\n';
	return 0;
}