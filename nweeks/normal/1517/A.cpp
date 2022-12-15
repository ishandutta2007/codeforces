#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve()
{
	int n;
	cin >> n;
	if (n%2050)
		return -1;

	n /= 2050;
	int rep(0);
	while (n)
	{
		rep+= n%10;
		n /= 10;
	}
	return rep;
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
		cout << solve() << '\n';
}