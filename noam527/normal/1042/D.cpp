#include <bits/stdc++.h>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

// no data structures?

int n;
ll T;
vector<ll> a, tmp;

int countless(vector<ll> &b, ll val) {
	int lo = 0, hi = b.size() - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (b[mid] < val) lo = mid + 1;
		else hi = mid;
	}
	if (b[lo] < val) lo++;
	return lo;
}

ll solve(int l, int r) {
	if (l > r) return 0LL;
	int mid = (l + r) / 2;
	ll rtn = 0, sum = a[mid];
	tmp.clear();
	tmp.reserve(r - mid + 1);
	tmp.push_back(sum);
	for (int i = mid + 1; i <= r; i++) {
		sum += a[i];
		tmp.push_back(sum);
	}
	sort(tmp.begin(), tmp.end());
	sum = 0;
	rtn += countless(tmp, T - sum);
	for (int i = mid - 1; i >= l; i--) {
		sum += a[i];
		rtn += countless(tmp, T - sum);
	}
	return rtn + solve(l, mid - 1) + solve(mid + 1, r);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> T;
	a.resize(n);
	for (auto &i : a) cin >> i;
	cout << solve(0, n - 1) << endl;
}