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
		int a, b;
		cin >> a >> b;
		if ((a + b) & 1)
			cout << "-1\n";
		else if (a == 0 && b == 0)
			cout << "0\n";
		else if (a == b)
			cout << "1\n";
		else
			cout << "2\n";
	}
	return 0;
}