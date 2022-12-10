//sobskdrbhvk
//remeber... ):(
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 * 1000 + 10;

void calc(int n, int val = 1) {
	if (n == 1) {
		cout << val << ' ';
		return;
	}
	if (n == 2) {
		cout << val << ' ' << val * 2 << endl;
		return;
	}
	if (n == 3) {
		cout << val << ' ' << val << ' ' << val * 3 << endl;
		return;
	}
	int cnt = (n + 1) / 2;
	for (int i = 0; i < cnt; i++)
		cout << val << ' ';
	calc(n / 2, val * 2);
}

int main() {
	int n;
	cin >> n;
	calc(n);
	return 0;
}