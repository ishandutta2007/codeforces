#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> arr(n);

	for (auto &it : arr)
		cin >> it.first;
	for (auto &it : arr)
		cin >> it.second;

	sort(arr.begin(), arr.end());

	ll ans = 0, sum = 0;
	int last = 0;

	priority_queue<int> pq;

	for (auto it : arr)
	{
		while (last < it.first && !pq.empty())
		{
			sum -= pq.top();
			ans += sum;
			pq.pop();
			last++;
		}

		last = it.first;
		pq.emplace(it.second);
		sum += it.second;
	}

	while (!pq.empty())
	{
		sum -= pq.top();
		ans += sum;
		pq.pop();
		last++;
	}

	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}