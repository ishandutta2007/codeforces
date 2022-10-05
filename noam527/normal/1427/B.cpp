#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, k;
string s;

void solve() {
	cin >> n >> k >> s;
	int cnt = 0, seg = 0, lst = -2;
	vector<int> diff;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			cnt++;
			if (lst + 1 < i) {
				seg++;
				if (lst >= 0) {
					diff.push_back(i - lst - 1);
				}
			}
			lst = i;
		}
	}
	if (cnt == 0) {
		cout << max(0, 2 * k - 1) << '\n';
		return;
	}
	cnt = min(n, cnt + k);
	sort(diff.begin(), diff.end());
	for (auto &i : diff) {
		if (i > k) break;
		k -= i;
		seg--;
	}
	cout << 2 * cnt - seg << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) {
		solve();
	}
}