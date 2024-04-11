#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

bool solve(void)
{
	ll n, d;
	cin >> n >> d;
	for (int x(n); x >= d/n-1 ; --x)
		if (x + (d+x)/(x+1) <= n)
			return true;
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	/*for (int n(1); n < 100; ++n)
	{
		int d = 1;
		while (solve(n, d))
			++d;
		cout << n << ' ' << d << endl;
	}*/

	while (t--)
		cout << (solve() ? "YES" : "NO") << '\n';
}