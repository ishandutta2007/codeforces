#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(1);

	int l, r, a;
	cin >> l >> r >> a;
	int team = 0;
	while (l && r) {
		l--;
		r--;
		team += 2;
	}
	while ((l > 0 || r > 0) && a) {
		a--;
		l--;
		r--;
		team += 2;
	}
	while (a > 1) {
		a -= 2;
		team += 2;
	}
	cout << team;

	return 0;
}