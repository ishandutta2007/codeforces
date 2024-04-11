#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int M = 1e6 + 5;

int n, m;
vector<pair<int, int>> A, B;
vector<int> upd[M];
int cnt[M] = {};

void solve() {
	cin >> n >> m;
	A.resize(n);
	B.resize(m);
	for (auto &i : A) cin >> i.first >> i.second;
	for (auto &i : B) cin >> i.first >> i.second;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 1; i < n; i++) {
		A[i].second = min(A[i].second, A[i - 1].second);
	}
	for (int i = m - 2; i >= 0; i--) {
		B[i].second = max(B[i].second, B[i + 1].second);
	}
	for (int i = 0; i < n; i++) {
		if (OO) {
			cout << "i = " << i << '\n';
		}
		int first = -1;
		for (int j = 0; j < m; j++) {
			if (A[i].first <= B[j].first) {
				first = j;
				break;
			}
		}
		if (first == -1 || A[i].second > B[first].second) {
			upd[0].push_back(0);
			continue;
		}
		int cur = B[first].second - A[i].second + 1;
		upd[0].push_back(cur);
		if (OO) {
			cout << "pushing " << cur << '\n';
		}
		for (int j = first; j < m; j++) {
			int dx = B[j].first - A[i].first;
			int dy;
			if (j + 1 < m)
				dy = B[j + 1].second - A[i].second;
			else
				dy = -1;
			if (OO) {
				cout << "dx dy " << dx << " " << dy << '\n';
			}
			upd[dx + 1].push_back(-cur);
			if (dy < 0) {
				upd[dx + 1].push_back(0);
				break;
			}
			cur = dy + 1;
			upd[dx + 1].push_back(cur);
		}
	}
	int ans = md;
	int addy = M - 1;
	for (int x = 0; x < M; x++) {
		for (const auto &v : upd[x])
			if (v >= 0)
				cnt[v]++;
			else
				cnt[-v]--;
		while (cnt[addy] == 0) addy--;
		ans = min(ans, x + addy);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}