#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e6 + 5;

int ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	int cnt_a = -1, cnt_b = -1;
	for (int i = 0; i <= n / a; i++) {
		if ((n - i * a) % b == 0) {
			cnt_a = i;
			cnt_b = (n - i * a) / b;
			break;
		}
	}

	if (cnt_a == -1) {
		cout << "-1\n";
		return 0;
	}

	iota(ans, ans + N, 0);
	for (int i = 1; i <= n && cnt_a; i += a) {
		if (a > 1) {
			rotate(ans + i, ans + i + 1, ans + i + a);
		}
		cnt_a--;
	}

	for (int i = n; i >= 1 && cnt_b; i -= b) {
		int j = i - b + 1;
		if (b > 1) {
			rotate(ans + j, ans + j + 1, ans + j + b);
		}
		cnt_b--;
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
	return 0;
}