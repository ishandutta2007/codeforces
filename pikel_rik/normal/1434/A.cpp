#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int a[6], n, b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	if (n == 1) {
		cout << "0\n";
		return 0;
	}

	vector<pair<int, int>> v(6 * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			v[i * 6 + j].first = b[i] - a[j];
			v[i * 6 + j].second = i;
		}
	}

	sort(v.begin(), v.end());

	int i = 0, j = 0, cur = 1;
	vector<int> cnt(n);
	cnt[v[0].second]++;

	int ans = INT_MAX;
	while (true) {
		while (i + 1 < 6 * n && cur < n) {
			i++;
			cnt[v[i].second]++;
			if (cnt[v[i].second] == 1) {
				cur++;
			}
		}
		while (cur == n && j < i) {
			ans = min(ans, v[i].first - v[j].first);
			cnt[v[j].second]--;
			if (!cnt[v[j].second]) {
				cur--;
			}
			j++;
		}
		if (i == 6 * n - 1) {
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}