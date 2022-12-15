#include <bits/stdc++.h>
#define int long long
using namespace std;

bool is_square(int x)
{
	int lo = 1, up = x;
	while (lo < up)
	{
		int mid = (lo + up) / 2;
		if (mid * mid < x) lo = mid+1;
		else up = mid;
	}
	return lo * lo == x;
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin>> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		cout << ( (n % 2 == 0 and is_square(n/2)) or (n % 4 == 0 and is_square(n / 4)) ? "YES" : "NO" ) << '\n';
	}
}