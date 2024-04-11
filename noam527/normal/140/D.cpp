#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, s1 = 0, s2 = 0, i, j, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (i = 1; i < n; i++) a[i] += a[i - 1];
	for (i = 0; i < n; i++) a[i] = max(a[i] - 350, 0);
	i = 0;
	while (i < n && a[i] <= 360) ans += a[i++];
	cout << i << " " << ans << endl;
}