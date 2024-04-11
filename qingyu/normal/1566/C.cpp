#include <bits/stdc++.h>

const int N = 1e6 + 50;
using namespace std;
bool vis[4];
int a[N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int Case;
	cin >> Case;
	while (Case--)
	{
		int n;
		string s, t;
		cin >> n >> s >> t;
		int ans = 0;
		bool has_one = false;
		for (int i = 0; i < n; ++i)
		{
			int x = s[i] - 48, y = t[i] - 48;
			if (x != y)
			{
				ans += 2;
				has_one = false;
			}
			else if (x == 0 && y == 0)
			{
				if (has_one == true)
				{
					ans += 2;
					has_one = false;
				}
				else if (i + 1 == n)
				{
					++ans;
				}
				else if (s[i + 1] == 48 || t[i + 1] == 48)
				{
					++ans;
				}
				else
				{
					ans += 2;
					++i;
				}
			}
			else if (x == 1 && y == 1)
			{
				has_one = true;
			}
		}
		cout << ans << '\n';
	}
	
}