#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 50;

int n, d, a[N];
bool b[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) b[i] = 0;
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!b[i])
			{
				vector<int> v;
				int p = i;
				bool all_one = 1;
				while (!b[p])
				{
					v.push_back(a[p]);
					b[p] = true;
					p = (p + d) % n;
					if (!a[p]) all_one = 0;
				}
				int x = 0, first = 0;
				for (int y : v)
				{
					if (!y) ans = max(ans, x), x = 0;
					else ++x;
				}
				for (int y : v)
				{
					if (!y) break;
					++first;
				}
				ans = max(ans, x + first);
				
				if (all_one)
				{
					ans = -1;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}

}