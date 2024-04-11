#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


int move_edge(const vector<tuple<int, int, int>> &edges, int v, int ind)
{
	return v ^ get<0>(edges[ind]) ^ get<1>(edges[ind]);
}


void cancel_cycles(vector<vector<int>> &gr, const vector<tuple<int, int, int>> &edges,
                   string &ans, function<void(int, int)> orient)
{
	vector<int> used(gr.size());

	auto check_edge = [&](int v, int i)
	{
		if (ans[gr[v][i]] != '0')
		{
			swap(gr[v][i], gr[v].back());
			gr[v].pop_back();

			return true;
		}
		else
			return false;
	};

	function<bool(int, int)> dfs = [&](int v, int prev)
	{
		if (used[v] == 2)
			return false;

		if (used[v] == 1)
		{
			used[v] = 0;

			return true;
		}

		used[v] = 1;

		for (int i = 0; i < ssize(gr[v]); i++)
			if (gr[v][i] != prev)
			{
				if (check_edge(v, i))
				{
					i--;

					continue;
				}

				if (dfs(move_edge(edges, v, gr[v][i]), gr[v][i]))
				{
					orient(gr[v][i], v);

					i--;

					if (used[v] == 1)
					{
						used[v] = 0;

						return true;
					}

					assert(used[v] == 0);

					used[v] = 1;
				}
			}

		used[v] = 2;

		return false;
	};

	for (int v = 0; v < ssize(gr); v++)
		if (!used[v])
			dfs(v, -1);

	for (int v = 0; v < ssize(gr); v++)
		for (int j = 0; j < ssize(gr[v]); j++)
			if (check_edge(v, j))
				j--;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<tuple<int, int, int>> edges(m);

	for (auto &[u, v, w]: edges)
	{
		cin >> u >> v >> w;
		u--;
		v--;
	}

	array<vector<vector<int>>, 2> grs{vector<vector<int>>(n), vector<vector<int>>(n)};

	for (auto it: ranges::iota_view(0, m))
	{
		grs[get<2>(edges[it]) - 1][get<0>(edges[it])].push_back(it);
		grs[get<2>(edges[it]) - 1][get<1>(edges[it])].push_back(it);
	}

	vector<bool> odd(ssize(grs[0])), odd2(ssize(grs[1]));

	for (int v = 0; v < ssize(grs[0]); v++)
	{
		odd[v] = ssize(grs[0][v]) % 2 != 0;
		odd2[v] = ssize(grs[1][v]) % 2 != 0;
	}

	cout << count(odd.begin(), odd.end(), true) << endl;

	string ans(m, '0');

	vector<int> bal(n);

	auto orient = [&ans, &bal, &edges](int ind, int a)
	{
		assert(ans[ind] != '1' && ans[ind] != '2');

		auto[u, v, w] = edges[ind];

		bal[a] -= w;
		bal[move_edge(edges, a, ind)] += w;

		if (a == u)
		{
			ans[ind] = '1';
		}
		else
		{
			assert(a == v);

			ans[ind] = '2';
		}
	};

	cancel_cycles(grs[1], edges, ans, orient);
	cancel_cycles(grs[0], edges, ans, orient);

	assert(count(bal.begin(), bal.end(), 0) == ssize(bal));

	vector<vector<int>> paths;

	function<void(vector<vector<int>> &, int, vector<int> &, vector<bool> &)> get_path =
			[&](vector<vector<int>> &gr, int v, vector<int> &path, vector<bool> &is_odd)
			{
				if (!is_odd[v])
					return;

				for (int j = 0; j < ssize(gr[v]); j++)
				{
					auto to = move_edge(edges, v, gr[v][j]);

					if (ans[gr[v][j]] == '0')
					{
						is_odd[v] = !is_odd[v];
						is_odd[to] = !is_odd[to];

						ans[gr[v][j]] = '?';
						path.push_back(gr[v][j]);

						get_path(gr, to, path, is_odd);

						return;
					}
					else
					{
						swap(gr[v][j], gr[v].back());
						gr[v].pop_back();
						j--;
					}
				}
			};

	auto todd = odd;
	auto todd2 = odd2;

	for (int j = 0; j < ssize(grs[0]); j++)
	{
		vector<int> path;

		if (todd[j])
			get_path(grs[0], j, path, todd);

		if (!path.empty())
		{
			paths.push_back(path);
			path.clear();
		}

		if (todd2[j])
			get_path(grs[1], j, path, todd2);

		if (!path.empty())
			paths.push_back(path);
	}

	assert(find(todd.begin(), todd.end(), true) == todd.end());
	assert(find(todd2.begin(), todd2.end(), true) == todd2.end());

	auto get_path_ends = [&](int ind) -> pair<int, int>
	{
		const auto &path = paths[ind];

		if (ssize(path) == 1)
			return {get<0>(edges[path[0]]), get<1>(edges[path[0]])};

		auto get_oth = [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
		{
			return get<0>(a) == get<0>(b) || get<0>(a) == get<1>(b) ? get<1>(a) : get<0>(a);
		};

		auto a = get_oth(edges[path[0]], edges[path[1]]);
		auto b = get_oth(edges[path.back()], edges[path[ssize(path) - 2]]);

		return {a, b};
	};

	auto color_path = [&](int ind, int from)
	{
		auto &path = paths[ind];

		while (!path.empty())
		{
			auto[a, b] = get_path_ends(ind);

			if (b == from)
			{
				orient(path.back(), from);
				from = move_edge(edges, from, path.back());
			}
			else
			{
				orient(path.back(), move_edge(edges, b, path.back()));
			}

			path.pop_back();
		}
	};

	vector<vector<int>> paths_gr(n);

	for (int j = 0; j < ssize(paths); j++)
	{
		auto[a, b] = get_path_ends(j);

		paths_gr[a].push_back(j);
		paths_gr[b].push_back(j);
	}

	for (auto &row: paths_gr)
		assert(ssize(row) <= 2);

	function<void(vector<vector<int>> &, int)> orient_path = [&](vector<vector<int>> &paths_gr, int v)
	{
		if (paths_gr[v].empty())
			return;

		auto ind = paths_gr[v].front();
		auto[a, b] = get_path_ends(ind);

		color_path(ind, v);

		paths_gr[a].erase(ranges::find(paths_gr[a], ind));
		paths_gr[b].erase(ranges::find(paths_gr[b], ind));

		orient_path(paths_gr, v ^ a ^ b);
	};

	for (int j = 0; j < paths_gr.size(); j++)
		if (ssize(paths_gr[j]) == 1)
			orient_path(paths_gr, j);

	for (int j = 0; j < paths_gr.size(); j++)
	{
		if (auto sz = ssize(paths_gr[j]); sz > 0)
		{
			assert(sz == 2);

			orient_path(paths_gr, j);
		}

		assert(paths_gr[j].empty());
	}

	for (int j = 0; j < edges.size(); j++)
		if (ans[j] != '1' && ans[j] != '2')
		{
			assert(ans[j] == '0');

			auto[a, b, w] = edges[j];

			assert(!(odd[a] && odd[b]));

			if (odd[b])
				swap(a, b);

			if (bal[a] > 0)
				orient(j, a);
			else
				orient(j, b);
		}

	assert(count(ans.begin(), ans.end(), '1') + count(ans.begin(), ans.end(), '2') == ssize(ans));

	for (auto it: bal)
		assert(it % 2 == 0 || abs(it) == 1);

	cout << ans << endl;
}


void gen(ostream &cout = std::cout)
{
	constexpr int n = 10, m = 15;

	cout << n << ' ' << m << endl;

	uniform_int_distribution<int> vert(1, n), w(1, 2);

	for (int j = 0; j < m; j++)
	{
		int a = 0, b = 0;

		while (a == b)
		{
			a = vert(mt);
			b = vert(mt);
		}

		cout << a << ' ' << b << ' ' << w(mt) << endl;
	}
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

	int cnt = 0;

	while (true)
	{
		stringstream ss, out;

		gen(ss);

		solve(ss, out);

		if (++cnt % 100 == 0)
			cout << "ok: " << cnt << endl;
	}

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}