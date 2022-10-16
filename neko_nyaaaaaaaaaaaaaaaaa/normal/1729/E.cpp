#include <bits/stdc++.h>
using namespace std;

#define int long long

int maxN = 1e18;
int cnt = 0;

void answer(int n) {
	cout << "! " << n << '\n';
	exit(0);
}

int ask(int i, int j) {
	if (cnt == 50) {
		answer(maxN);
	}

	cnt++;
	cout << "? " << i << ' ' << j << endl;
	int x; cin >> x;
	if (x == 0) exit(1);
	return x;
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 3; ; i++) {
		int d1 = ask(i, i+1);

		if (d1 == -1) {
			answer(i);
		} else {
			int d2 = ask(i+1, i);

			if (d1 != d2) {
				answer(d1+d2);
			}
		}
	}

	return 0;
}