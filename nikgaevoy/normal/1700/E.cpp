#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr array dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	auto matr = vector(n, vector<int>(m));

	for (auto &row: matr)
		for (auto &it: row)
		{
			cin >> it;
			it--;
		}

	auto is_inside = [&matr](int x, int y)
	{
		return 0 <= y && y < ssize(matr) &&
		       0 <= x && x < ssize(matr[y]);
	};

	auto is_bad = [&matr, &is_inside](int x, int y)
	{
		if (!is_inside(x, y) || matr[y][x] == 0)
			return false;

		for (int i = 0; i < 4; i++)
		{
			auto nx = x + dx[i];
			auto ny = y + dy[i];

			if (is_inside(nx, ny) && matr[ny][nx] < matr[y][x])
				return false;
		}

		return true;
	};

	vector<pair<int, int>> bad;

	for (int y = 0; y < ssize(matr); y++)
		for (int x = 0; x < ssize(matr[y]); x++)
			if (is_bad(x, y))
				bad.emplace_back(x, y);

	if (bad.empty())
	{
		cout << 0 << endl;

		return;
	}

	if (bad.size() > 5)
	{
		cout << 2 << endl;

		return;
	}

	auto cand = bad;

	for (auto [x, y]: bad)
		for (int i = 0; i < 4; i++)
		{
			auto nx = x + dx[i];
			auto ny = y + dy[i];

			if (is_inside(nx, ny))
				cand.emplace_back(nx, ny);
		}

	ranges::sort(cand);
	cand.resize(cand.size() - size(ranges::unique(cand)));

	int cnt = 0;

	for (auto [fx, fy]: cand)
	{
		for (int sy = 0; sy < ssize(matr); sy++)
			for (int sx = 0; sx < ssize(matr[sy]); sx++)
				if (!ranges::binary_search(cand, pair{sx, sy}) || matr[sy][sx] < matr[fy][fx])
				{
					swap(matr[sy][sx], matr[fy][fx]);

					bool ok = !is_bad(fx, fy) && !is_bad(sx, sy);

					for (auto [x, y]: bad)
						ok &= !is_bad(x, y);

					for (int i = 0; i < 4; i++)
						ok &= !is_bad(fx + dx[i], fy + dy[i]) && !is_bad(sx + dx[i], sy + dy[i]);

					if (ok)
						cnt++;

					swap(matr[sy][sx], matr[fy][fx]);
				}
	}

	if (cnt > 0)
		cout << "1 " << cnt << endl;
	else
		cout << 2 << endl;
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