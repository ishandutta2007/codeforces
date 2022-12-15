#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

void solve(void)
{
	string a, b, c;
	cin >> a >> b >> c;

	int n = a.size();

	for (int i(0); i < n; ++i)
	{
		if (!(c[i] == a[i] or c[i] == b[i]))
		{
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}