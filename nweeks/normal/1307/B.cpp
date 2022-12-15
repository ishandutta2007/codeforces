#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

void solve(void)
{
	int n, x;
	cin >> n >> x;

	vector<int> jumps(n);
	for (auto &v : jumps)
		cin >> v;
	sort(jumps.begin(), jumps.end());

	int bst(n-1);
	int ans(1e9);
	while (bst > 0 and jumps[bst] > x)
	{
		bst--;
		ans = min(ans, 2);
	}
	if (jumps[bst] <= x)
		ans = min(ans, (jumps[bst]-1 + x)/jumps[bst]);
	else
		ans = min(ans, 2);
	cout << ans << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}