#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define wait cin.ignore(), cin.get()
typedef long long ll;
typedef long double ldb;
const int inf = 1e9 + 7;
const int OO = 0;
using namespace std;

const ll lim = 1e14, hlim = 1e7;
const int lo = 2e6;

int dig[15], len;
int W[1000000], nxt = 0;

void con(ll x) {
	len = 0;
	while (x) {
		dig[len++] = x % 10;
		x /= 10;
	}
	reverse(dig, dig + len);
}

bool wavy(ll x) {
	if (x < 10) return true;
	int f, l, dir;
	l = x % 10, x /= 10;
	f = x % 10, x /= 10;
	if (f == l) return false;
	if (f < l) dir = 0;
	else dir = 1;
	while (x) {
		l = f;
		f = x % 10, x /= 10;
		if (dir && f >= l) return false;
		else if (!dir && f <= l) return false;
		dir ^= 1;
	}
	return true;
}
bool realwavy(ll x) {
	if (10 <= x && x < 100 && x / 10 == x % 10) return false;
	con(x);
	for (int i = 1; i < len - 1; i++)
		if (dig[i - 1] == dig[i] || dig[i] == dig[i + 1] || (dig[i - 1] <= dig[i] && dig[i] <= dig[i + 1]) || (dig[i - 1] >= dig[i] && dig[i] >= dig[i + 1])) return false;
	return true;
}

ll pw[15], n, k;

int S[lo][10][2] = {};

void calc() {
	for (int i = 1; i < hlim; i++) {
		if (wavy(i)) {
			W[nxt++] = i;
			if (i % n == 0) k--;
			if (k == 0) {
				cout << i << '\n';
				wait;
				exit(0);
			}
			if (i >= hlim / 100) {
				con(i);
				if (len == 6 && dig[0] > dig[1]) {
					S[i % n][0][1]++;
				}
				else if (len == 7) {
					if (dig[0] < dig[1]) S[i % n][dig[0]][1]++;
					else S[i % n][dig[0]][0]++;
				}
			}
		}
	}
	for (int i = 0; i < lo; i++) {
		for (int j = 1; j < 10; j++)
			S[i][j][1] += S[i][j - 1][1];
		for (int j = 8; j >= 0; j--)
			S[i][j][0] += S[i][j + 1][0];
	}
}

int brute(int k) {
	for (int i = 1;; i++) {
		if (wavy(i)) k--;
		if (!k) return i;
	}
}

int realbrute(int k) {
	for (int i = 1;; i++) {
		if (realwavy(i)) k--;
		if (!k) return i;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	pw[0] = 1;
	for (int i = 1; i < 15; i++) pw[i] = 10LL * pw[i - 1];

	cin >> n >> k;
	if (n > lim / k) {
		cout << -1;
		wait;
		return 0;
	}
	if (n >= lo) {
		for (ll i = n; i <= lim; i += n) {
			if (wavy(i)) k--;
			if (!k) {
				cout << i << '\n';
				wait;
				return 0;
			}
		}
		cout << -1;
		wait;
		return 0;
	}

	if (n < 10 && n * k < 10) {
		cout << n * k << '\n';
		wait;
		return 0;
	}

	calc();

	ll start = -1;
	for (int ii = 0; ii < nxt; ii++) {
		ll i = W[ii];
		con(i);
		ll mneed = (-i * 10000000 % n + n) % n;
		int cur = 0;
		if ((len == 1 && i > 0) || dig[len - 2] < dig[len - 1]) cur += S[mneed][dig[len - 1] - 1][1];
		if ((len == 1 && i < 9) || (len > 1 && dig[len - 2] > dig[len - 1])) cur += S[mneed][dig[len - 1] + 1][0];
		if (OO) cout << "for start " << i << ", need mod " << mneed << ". there are " << cur << '\n';
		if (OO) cout << "current k " << k << '\n';
		if (cur >= k) {
			start = i;
			break;
		}
		k -= cur;
	}
	if (start == -1) {
		cout << -1;
		wait;
		return 0;
	}
	for (int i = hlim / 100; i < hlim; i++) {
		ll val = start * 10000000 + i;
		if (val % n == 0 && wavy(val)) {
			k--;
			if (k == 0) {
				cout << val << '\n';
				wait;
				return 0;
			}
		}
	}
	cout << "error\n";

	cin.ignore();
	cin.get();
}