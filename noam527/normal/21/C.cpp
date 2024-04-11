#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
#define endl '\n'
using namespace std;
/*
 Time Complexity: O(N)
 No DP, no Binary Search and no sorting.
 */
int main() {
	int n, a[100000], sum = 0, cnt = 0, curr = 0;
	ll ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	if (sum % 3 != 0 || n < 3) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		curr += a[i];
		if (curr == sum * 2 / 3) ans += cnt;
		if (curr == sum / 3) cnt++;
	}
	cout << ans << endl;
	return 0;
}