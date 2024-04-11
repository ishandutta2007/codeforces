#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPrime(int n) {
	if (n == 2) return 1;
	if (n <= 1 || n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0) return 0;
	return 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	srand(time(NULL));
	for (int i = rand() % ((int)1e9 - n); ; i = rand() % ((int)1e9 - n)) {
		if (!isPrime(i) && !isPrime(i + n)) {
			cout << i + n << ' ' << i << '\n';
			break;
		}
	}
}