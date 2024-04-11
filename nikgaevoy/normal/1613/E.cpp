#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<string> field(n);

	for (auto &row: field)
		cin >> row;

	queue<pair<int, int>> q;

	for (auto y: ranges::iota_view(0, ssize(field)))
		for (auto x: ranges::iota_view(0, ssize(field[y])))
			if (field[y][x] == 'L')
				q.emplace(x, y);

	constexpr array dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

	auto is_inside = [&](int x, int y)
	{
		return 0 <= y && y < n && 0 <= x && x < m;
	};

	while (!q.empty())
	{
		auto[x, y] = q.front();
		q.pop();

		if (field[y][x] != 'L')
			field[y][x] = '+';

		for (auto i: ranges::iota_view(0, ssize(dx)))
		{
			auto px = x + dx[i];
			auto py = y + dy[i];

			if (is_inside(px, py) && field[py][px] == '.')
			{
				int cnt = 0;

				for (auto j: ranges::iota_view(0, ssize(dx)))
				{
					auto nx = px + dx[j];
					auto ny = py + dy[j];

					if (is_inside(nx, ny) && field[ny][nx] == '.')
						cnt++;
				}

				if (cnt < 2)
					q.emplace(px, py);
			}
		}
	}

	for (const auto &row: field)
		cout << row << '\n';
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