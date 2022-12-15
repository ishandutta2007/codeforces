#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &v : a) cin >> v;
	int m = a[0] % k;
	for (int i(1); i < n; ++i)
		if (a[i] % k != m)
		{
			cout << -1 << endl;
			return 0;
		}
	int mini = *min_element(a.begin(), a.end());
	long long ans(0);
	for (auto v : a)
		ans += (v - mini) / k;
	cout << ans << endl;
}