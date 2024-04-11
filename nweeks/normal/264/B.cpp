#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;

int best[MAX] = {};

int main(void)
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> arr(N);
	for (auto &v : arr)
		cin >> v;
	
	for (int i(N-1); i >= 0; --i)
	{
		list<int> factors;
		int cur_best(0);
		for (int j(2); j * j <= arr[i]; ++j)
			if (arr[i]%j==0)
			{
				while (arr[i]%j==0)
					arr[i] /= j;
				cur_best = max(cur_best, best[j]);
				factors.push_back(j);
			}
		if (arr[i] != 1)
		{
			cur_best = max(cur_best, best[arr[i]]);
			factors.push_back(arr[i]);
		}
		for (auto e : factors)
			best[e] = max(best[e], cur_best + 1);
	}
	int ans(1);
	for (int i(0); i < MAX; ++i)
		ans = max(ans, best[i]);
	cout << ans << endl;
}