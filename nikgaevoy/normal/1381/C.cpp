#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, x, y;

	cin >> n >> x >> y;

	vector<int> arr(n);

	for (auto &it : arr)
	{
		cin >> it;
		it--;
	}

	vector<vector<int>> wh(n + 1);

	for (int i = 0; i < arr.size(); i++)
		wh[arr[i]].push_back(i);

	vector<int> ord(wh.size());
	iota(ord.begin(), ord.end(), 0);

	sort(ord.begin(), ord.end(), [&wh](int a, int b)
	{
		return wh[a].size() < wh[b].size();
	});

	vector<int> ans(n, ord.front());

	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < wh.size(); i++)
		pq.emplace(wh[i].size(), i);

	while (x > 0)
	{
		while (wh[pq.top().second].size() != pq.top().first)
			pq.pop();

		auto q = pq.top().second;

		ans[wh[q].back()] = q;
		wh[q].pop_back();

		pq.emplace(wh[q].size(), q);

		x--;
		y--;
	}

	sort(ord.begin(), ord.end(), [&wh](int a, int b)
	{
		return wh[a].size() < wh[b].size();
	});

	vector<int> positions;

	for (auto it : ord)
		positions.insert(positions.end(), wh[it].begin(), wh[it].end());

	auto shift = wh[ord.back()].size();

	for (int i = 0; i < y; i++)
		if (arr[positions[i]] == arr[positions[(i + shift) % positions.size()]])
		{
			cout << "no" << endl;

			return;
		}
		else
			ans[positions[i]] = arr[positions[(i + shift) % positions.size()]];

	cout << "yes" << endl;

	for (auto it : ans)
		cout << it + 1 << ' ';
	cout << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}