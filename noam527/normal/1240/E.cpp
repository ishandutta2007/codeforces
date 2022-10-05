#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int mxn = 5e5 + 5;

int F[mxn + 2] = {};
int have[mxn + 2] = {};
int totalhave = 0;
int nxtupd = mxn;

void upd(int x) {
	while (x <= nxtupd) {
		F[nxtupd] = F[nxtupd + 1];
		nxtupd--;
	}
	F[x]++;
}
int query(int l, int r) {
	if (r > mxn) r = mxn;
	if (l > r) return 0;
	if (r <= nxtupd) return 0;
	l = max(l, nxtupd + 1);
	return F[l] - F[r + 1];
}
int bigquery(int sz, int y) {
	int rtn = 0;
	for (int i = y - 1; i - sz + 1 <= mxn; i += y) {
		rtn += query(i - sz + 1, i);
		if (rtn >= 2) return rtn;
	}
	return rtn;
}

pair<int, int> best(int y) {
	int lo, hi, mid;

	int m1 = -1, m2 = -1;
	int v1 = 0, v2 = 0;

	if (OO) {
		cout << "calc best " << y << '\n';
		cout << "total " << totalhave << '\n';
		for (int i = 1; i <= 30; i++) cout << F[i] << " "; cout << '\n' << '\n';
	}

	if (totalhave >= 1) {
		lo = 1, hi = y;
		while (lo < hi) {
			mid = (lo + hi) / 2;
			if (bigquery(mid, y) >= 1) hi = mid;
			else lo = mid + 1;
		}
		m1 = y - lo;
		if (OO) cout << "m1 " << m1 << '\n';
		for (int i = m1; i <= mxn; i += y)
			if (have[i]) v1 = i;
		if (OO) cout << "v1 " << v1 << '\n';
		have[v1]--;
	}
	else return{ 0, 0 };

	if (totalhave >= 2) {
		lo = 1, hi = y;
		while (lo < hi) {
			mid = (lo + hi) / 2;
			if (bigquery(mid, y) >= 2) hi = mid;
			else lo = mid + 1;
		}
		m2 = y - lo;
		if (OO) cout << "m2 " << m2 << '\n';
		for (int i = m2; i <= mxn; i += y)
			if (have[i]) v2 = i;
		if (OO) cout << "v2 " << v2 << '\n';
	}
	have[v1]++;
	return make_pair(v1, v2);
}

int n;
int A[mxn + 1] = {};
int ps[mxn + 1] = {};
ll C[mxn + 1] = {};

int x = 0, y = 2;
ll ans = 0;
pair<int, int> bestpair = { 0, 0 };

void incy() {
	y++;
	bestpair = best(y);
}
void decx() {
	x--;
	if (x < 2) return;
	for (int times = 0; times < A[x]; times++) {
		have[x]++;
		totalhave++;
		upd(x);
		if (bestpair.second % y < x % y || (bestpair.second % y == x % y && bestpair.second < x)) {
			bestpair.second = x;
			if (bestpair.first % y < bestpair.second % y || (bestpair.first % y == bestpair.second % y && bestpair.first < bestpair.second))
				swap(bestpair.first, bestpair.second);
		}
	}
}

bool can() {
	if (OO) {
		cout << "can x y " << x << " " << y << '\n';
		cout << "bestpair " << bestpair.first << " " << bestpair.second << '\n';
	}
	ll total = C[y];
	pair<int, int> tmp = bestpair;
	if (tmp.first / x + tmp.second / x < 2) return false;
	total = total - tmp.first / y - tmp.second / y;
	tmp.first -= x;
	if (tmp.first < x || tmp.first % y < tmp.second % y) tmp.second -= x;
	else tmp.first -= x;
	total += tmp.first / y + tmp.second / y;
	if (total >= x) {
		ans = max(ans, (ll)x * y);
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		A[val]++;
		x = max(x, val + 1);
	}
	for (int i = 1; i <= mxn; i++)
		ps[i] = ps[i - 1] + A[i];
	// make C
	for (int yy = 2; yy <= mxn; yy++) {
		int l = yy, r = 2 * yy - 1;
		if (r > mxn) r = mxn;
		while (l <= mxn) {
			C[yy] += ll(ps[r] - ps[l - 1]) * (l / yy);
			l += yy, r += yy;
			if (r > mxn) r = mxn;
		}
	}

	while (x >= 2) {
		if (can()) incy();
		else decx();
	}
	finish(ans);
}