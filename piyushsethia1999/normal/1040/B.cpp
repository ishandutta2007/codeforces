#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t = 1;
	for (int iii = 0; iii < t; ++iii)
	{
		int n; cin >> n;
		int k; cin >> k;
		int o = (n / (2 * k + 1));
		if (n % (2 * k + 1)) {
			o++;
			cout << o << "\n";
			int in = 1 + max(n % (2 * k + 1) - k, 0);
			for (int i = 0; i < o; ++i)
			{
				cout << in << " ";
				in += (2 * k  + 1);
			}
		}
		else
		{
			cout << o << "\n";
			int in = k + 1;
			for (int i = 0; i < o; ++i)
			{
				cout << in << " ";
				in += (2 * k  + 1);
			}
		}
		cout << "\n";
	}

}