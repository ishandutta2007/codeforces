#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

void solve(void)
{
	int n, d;
	cin >> n >> d;
	vector<int> cnt(n);
	for (auto &v : cnt)
		cin >> v;

	for (int i(0); i < d; ++i)
	{
		int j(1);
		while (j < n and cnt[j] == 0)
			++j;
		if (j == n) continue;
		cnt[j]--;
		cnt[j-1]++;
	}
	cout << cnt[0] << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}