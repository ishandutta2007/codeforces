#include <bits/stdc++.h>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
#define yesno(X) cout << ((X) ? "YES" : "NO") << endl
#define noyes(X) cout << ((X) ? "NO" : "YES") << endl
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct query {
	int l, r, x;
	query(int lll = 0, int rr = 0, int xx = 0) {
		l = lll;
		r = rr;
		x = xx;
	}
	bool operator < (const query &a) const {
		return l < a.l;
	}
};

int n, q;
vector<query> a;
pair<int, int> dp[10001];
pair<int, int> tmp;

pair<int, int> cut(const pair<int, int> &st, const pair<int, int> &en) {
	if (max(st.first, en.first) > min(st.second, en.second)) return{ inf, -inf };
	return{ max(st.first, en.first), min(st.second, en.second) };
}

pair<int, int> best(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second > b.second) return a;
	if (a.second < b.second) return b;
	if (a.first < b.first) return a;
	return b;
}

int main() {
	fast;
	for (int i = 0; i < 10001; i++) dp[i] = { inf, -inf };
	cin >> n >> q;
	a.resize(q);
	for (auto &i : a) cin >> i.l >> i.r >> i.x;
	sort(a.begin(), a.end());
	dp[0] = { 0, n - 1 };
	for (const auto &i : a) {
		for (int k = n; k >= i.x; k--) {
			dp[k] = best(dp[k], cut(dp[k - i.x], { i.l - 1, i.r - 1 }));
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if (dp[i].first != inf) ans.push_back(i);
	cout << ans.size() << endl;
	for (const auto &i : ans) cout << i << " "; cout << endl;
}