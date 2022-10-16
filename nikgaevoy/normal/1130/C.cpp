#include <bits/stdc++.h>

using namespace std;

using ll = long long;


template<class T>
T sqr(T x)
{
	return x * x;
}


void bfs(const vector<string> &field, vector<vector<int>> &dist, int x, int y)
{
	queue<pair<int, pair<int, int>>> q;
	q.emplace(0, pair<int, int>{x, y});

	while (!q.empty())
	{
		auto t = q.front();
		q.pop();

		int d = t.first;
		x = t.second.first;
		y = t.second.second;

		if (field[y][x] == '0' && dist[y][x] == -1)
		{
			dist[y][x] = d;

			static int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

			for (int i = 0; i < 4; i++)
				if (0 <= y + dy[i] && y + dy[i] < dist.size() &&
				    0 <= x + dx[i] && x + dx[i] < dist[y + dy[i]].size())
					q.emplace(d + 1, pair<int, int>(x + dx[i], y + dy[i]));
		}
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	int r0, c0, r1, c1;

	cin >> r0 >> c0 >> r1 >> c1;
	r0--;
	c0--;
	r1--;
	c1--;

	vector<string> field(n);

	for (auto &row : field)
		cin >> row;

	vector<vector<int>> dist(n, vector<int>(n, -1)), tsid(n, vector<int>(n, -1));

	bfs(field, dist, c0, r0);
	bfs(field, tsid, c1, r1);

	int best = numeric_limits<int>::max();

	for (int x0 = 0; x0 < n; x0++)
		for (int y0 = 0; y0 < n; y0++)
			for (int x1 = 0; x1 < n; x1++)
				for (int y1 = 0; y1 < n; y1++)
					if (dist[y0][x0] != -1 && tsid[y1][x1] != -1)
						best = min(best, sqr(x0 - x1) + sqr(y0 - y1));

	cout << best << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}