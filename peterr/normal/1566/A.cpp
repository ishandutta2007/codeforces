#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, s;
		cin >> n >> s;
		int cnt = (n + 2) / 2;
		cout << s / cnt << "\n";
	}
	return 0;
}