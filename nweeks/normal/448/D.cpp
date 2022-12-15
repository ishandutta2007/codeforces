#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k;

inline int count_under_row(ll row, ll upper)
{
	return min(row*m, upper) / row;
}

inline ll count_under_table(ll upper)
{
	ll ans(0);
	for (int i(1); i <= n; ++i)
		ans += count_under_row(i, upper);
	return ans;
}

int main(void)
{
	cin >> n >> m >> k;

	ll left(1), right(n*m);
	for (int i(0); i < 100; ++i)
	{
		ll mid = (left+right)/2;

		ll ret = count_under_table(mid);
		if (ret < k)
			left = mid + 1;
		else if (ret > k)
			right = mid - 1;
		else
			right = mid - (count_under_table(mid-1)==k ? 1 : 0);
	}
	cout << left << endl;
}