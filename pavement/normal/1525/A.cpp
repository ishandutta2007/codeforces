#include <bits/stdc++.h>
using namespace std;

int T, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> K;
		cout << 100 / __gcd(100, K) << '\n';
	}
}