#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << -1 << '\n';
		return ;
	}

	for (int i(0); i < n-2; ++i)
		cout << 2;
	if ((2 * (n-1))%3)
		cout << 2;
	else
		cout << 4;
	cout << 3;
	cout << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}