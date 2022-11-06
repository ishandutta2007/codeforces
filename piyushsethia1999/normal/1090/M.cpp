#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	int y = 1;
	int curr = 0;
	int prevcolor = -1;
	for (int i = 0; i < n; ++i)
	{
		int u; cin >> u;
		if (u == prevcolor)
		{
			y = max(y, curr);
			curr = 1;
		}
		else
		{
			curr++;
			prevcolor = u;
			y = max(y, curr);
		}
	}
	cout << y;
}