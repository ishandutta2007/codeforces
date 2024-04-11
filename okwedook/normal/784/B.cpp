#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	int arr[] = { 1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0 };
	int a;
	cin >> a;
	if (a == 0) return 0 * puts("1");
	int ans = 0;
	while (a > 0) {
		ans += arr[a % 16];
		a /= 16;
	}
	cout << ans;
	return 0;
}