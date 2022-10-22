#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int sum = 0;
	for (int i = 2; i < n; ++i) {
		int x = n;
		while(x) {
			sum += x % i;
			x /= i;
		}
	}
	int g = __gcd(sum, n - 2);
	cout << sum / g << "/" << (n - 2) / g;
	return 0;
}