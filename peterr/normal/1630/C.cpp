#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int f[MAXN + 1];
int l[MAXN + 1];

int main()
{
	int n;
	cin >> n;
	fill(f + 1, f + n + 1, -1);
	fill(l + 1, l + n + 1, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (f[a[i]] == -1)
			f[a[i]] = i;
		l[a[i]] = i;
	}
	int ans = 0;
	int ptr = 0;
	while (ptr < n)
	{
		if (ptr == f[a[ptr]] && ptr != l[a[ptr]])
		{
			//cout << "starting " << ptr << endl;
			int nxt = l[a[ptr]];
			ans += nxt - ptr - 1;
			while (true)
			{
				int best = -1;
				while (ptr + 1 < nxt)
				{
					ptr++;
					best = max(best, l[a[ptr]]);
				}
				if (best > nxt)
				{
					ans += best - nxt - 1;
					ptr = nxt;
					nxt = best;
				}
				else
				{
					ptr = nxt + 1;
					break;
				}
			}
			//cout << "ans " << ans << endl;
		}
		else
			ptr++;
	}
	cout << ans << "\n";
	return 0;
}