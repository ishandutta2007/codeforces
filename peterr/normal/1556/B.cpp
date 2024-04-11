#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E18;
const int MAXN = 1E5;
int a[MAXN];
int b[MAXN];

long long solve(int n)
{
	copy(a, a + n, b);
	int zeros = (n + 1) / 2;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += a[i] == 0;
	}
	if (cnt != zeros)
		return INF;
	long long ans = 0;
	int ptr0 = 0;
	int ptr1 = 0;
	for (int i = 0; i < n; i++)
	{
		ptr0 = max(ptr0, i);
		ptr1 = max(ptr1, i);
		while (ptr0 < n && b[ptr0] == 1)
			ptr0++;
		while (ptr1 < n && b[ptr1] == 0)
			ptr1++;
		int target = i & 1;
		if (b[i] == target)
			continue;
		if (target)
		{
			ans += ptr1 - i;
			swap(b[i], b[ptr1]);
		}
		else
		{
			ans += ptr0 - i;
			swap(b[i], b[ptr0]);
		}
	}
	return ans;
}

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
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] = a[i] & 1;
		}
		long long ans = solve(n);
		for (int i = 0; i < n; i++)
			a[i] = !a[i];
		ans = min(ans, solve(n));
		if (ans == INF)
			ans = -1;
		cout << ans << "\n";
	}
	return 0;
}