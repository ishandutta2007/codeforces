#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


pair<int, int> operator/(const pair<int, int> &a, int b)
{
	return {a.first / b, a.second / b};
}


pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b)
{
	return {a.first - b.first, a.second - b.second};
}


ll len2(const pair<int, int> &a)
{
	return a.first * (ll) a.first + a.second * (ll) a.second;
}


template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int k, n;

	cin >> n >> k;

	vector<pair<int, int>> arr(n);

	for (auto &it : arr)
		cin >> it.first >> it.second;

	map<pair<int, int>, vector<pair<int, int>>> dirs;

	for (const auto &it : arr)
	{
		if (it == pair{0, 0})
		{
			dirs[it].push_back(it);
		}
		else
		{
			auto g = __gcd(abs(it.first), abs(it.second));

			dirs[it / g].push_back(it);
		}
	}

	for (auto &it : dirs)
		sort(it.second.begin(), it.second.end(), [](const auto &a, const auto &b)
		{
			return len2(a) > len2(b);
		});

	priority_queue<tuple<double, pair<int, int>, int>> pq;
	double ans = 0;

	for (auto &row : dirs)
		pq.emplace(sqrt(len2(row.second.front())) * (k - 1), row.first, 0);

	for (int j = 0; j < k; j++)
	{
		double add;
		pair<int, int> cd;
		int i;

		tie(add, cd, i) = pq.top();
		pq.pop();

		auto &row = dirs[cd];

		if (add < 0 && row.begin() + i != row.end() - (k - j))
		{
			assert(pq.empty());

			row.erase(row.begin() + i, row.end() - (k - j));
			j--;
		}
		else
		{
			ans += add;

//			cerr << row[i].first << ' ' << row[i].second << endl;
			i++;
		}

		if (i < row.size())
			pq.emplace(sqrt(len2(row[i])) * (k - 1 - 2 * i), cd, i);
	}

	cout << fixed << setprecision(20);
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

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}