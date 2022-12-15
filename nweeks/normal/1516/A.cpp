#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto &v : arr) cin >> v;
	
	for (int l(0); l < n-1; ++l)
	{
		while (arr[l] > 0 and k > 0)
		{
			arr[l]--;
			arr[n-1]++;
			k--;
		}
	}
	for (auto v: arr)
		cout << v << ' ';
	cout << '\n';
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}