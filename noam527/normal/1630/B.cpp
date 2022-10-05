#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, k;
vector<int> a;
vector<int> cnt;

void solve() {
	cin >> n >> k;
	a.resize(n);
	cnt.clear();
	cnt.resize(n + 1, 0);
	for (auto &i : a) {
		cin >> i;
		cnt[i]++;
	}
	for (int i = 2; i <= n; i++)
		cnt[i] += cnt[i - 1];
	
	int x = 1, y = n;
	int nxt = 0;
	for (int i = 0; i <= n; i++) {
		while (nxt <= n && 2 * (cnt[nxt] - cnt[i]) < n + k) nxt++;
		if (nxt <= n) {
			int candx = i + 1, candy = nxt;
			if (y - x > candy - candx) {
				x = candx;
				y = candy;
			}
		}
	}
	cout << x << " " << y << '\n';
	int cnt = 0, lst = 0;
	int total = 0;
	for (int i = 0; i < n; i++) {
		if (x <= a[i] && a[i] <= y) cnt++;
		else cnt--;
		if (cnt > 0) {
			total++;
			if (total == k) {
				cout << lst + 1 << " " << n << '\n';
				break;
			}
			cout << lst + 1 << " " << i + 1 << '\n';
			lst = i + 1;
			cnt = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}