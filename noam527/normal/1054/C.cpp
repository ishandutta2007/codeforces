#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<int> l, r;
vector<pair<int, int>> s;
vector<int> ans;

int main() {
	fast;
	cin >> n;
	l.resize(n);
	r.resize(n);
	s.resize(n);
	for (auto &i : l) cin >> i;
	for (auto &i : r) cin >> i;
	for (int i = 0; i < n; i++)
		s[i] = { l[i] + r[i], i };
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	ans.resize(n);
	ans[s[0].second] = 1;
	for (int i = 1; i < n; i++) {
		if (s[i].first == s[i - 1].first)
			ans[s[i].second] = ans[s[i - 1].second];
		else
			ans[s[i].second] = 1 + ans[s[i - 1].second];
	}

	int le, ri;
	for (int i = 0; i < n; i++) {
		le = ri = 0;
		for (int j = i - 1; j >= 0; j--)
			if (ans[i] < ans[j]) le++;
		for (int j = i + 1; j < n; j++)
			if (ans[i] < ans[j]) ri++;
		if (le != l[i] || ri != r[i]) {
			finish("NO");
		}
	}
	cout << "YES" << endl;
	for (auto &i : ans) cout << i << " "; cout << endl;
}