#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, p;
vector<ldb> a, b;

bool can(ldb t) {
	ldb sum = 0;
	for (int i = 0; i < n; i++) {
		ldb cur = a[i] * t - b[i];
		if (cur > 0) sum += cur;
	}
	if (sum / t <= p) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> p;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	ldb lo = 0, hi = 1e13, mid;
	int iter = 200;
	while (iter > 0 && hi - lo > 1e-6) {
		iter--;
		mid = (lo + hi) / 2;
		if (can(mid)) lo = mid;
		else hi = mid;
	}
	if (lo > 5e12) {
		finish(-1);
	}
	cout.precision(9);
	cout << fixed << lo << endl;

}