#include <bits/stdc++.h>

using namespace std;

int cnt[60];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		fill(cnt, cnt + 60, 0);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			for (int j = 0; j < 40; j++)
			{
				if (x & (1 << j))
					cnt[j]++;
			}
		}
		int g = *max_element(cnt, cnt + 60);
		for (int i = 0; i < 60; i++)
		{
			g = __gcd(g, cnt[i]);
		}
		//cout << "ANS ";
		for (int i = 1; i <= n; i++)
		{
			//cout << "mod " << g % i << endl;
			if (g % i == 0)
				cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}