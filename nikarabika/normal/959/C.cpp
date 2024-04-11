//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) x = min(x, y)

const int maxn = 1e5 + 10;

void correct(int n) {
	for (int i = 2; i <= n; i++)
		cout << 1 << ' ' << i << '\n';
}

void incorrect(int n) {
	if (n <= 5) {
		cout << -1 << endl;
		return;
	}
	cout << 1 << ' ' << 2 << '\n'
		<< 1 << ' ' << 3 << '\n'
		<< 1 << ' ' << 4 << '\n';
	for (int i = 5; i <= n; i++)
		cout << 2 << ' ' << i << '\n';
	return;
}

int main() {
	int n;
	cin >> n;
	incorrect(n);
	correct(n);
	return 0;
}