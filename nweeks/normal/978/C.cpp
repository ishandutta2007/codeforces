#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;

	vector<long long> a(n);
	for (auto &v : a)
		cin >> v;
	
	for (int i(0); i < n-1; ++i)
		a[i+1] += a[i];

	while (m--)
	{
		long long dorm;
		cin >> dorm;
		int ans = lower_bound(a.begin(), a.end(), dorm) - a.begin();
		cout << ans + 1 << ' ' << dorm - (ans ? a[ans-1] : 0) << '\n';
	}
}