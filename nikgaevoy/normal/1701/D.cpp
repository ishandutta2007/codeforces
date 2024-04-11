#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	vector<pair<int, int>> segs(arr.size());

	for (int i = 0; i < segs.size(); i++)
	{
		segs[i].first = *ranges::partition_point(ranges::iota_view(1, ssize(arr) + 1), [&](int t)
		{
			return (i + 1) / t > arr[i];
		});
		segs[i].second = *ranges::partition_point(ranges::iota_view(1, ssize(arr) + 1), [&](int t)
		{
			return (i + 1) / t >= arr[i];
		});
	}

	vector<int> events(arr.size());
	ranges::copy(ranges::iota_view(0, (int) ssize(arr)), events.begin());

	ranges::sort(events, [&](int a, int b)
	{
		return segs[a] < segs[b];
	});

	minheap<pair<int, int>> pq;
	vector<int> ans(arr.size(), -1);

	for (int i = 1, j = 0; i <= n; i++)
	{
		while (j < ssize(events) && segs[events[j]].first <= i)
		{
			pq.emplace(segs[events[j]].second, events[j]);
			j++;
		}

		assert(!pq.empty());

		auto t = pq.top().second;
		pq.pop();

		ans[t] = i;
	}

	assert(ranges::count(ans, -1) == 0);

	for (auto it: ans)
		cout << it << ' ';
	cout << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

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
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}