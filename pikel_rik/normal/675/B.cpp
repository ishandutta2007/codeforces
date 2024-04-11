#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	auto check = [&](int num) -> bool {
		return 1 <= num && num <= n;
	};

	int ans = 0;
	for (int e = 1; e <= n; e++) {
		int sum = b + e + a;
		int f = sum - a - c;
		int g = sum - c - d;
		int h = sum - b - d;
		ans += check(f) && check(g) & check(h);
	}
	cout << (long long)n * ans << '\n';
	return 0;
}