#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;
int st[300003], en[300003];

ll solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, --i;
	for (int i = 0; i < n; i++)
		st[i] = en[i] = -1;
	for (int i = 0; i < n; i++) {
		if (st[a[i]] == -1)
			st[a[i]] = en[a[i]] = i;
		else
			en[a[i]] = i;
	}
	vector<pair<int, int>> a;
	for (int i = 0; i < n; i++)
		if (st[i] != -1) a.emplace_back(st[i], en[i]);
	int mx = 1, cnt = 1;
	for (int i = 1; i < a.size(); i++) {
		if (a[i - 1].second < a[i].first) cnt++;
		else cnt = 1;
		mx = max(mx, cnt);
	}
	return (int)a.size() - mx;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) cout << solve() << '\n';
}