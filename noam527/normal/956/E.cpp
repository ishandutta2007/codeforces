#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, l, r;
vector<int> a, b;
int dp[10001] = {};
int cnt[10001] = {};

void upd(int x, int good = 0) {
	if (good) {
		for (int i = 10000; i >= x; i--) {
			if (dp[i - x]) {
				if (dp[i])
					cnt[i] = min(cnt[i], 1 + cnt[i - x]);
				else
					dp[i] = 1, cnt[i] = 1 + cnt[i - x];
			}
		}
		return;
	}
	for (int i = 10000; i >= x; i--)
		dp[i] = dp[i] | dp[i - x];
}
int query(int x, int y, int less) {
	for (int i = x; i <= y; i++)
		if (dp[i] && cnt[i] < less) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	dp[0] = 1;
	cin >> n >> l >> r;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0, tmp; i < n; i++) {
		cin >> tmp;
		if (tmp) b.push_back(a[i]);
		else upd(a[i]);
	}
	if (!b.size()) finish(0);
	sort(b.begin(), b.end());
	int sum = 0, k = b.size();
	for (int i = 0; i + 1 < b.size(); i++) {
		sum += b[i];
	}
	upd(b[k - 1], 1);
	while (k > 0) {
		if (query(l, r - sum, (int)b.size() - k + 1)) finish(k);
		k--;
		if (!k) break;
		upd(b[k - 1], 1);
		sum -= b[k - 1];
	}
	finish(0);
}