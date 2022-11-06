#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	cout << 1 << " ";
	n--;
	for (int i = 1; i < n; ++i)
	{
		if (i % 3 != 0 && (n - i) % 3 != 0)
		{
			cout << i << " " << n - i;
			return 0;
		}
	}
}