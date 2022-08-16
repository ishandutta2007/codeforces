#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2000 + 5;

int n, m, k;
pair<int, int> a[N];
vector<int> l[N], r[N], check[N];

int sect(int l1, int r1, int l2, int r2) {
	if (r1 < l2 || r2 < l1) {
		return 0;
	} else {
		return min(r1, r2) - max(l1, l2) + 1;
	}
}

int eval(int r1, int r2) {
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans += max(sect(a[i].first, a[i].second, r1 - k + 1, r1), sect(a[i].first, a[i].second, r2 - k + 1, r2));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
		l[--a[i].first].push_back(i);
		r[--a[i].second].push_back(i);
	}

	if (k == n) {
		int ans = 0;
		for (int i = 0; i < m; i++) {
			ans += a[i].second - a[i].first + 1;
		}
		cout << ans << '\n';
		return 0;
	}

	int ans = 0;
	vector<int> sect1(m);

	for (int i = k - 1; i < n - 1; i++) {
		vector<bool> inside(m);
		for (int j = 0; j < n; j++) {
			check[j].clear();
		}
		int cur = 0, behind = 0, front = 0;
		for (int x = 0; x < m; x++) {
			sect1[x] = sect(a[x].first, a[x].second, i - k + 1, i);
			cur += sect1[x];
			check[a[x].second - sect1[x] + 1].push_back(x);
			if (0 < sect1[x] && sect1[x] < k && a[x].second > i) {
				inside[x] = true;
				front++;
			}
		}

		for (int j = i + 1; j < n; j++) {
			for (int x : l[j - k]) {
				if (inside[x]) {
					if (a[x].second - a[x].first) {
						behind++;
					} else {
						cur -= 1;
						inside[x] = false;
					}
				}
			}
			cur += front - behind;
			for (int x : check[j - k + 1]) {
				if (inside[x]) {
					behind--;
				}
				inside[x] = false;
			}
			for (int x : l[j]) {
				if (a[x].second - a[x].first) {
					front++;
				}
				cur += 1;
				inside[x] = true;
			}
			for (int x : r[j]) {
				if (inside[x]) {
					if (a[x].second - a[x].first) {
						front--;
					}
				}
			}
//			cout << i << ' ' << j << ' ' << cur << ' ' << eval(i, j) << '\n';
			ans = max(ans, cur);
		}
	}
	cout << ans << '\n';
	return 0;
}