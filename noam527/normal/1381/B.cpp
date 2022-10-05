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
int dp[4005];

void solve() {
	cin >> n;
	a.resize(2 * n);
	for (auto &i : a) cin >> i;
	vector<int> s;
	int nxt = 2 * n - 1;
	while (nxt >= 0) {
		int at = 0;
		for (int i = 1; i <= nxt; i++)
			if (a[at] < a[i]) at = i;
		s.push_back(nxt - at + 1);
		nxt = at - 1;
	}
	for (int i = 0; i <= 2 * n; i++) dp[i] = 0;
	dp[0] = 1;
	for (const auto &i : s) {
		for (int j = 2 * n; j >= i; j--)
			dp[j] |= dp[j - i];
	}
	if (dp[n]) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) solve();
}