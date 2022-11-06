#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E5;
int a[MAXN];
bool seen[MAXN + 1];

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
		fill(seen + 1, seen + n + 1, false);
		vector<int> extras;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] <= n && !seen[a[i]])
			{
				seen[a[i]] = true;
			}
			else
			{
				extras.push_back(a[i]);
			}
		}
		sort(extras.begin(), extras.end());
		int ans = (int) extras.size();
		for (int i = n; i >= 1; i--)
		{
			if (seen[i])
				continue;
			if ((extras.back() - 1) / 2 < i)
			{
				ans = -1;
				break;
			}
			extras.pop_back();
		}
		cout << ans << "\n";
	}
	return 0;
}