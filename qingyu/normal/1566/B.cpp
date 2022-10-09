#include <bits/stdc++.h>

const int N = 1e6 + 50;
using namespace std;
bool vis[4];
int a[N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.length();
		for (int i = 0; i < 3; ++i) vis[i] = 0;
		for (int i = 0; i < n; ++i)
			vis[s[i] - 48] = 1;
		int mex = 0;
		while (vis[mex]) ++mex;
		if (mex == 0 || mex == 1) cout << mex << "\n";
		else
		{
		int opt = 0, tot = 0;
		for (int i = 0; i <= n; ++i)
		{
			if (i == n || s[i] == '2')
			{
				if (!tot) continue;
				int l = 1, r = tot;
				while (a[l] == 1) ++l;
				while (a[r] == 1) --r;
				if (l > r) continue;
				else if (l == r) ++opt;
				else
				{
					bool has_one = false;
					for (int k = l; k <= r; ++k)
						if (a[k] == 1)
							has_one = true;
					if (has_one)
					{
						opt += 2;
					}
					else ++opt;
				}
				for (int i = 0; i <= tot; ++i) a[i] = 0;
				tot = 0;
			}
			else
			{
				a[++tot] = s[i] - 48;
			}	
		}
		cout << min(opt, mex) << "\n";
		}
	}
	
}