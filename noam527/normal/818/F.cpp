#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

void solve(ll n) {
	int k = ceil((-1 + sqrt(9 + 8 * n)) / 2.0 - 1);
	ll ans = ll(k - 2) * (k - 1) / 2 + n - 1, free = n - k;
	if (ans + 1 > 2 * (free - 1))
		cout << ans << endl;
	else
		cout << 2 * (free - 1) << endl;
}

int main() {
	ios::sync_with_stdio(0);
	int q;
	ll n;
	cin >> q;
	while (q--)
		cin >> n, solve(n);
	return 0;
}