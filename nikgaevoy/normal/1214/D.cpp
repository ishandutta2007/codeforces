#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;


int Dijkstra(const vector<string> &field)
{
	deque<tuple<int, int, int>> pq;
	vector<vector<int>> dist(field.size(), vector<int>(field[0].size(), -1));

	auto check = [&](int x, int y) {
		return 0 <= y && y < field.size() && 0 <= x && x < field[y].size() &&
		       (y != 0 || x != 0) && (y + 1 != field.size() || x + 1 != field[0].size());
	};

	auto add = [&](int x, int y, int d = 0) {
		if (check(x, y))
			if (field[y][x] == '#')
				pq.emplace_front(d, x, y);
			else
				pq.emplace_back(d + 1, x, y);
	};

	auto add_free = [&](int x, int y, int d = 0) {
		if (check(x, y))
			pq.emplace_front(d, x, y);
	};

	for (int i = 0; i < field[0].size(); i++)
		add(i, 0);
	for (int i = 0; i < field.size(); i++)
		add(field[0].size() - 1, i);

	int dx[] = {0, -1, -1}, dy[] = {1, 1, 0};
	int dxf[] = {1, 0}, dyf[] = {0, -1};

	while (!pq.empty())
	{
		int d, x, y;

		tie(d, x, y) = pq.front();
		pq.pop_front();

		if (dist[y][x] == -1)
		{
			dist[y][x] = d;

			for (int j = 0; j < 3; j++)
				add(x + dx[j], y + dy[j], d);
			for (int j = 0; j < 2; j++)
				add_free(x + dxf[j], y + dyf[j], d);
		}
	}

	int ans = numeric_limits<int>::max();

	for (int i = 0; i < field[0].size(); i++)
		if (check(i, field.size() - 1))
			ans = min(ans, dist.back()[i]);
	for (int i = 0; i < field.size(); i++)
		if (check(0, i))
			ans = min(ans, dist[i].front());

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<string> field(n);

	for (auto &it : field)
		cin >> it;

	cout << Dijkstra(field) << endl;
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