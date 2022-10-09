#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long k, n, w;
	cin >> k >> n >> w;
	long long need = w * (w + 1) / 2 * k;
	cout << max(0ll, need - n) << '\n';
	return 0;
}