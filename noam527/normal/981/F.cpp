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

int n;
int L;
vector<int> a, b;
vector<pair<int, int>> c;

int dist(int x, int y) {
	return min(abs(a[x] - b[y]), L - abs(a[x] - b[y]));
}

int lowerbound(int val) {
	int add = 0;
	while (val < 0) {
		val += L;
		add--;
	}
	while (val >= L) {
		val -= L;
		add++;
	}
	static int lo, hi, mid;
	lo = 0, hi = n - 1;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (b[mid] >= val) hi = mid;
		else lo = mid + 1;
	}
	if (b[lo] < val) lo++;
	return lo + n * add;
}

bool check(int k) {
	for (int i = 0; i < n; i++) {
		c[i].first = lowerbound(a[i] - k);
		c[i].second = lowerbound(a[i] + k + 1) - 1;
	}
	for (int i = 0; i < n; i++)
		if (c[i].first > c[i].second) return false;

	for (int i = 0; i < n; i++)
		c[i].first -= i, c[i].second -= i;
	int mx = -2e9;
	for (int i = 0; i < n; i++) {
		if (mx > c[i].second) return false;
		mx = max(mx, c[i].first);
	}
	mx = 2e9;
	for (int i = 0; i < n; i++) {
		if (mx < c[i].first) return false;
		mx = min(mx, c[i].second);
	}
	return true;
}

int main() {
	fast;
	cin >> n >> L;
	if (L == 1) finish(0);
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int lo = 0, hi = L / 2 - 1, mid;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	if (!check(lo)) ++lo;
	finish(lo);
}