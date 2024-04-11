#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int arr[MAXN];
int cpy[MAXN];

int N;

int change(int first, int second)
{
	int ans = abs(first) + abs(second);
	for (int i(0); i < N; ++i)
		arr[i] = cpy[i];
	arr[0] += first;
	arr[1] += second;
	long long p = arr[1] - arr[0];
	for (int i(2); i < N; ++i)
	{
		long long d = arr[i] - arr[i-1] - p;
		if (abs(d) > 1)
			return 1e9;
		ans += abs(d);
		arr[i] -= d;
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	if (N <= 2)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i(0); i < N; ++i)
		cin >> cpy[i];
	int ans(1e9);
	for (int i(-1); i < 2; ++i)
		for (int j(-1); j < 2; ++j)
			ans = min(ans, change(i, j));
	if (ans == 1e9)
		ans = -1;
	cout << ans << endl;
}