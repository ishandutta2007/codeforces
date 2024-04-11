#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;
vector<int> L[2], R[2];
vector<pair<int, int>> s[2];
int nxt[2];
set<int> dpos, upos;

void calc(int at) {
	vector<pair<int, int>> st = { {-md, -1} };
	for (int i = 0; i < n; i++) {
		while (st.back().first > a[i]) st.pop_back();
		L[at][i] = st.back().second;
		st.emplace_back(a[i], i);
	}
	st.clear();
	st.emplace_back(-md, n);
	for (int i = n - 1; i >= 0; i--) {
		while (st.back().first > a[i]) st.pop_back();
		R[at][i] = st.back().second;
		st.emplace_back(a[i], i);
	}
}

void prep() {
	dpos.clear();
	upos.clear();
	nxt[0] = nxt[1] = 0;
	for (int i = 0; i < 2; i++) {
		L[i].resize(n);
		R[i].resize(n);
	}
	calc(0);
	for (auto &i : a) i = -i;
	calc(1);
	for (auto &i : a) i = -i;

	s[0].resize(n);
	s[1].resize(n);
	for (int i = 0; i < n; i++) {
		s[0][i] = { L[0][i], i };
		s[1][i] = { L[1][i], i };
	}
	sort(s[0].begin(), s[0].end());
	sort(s[1].begin(), s[1].end());
}

void advance(int i) {
	for (int j = 0; j < 2; j++) {
		while (nxt[j] < n && s[j][nxt[j]].first < i) {
			if (j == 0)
				dpos.insert(s[j][nxt[j]].second);
			else
				upos.insert(s[j][nxt[j]].second);
			nxt[j]++;
		}
	}
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	prep();
	advance(0);

	int j = 0;
	int ans = 0;
	while (j < n - 1) {
		int nxtj = j;
		int r;
		
		r = R[1][j];
		auto it = dpos.lower_bound(r);
		it--;
		nxtj = max(nxtj, *it);

		r = R[0][j];
		it = upos.lower_bound(r);
		it--;
		nxtj = max(nxtj, *it);

		ans++;
		j = nxtj;
		advance(j);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}