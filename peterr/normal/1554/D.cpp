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
		int n;
		cin >> n;
		if (n & 1)
		{
			n--;
			cout << 'z';
		}
		for (int i = 0; i < n / 2; i++)
		{
			cout << 'a';
		}
		if (n)
			cout << 'b';
		for (int i = 0; i < n / 2 - 1; i++)
		{
			cout << 'a';
		}
		cout << "\n";
	}
}