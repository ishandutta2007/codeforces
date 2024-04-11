#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
using namespace std;

int n, m;
int a[1001][1001];
pair<int, int> b[1001][1001];
pair<int, int> tmp[1001];
int ans[1001][1001];

int calc(pair<int, int> aa, pair<int, int> bb) {
	if (aa.first < bb.first) {
		aa.second += bb.first - aa.first;
	}
	else {
		bb.second += aa.first - bb.first;
	}
	return max(aa.second, bb.second);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) tmp[j] = { a[i][j], j };
		sort(tmp, tmp + m);
		int val = 1;
		b[i][tmp[0].second].first = val;
		for (int j = 1; j < m; j++) {
			if (tmp[j - 1].first != tmp[j].first) val++;
			b[i][tmp[j].second].first = val;
		}
		for (int j = 0; j < m; j++)
			b[i][j].second = val;
	}

	if (OO) {
		cout << b[0][2].first << " " << b[0][2].second << '\n';
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) tmp[i] = { a[i][j], i };
		sort(tmp, tmp + n);
		int val = 1, mx;
		for (int i = 1; i < n; i++)
			if (tmp[i - 1].first != tmp[i].first) val++;
		mx = val;
		val = 1;

		ans[tmp[0].second][j] = calc(b[tmp[0].second][j], { val, mx });
		for (int i = 1; i < n; i++) {
			if (tmp[i - 1].first != tmp[i].first) val++;
			ans[tmp[i].second][j] = calc(b[tmp[i].second][j], { val, mx });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << ans[i][j] << " "; cout << '\n';
	}
}