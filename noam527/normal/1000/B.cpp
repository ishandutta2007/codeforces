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

int n, m;
vector<int> a;
int pre[100000], suf[100000];

int main() {
	fast;
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) cin >> i;
	pre[0] = a[0];
	for (int i = 1; i < n; i++)
		if (i & 1)
			pre[i] = pre[i - 1];
		else
			pre[i] = pre[i - 1] + a[i] - a[i - 1];
	if (n & 1) suf[n - 1] = 0;
	else suf[n - 1] = m - a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		if ((i + 1) & 1)
			suf[i] = suf[i + 1];
		else
			suf[i] = suf[i + 1] + a[i + 1] - a[i];

	int ans = -inf;

	for (int i = 0; i < n; i++) ans = max(ans, pre[i] + suf[i]);

	for (int i = 0; i < n - 1; i++) {
		if (a[i] + 1 < a[i + 1])
			ans = max(ans, pre[i] + (m - a[i + 1] - suf[i + 1]) + (a[i + 1] - a[i] - 1));
	}
	if (a[0] > 1)
		ans = max(ans, m - a[0] - suf[0] + a[0] - 1);
	if (a[n - 1] < m - 1)
		ans = max(ans, pre[n - 1] + (m - a[n - 1] - 1));
	finish(ans);
}