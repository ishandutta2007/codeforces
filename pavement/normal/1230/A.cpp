#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	for (int i = 0; i < (1<<4); i++) {
		int s = 0, ts = 0;
		for (int j = 0; j < 4; j++)
			if (i & (1<<j)) s += a[j];
			else ts += a[j];
		if (ts == s) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}