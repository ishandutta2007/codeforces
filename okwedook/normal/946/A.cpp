#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &i : arr) cin >> i;
	ll ans = 0;
	for (auto i : arr) ans += abs(i);
	cout << ans;
	return 0;
}