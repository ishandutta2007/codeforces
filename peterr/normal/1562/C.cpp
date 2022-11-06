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
		string s;
		cin >> n >> s;
		bool nozeros = all_of(s.begin(), s.end(), [&] (char ch) { return ch == '1'; });
		if (nozeros)
		{
			int len = n / 2;
			cout << "1 " << len << " ";
			cout << n - len + 1 << " " << n << "\n";
		}
		else
		{
			int ind = (int) s.find("0");
			if (ind >= n / 2)
			{
				cout << "1 " << ind + 1 << " ";
				cout << "1 " << ind << "\n";
			}
			else
			{
				cout << ind + 1 << " " << n << " ";
				cout << ind + 2 << " " << n << "\n";
			}
		}
	}
	return 0;
}