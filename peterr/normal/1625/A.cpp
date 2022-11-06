#include <bits/stdc++.h>
 
using namespace std;

const int MAXL = 30;
int freq[MAXL];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, l;
		cin >> n >> l;
		fill(freq, freq + l, 0);
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			for (int j = 0; j < l; j++)
			{
				if (x & (1 << j))
					freq[j]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < l; i++)
		{
			if (freq[i] > n / 2)
				ans = ans | (1 << i);
		}
		cout << ans << "\n";
	}
	return 0;
}