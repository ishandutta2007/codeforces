#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

const int N = 5e3;
const int A = 1e6;

int n, k, a[N], cnt[A + 1], stn[N], sta[A];
int diff[A + 1][11], now[A + 1];
bool visited[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int d = abs(a[i] - a[j]);
			if (now[d] < 11) {
				diff[d][now[d]++] = j * n + i;
			}
		}
	}

	int ans = A + 1;
	for (int i = max(1, n - k); i <= A; i++) {
		int topn = 0, topa = 0;
		for (int j = i; j <= A && topn < 10; j += i) {
			for (int jj = 0; jj < now[j]; jj++) {
				int x = diff[j][jj] / n, y = diff[j][jj] % n, rem = a[x] % i;
				if (!cnt[rem]) {
					sta[topa++] = rem;
				}
				if (!visited[x]) {
					visited[x] = true;
					stn[topn++] = x;
					cnt[rem]++;
				}
				if (!visited[y]) {
					visited[y] = true;
					stn[topn++] = y;
					cnt[rem]++;
				}
			}
		}

		int req = 0;
		for (int j = 0; j < topa; j++) {
			req += cnt[sta[j]] - 1;
			cnt[sta[j]] = 0;
		}

		for (int j = 0; j < topn; j++) {
			visited[stn[j]] = false;
		}

		if (req <= k) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}