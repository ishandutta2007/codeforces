#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 9e18;
using namespace std;

const int mx = 1e9;

int ask(int x, int y) {
	cout << "? " << x << " " << y << '\n';
	fflush(stdout);
	cout.flush();
	string rtn;
	cin >> rtn;
	if (rtn[0] == 'x') return 0;
	else if (rtn[0] == 'y') return 1;
	exit(0);
	return 0;
}
void answer(int x) {
	cout << "! " << x << '\n';
	fflush(stdout);
	cout.flush();
}

void solve() {
	if (ask(0, 1) == 0) {
		answer(1);
		return;
	}
	int st = 1, prev;
	while (1) {
		prev = st;
		st *= 2;
		if (ask(st, prev) == 1) break;
	}
	int lo = prev + 1, hi = st, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (ask(mid, prev) == 1) hi = mid;
		else lo = mid + 1;
	}
	answer(lo);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string tt;
	cin >> tt;
	while (tt == "start") {
		solve();
		cin >> tt;
	}
}