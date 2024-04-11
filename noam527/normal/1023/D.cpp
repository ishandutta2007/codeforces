#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, q;
vector<int> a, st, en, ans;
vector<pair<int, int>> eve;
set<int> val;

int main() {
	fast;
	cin >> n >> q;
	a.resize(n);
	ans.resize(n, 0);
	st.resize(q + 1, inf);
	en.resize(q + 1, -1);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			st[a[i]] = min(st[a[i]], i);
			en[a[i]] = max(en[a[i]], i);
		}
	}
	if (find(a.begin(), a.end(), 0) == a.end() && find(a.begin(), a.end(), q) == a.end()) finish("NO");

	for (int i = 1; i <= q; i++) {
		if (st[i] != inf) {
			eve.push_back({ st[i], i });
			eve.push_back({ en[i] + 1, i });
		}
	}
	sort(eve.begin(), eve.end());
	int nxt = 0;
	for (int i = 0; i < n; i++) {
		while (nxt < eve.size() && eve[nxt].first <= i) {
			if (val.count(eve[nxt].second)) val.erase(eve[nxt].second);
			else val.insert(eve[nxt].second);
			nxt++;
		}
		if (val.size() != 0) {
			ans[i] = *val.rbegin();
		}
	}
	if (find(ans.begin(), ans.end(), q) == ans.end()) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				ans[i] = q;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != 0 && ans[i] != a[i]) finish("NO");
		if (ans[i] == 0) ans[i] = 1;
	}
	cout << "YES" << endl;
	for (const auto &i : ans) cout << i << " "; cout << endl;
}