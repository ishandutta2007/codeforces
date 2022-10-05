#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, a[1000], sum = 0, r, l, ans = 0;
	bool found = false;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		if (!found) {
			if (sum >= l && sum <= r)
				found = true, ans = sum;
			else if (sum < l)
				found = true, ans = l;
		}
	}
	if (!found)
		cout << -1 << endl;
	else
		cout << ans << endl;
}