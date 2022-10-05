#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, l;
vector<int> a, b;

ldb check(const vector<int> &p, ldb x) {
	ldb pos = 0;
	int sp = 1;
	int nxt = 0;
	while (x > 0 && nxt < p.size()) {
		int dist = p[nxt] - pos;
		ldb need = (ldb)dist / sp;
		if (x < need) {
			pos += x * sp;
			x = 0;
			break;
		}
		x -= need;
		pos = p[nxt++];
		sp++;
	}
	if (x > 0) {
		pos = min((ldb)l, pos + x * sp);
	}
	return pos;
}

void solve() {
	cin >> n >> l;
	a.resize(n);
	for (auto &i : a) cin >> i;
	b.resize(n);
	for (int i = 0; i < n; i++) {
		b[i] = l - a[n - 1 - i];
	}
	ldb lo = 0, hi = l, mid;
	int iter = 100;
	while (iter > 0 && hi - lo > 1e-8) {
		iter--;
		mid = (lo + hi) / 2;
		if (0 && OO) {
			cout << "mid = " << mid << endl;
		}
		ldb d1 = check(a, mid);
		ldb d2 = check(b, mid);
		if (d1 + d2 >= l)
			hi = mid;
		else
			lo = mid;
	}
	cout.precision(9);
	cout << fixed << lo << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}