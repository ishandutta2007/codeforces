#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve()
{
	int c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	int a1, a2, a3, a4, a5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	c1 -= a1, c2 -= a2, c3 -= a3;
	if (c1 < 0 or c2 < 0 or c3 < 0)
		return false;
	a4 -= min(c1, a4);
	a5 -= min(c2, a5);
	return a4 + a5 <= c3;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	while (t--)
	{
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}