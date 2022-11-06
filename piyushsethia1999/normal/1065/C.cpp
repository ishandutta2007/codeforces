#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n, k;
	cin >> n >> k;
	vector<int> h(n); for (int o = 0; o < n; o++) { cin >> h[o]; }
	sort(h.rbegin(), h.rend());
	int pre = 0;
	int cnt = 0;
	for (int i = 0; i < (n - 1); ++i)
	{
		int wi = i + 1;
		for (int j = 0; j < h[i] - h[i + 1]; ++j)
		{
			int m = pre;
			if (m + wi > k)
			{
				cnt++;
				pre = 0;
			}
			pre += wi;
		}
	}
	if (pre != 0)
		cnt ++;
	cout << cnt;
}