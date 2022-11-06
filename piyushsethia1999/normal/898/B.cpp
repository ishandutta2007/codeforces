#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int a; cin >> a;
	int b; cin >> b;
	int sx = -1;
	int sy = -1;
	for (int i = 0; i <= n; ++i)
	{
		if (((n - (i * a)) % b == 0) && (((n - (i * a)) / b) >= 0))
		{
			cout << "YES\n";
			cout << i << " " << (n - (i * a)) / b;
			return 0;
		}
	}
	cout << "NO\n";
}