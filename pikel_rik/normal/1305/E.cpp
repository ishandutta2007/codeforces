#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 5000 + 5;

int n, m, a[N];
int cnt[N * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	int cur = 1;
	for (int i = 0; i < n; i++) {
		while (cnt[cur] > m) {
			cur++;
		}
		a[i] = cur;
		for (int j = 0; j < i; j++) {
			cnt[a[j] + a[i]]++;
		}
		m -= cnt[cur];
		cur++;

		if (m == 0) {
			for (int j = i + 1; j < n; j++) {
				a[j] = (int) 1e8 + (j - i - 1) * cur;
			}
			break;
		}
	}

	if (m == 0) {
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << '\n';
	} else {
		cout << "-1\n";
		return 0;
	}
	return 0;
}