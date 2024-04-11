#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
int query(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	int id; cin >> id;
	return id;
}
void guessed(int x) {
	// yay guessed )))
	cout << "! " << x << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n; cin >> n;
	int get = query(1, n);
	int ask1 = -1, ask2 = -1;
	if (get != 1) ask1 = query(1, get);
	if (get != n) ask2 = query(get, n);
	if (ask1 == get) {
		int l = 1, r = get;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			int ask = query(m, get);
			if (ask == get) l = m;
			else r = m;
		}
		guessed(l);
	}
	else {
		int l = get, r = n;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			int ask = query(get, m);
			if (ask == get) r = m;
			else l = m;
		}
		guessed(r);
	}
	return 0;
}