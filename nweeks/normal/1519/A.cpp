#include <bits/stdc++.h>
#define int long long
using namespace std;

bool solve()
{
	int r, b, d;
	cin >> r >> b >> d;

	if (!d)
		return r == b;
	if (r > b) swap(r, b);
	return (b-r + d-1) / d <= r;
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
		cout << (solve() ? "YES" : "NO") << '\n';
}