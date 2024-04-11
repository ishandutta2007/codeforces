#include <bits/stdc++.h>

using namespace std;

long long sum(int x)
{
	return (long long) x * (x + 1) / 2;
}

long long f(int k, int lines)
{
	long long ans = 0;
	if (lines >= k)
		ans += k;
	ans += sum(min(k - 1, lines));
	ans += sum(k - 1);
	ans -= sum(min(k - 1, 2 * k - 1 - lines));
	return ans;
}

int main()
{
	//for (int i = 0; i <= 5; i++)
	//{
		//cout << f(3, i) << endl;
	//}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		long long x;
		cin >> k >> x;
		long long lo = 0;
		long long hi = 2 * k - 2;
		while (lo < hi)
		{
			int mid = (int) ((lo + hi + 1) / 2);
			if (f(k, mid) >= x)
				hi = mid - 1;
			else
				lo = mid;
		}
		cout << lo + 1 << "\n";
	}
	return 0;
}