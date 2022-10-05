#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
using namespace std;

const int N = 2e6 + 10000;

bool isgood(int x) {
	int z = (int)sqrt(x);
	return x - z * z < (z + 1) * (z + 1) - x;
}
int nextsq(int x) {
	int z = (int)sqrt(x);
	return (z + 1) * (z + 1) - x;
}

int n;
int a[N / 2];
int c[N], last[N], nxt[N];

int first_check() {
	bool good = true;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		if (!isgood(a[i])) {
			good = false;
			if (OO) cout << a[i] << " is not good\n";
			if (OO) cout << nextsq(a[i]) << '\n';
			mx = max(mx, nextsq(a[i]));
		}
	}
	if (good) return 0;
	good = true;
	for (int i = 0; i < n; i++) {
		if (!isgood(a[i] + mx)) {
			good = false;
			break;
		}
	}
	if (good) return mx;
	return -1;
}

int second_check(int k) {
	if (OO) cout << "second check " << k << '\n';
	int mnin = md; // do mnin, you lose
	int mxout = 0; // do at least mxout
	int start = 0;
	for (int i = 0, j;; i++) {
		if (start > N) break;
		j = last[min(N - 1, start + k + i)];
		mnin = min(mnin, start + k + i - j + 1);
		if (start + k + i + 1 >= N)
			j = md;
		else
			j =	nxt[start + k + i + 1];
		mxout = max(mxout, start + 2 * (k + i) + 1 - j);

		start += 2 * (k + i) + 1;
	}
	if (OO) {
		cout << "mnin " << mnin << ", mxout " << mxout << '\n';
	}
	if (mnin > mxout) return mxout;
	return -1;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i] - a[0]] = 1;
	}
	last[0] = 0;
	for (int i = 1; i < N; i++) {
		if (c[i]) last[i] = i;
		else last[i] = last[i - 1];
	}
	nxt[N - 1] = md;
	for (int i = N - 2; i >= 0; i--) {
		if (c[i]) nxt[i] = i;
		else nxt[i] = nxt[i + 1];
	}
	int tmp = first_check();
	if (tmp != -1) {
		cout << tmp << '\n';
		return;
	}

	if (OO) cout << "failed first\n";

	int k = 1;
	while (a[0] >= k * k) k++;

	for (; k < N; k++) {
		int tmp = second_check(k);
		if (tmp != -1) {
			cout << (ll)k * k - a[0] + tmp << '\n';
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}