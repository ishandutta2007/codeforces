#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
bool used[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		fill(used, used + n, false);
		int ans = 0;
		int ptr = 0;
		for (int i = 0; i < n; i++)
		{
			if (used[i])
				continue;
			while (ptr < n && (a[ptr] < (long long) x * a[i] || used[ptr]))
				ptr++;
			if (ptr < n && (long long) x * a[i] == a[ptr])
				used[ptr] = true;
			else
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}