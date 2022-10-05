#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m, k;
ll A, B;
vector<ll> a, b;
ll ans = -inf;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> A >> B >> k;
	if (k >= n || k >= m) finish(-1);
	a.resize(n);
	b.resize(m);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n && i <= k; i++) {
		int left = k - i;
		int it = lower_bound(b.begin(), b.end(), a[i] + A) - b.begin();
		if (it + left >= b.size()) finish(-1);
		ans = max(ans, b[it + left] + B);
	}
	finish(ans);
}