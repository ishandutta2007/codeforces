#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[200002], n, k, q, l, r;

void ps() {
	for (int i = 1; i < 200002; i++)
		a[i] += a[i - 1];
}

int main() {
	for (int i = 0; i < 200002; i++) a[i] = 0;
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		a[l]++, a[r + 1]--;
	}
	ps();
	for (int i = 0; i < 200002; i++)
		if (a[i] >= k)
			a[i] = 1;
		else
			a[i] = 0;
	ps();
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}
	return 0;
}