#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void bfs(const vector<vector<int>> &gr, vector<int> &dist, int v)
{
	queue<pair<int, int>> pq;
	pq.emplace(0, v);

	while (!pq.empty())
	{
		int d;

		tie(d, v) = pq.front();
		pq.pop();

		if (dist[v] == -1)
		{
			dist[v] = d;

			for (auto it : gr[v])
				pq.emplace(d + 1, it);
		}
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, k;

	cin >> n >> m >> k;

	vector<int> spec(k);

	for (auto &it : spec)
	{
		cin >> it;
		it--;
	}

	sort(spec.begin(), spec.end());

	vector<vector<int>> gr(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	vector<int> dist(n, -1), rdist(n, -1);

	bfs(gr, dist, 0);
	bfs(gr, rdist, n - 1);

	for (auto fr : spec)
		for (auto to : gr[fr])
			if (binary_search(spec.begin(), spec.end(), to))
			{
				cerr << "exists: " << fr << ' ' << to << endl;

				cout << dist.back() << endl;

				return;
			}

	int ans = 0;

	auto ds = spec, rds = spec;

	stable_sort(ds.begin(), ds.end(), [&dist](int a, int b) {
		return dist[a] < dist[b];
	});
	stable_sort(rds.begin(), rds.end(), [&rdist](int a, int b) {
		return rdist[a] > rdist[b];
	});

	if (ds != rds)
	{
		cerr << "found trash" << endl;

		cout << dist.back() << endl;

		return;
	}

	for (int i = 1; i < ds.size(); i++)
	{
		int le = ds[i - 1];
		int ri = ds[i];

		ans = max(ans, 1 + min(dist[le] + rdist[ri], rdist[le] + dist[ri]));
	}

	cout << min(ans, dist.back()) << endl;
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