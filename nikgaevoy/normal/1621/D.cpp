#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

constexpr array dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};


ll Dijkstra(const vector<vector<int>> &gr)
{
	minheap<tuple<ll, int, int>> pq;
	vector<vector<ll>> dist(gr.size(), vector<ll>(gr.size(), -1));

	pq.emplace();

	while (!pq.empty())
	{
		auto[d, x, y] = pq.top();
		pq.pop();

		if (dist[y][x] == -1)
		{
			dist[y][x] = d;

			for (int j = 0; j < dx.size(); j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= ssize(gr))
					nx -= ssize(gr);
				if (nx < 0)
					nx += ssize(gr);
				if (ny >= ssize(gr))
					ny -= ssize(gr);
				if (ny < 0)
					ny += ssize(gr);

				pq.emplace(d + gr[ny][nx], nx, ny);
			}
		}
	}

	return dist.back().back();
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> arr(2 * n, vector<int>(2 * n));

	for (auto &row: arr)
		for (auto &it: row)
			cin >> it;

	ll ans = 0;

	for (int i = n; i < 2 * n; i++)
		for (int j = n; j < 2 * n; j++)
		{
			ans += arr[i][j];
			arr[i][j] = 0;
		}

	cout << ans + min({arr[0][n], arr[n - 1][n], arr[n][0], arr[n][n - 1],
	                   arr[0].back(), arr[n - 1].back(), arr.back()[0], arr.back()[n - 1]}) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
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