#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n;
int a[N];

int main() {
	cin >> n;
	int num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		num += (a[i] == 1);
	}
	if (num) {
		cout << n - num << endl;
		return 0;
	}
	int res = (int)1e9;
	for (int i = 1; i <= n; i++) {
		int cur = a[i];
		for (int j = i + 1; j <= n; j++) {
			cur = __gcd(cur, a[j]);
			if (cur == 1) {
				res = min(res, j - i + n - 1);
				break;
			}
		}
	}
	if (res >= (int)1e9) {
		cout << -1 << endl;
	} else {
		cout << res << endl;
	}
	return 0;
}