#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		int y; cin >> y;
		m = max(m, x + y);
	}
	cout << m;
}