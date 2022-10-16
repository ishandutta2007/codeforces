#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void dfs(const vector<vector<int>> &gr, vector<bool> &used, int v)
{
	if (used[v])
		return;
	used[v] = true;

	for (auto it : gr[v])
		dfs(gr, used, it);
}


bool check(const vector<pair<unsigned, unsigned>> &edges, unsigned ans)
{
	vector<vector<int>> gr(1u << ans);

	for (auto it : edges)
	{
		it.first &= (1u << ans) - 1;
		it.second &= (1u << ans) - 1;

		gr[it.first].push_back(it.second);
		gr[it.second].push_back(it.first);
	}

	int st = 0;

	while (gr[st].empty())
		st++;

	vector<bool> used(gr.size());

	dfs(gr, used, st);

	for (int i = 0; i < gr.size(); i++)
		if (!gr[i].empty() && (gr[i].size() % 2 == 1 || !used[i]))
			return false;

	return true;
}


void dfs(unordered_map<unsigned, set<pair<unsigned, pair<int, int>>>> &gr, vector<pair<int, int>> &ord, int v)
{
	while (!gr[v].empty())
	{
		auto q = *gr[v].begin();
		gr[v].erase(q);
		gr[q.first].erase(pair{v, pair{q.second.second, q.second.first}});
		dfs(gr, ord, q.first);
		ord.emplace_back(q.second.second, q.second.first);
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<unsigned, unsigned >> edges(n);

	for (auto &it : edges)
		cin >> it.first >> it.second;

	unsigned ans = 20;

	while (!check(edges, ans))
		ans--;

	cout << ans << endl;

	unordered_map<unsigned, set<pair<unsigned, pair<int, int>>>> gr;

	for (int i = 0; i < edges.size(); i++)
	{
		auto it = edges[i];

		it.first &= (1u << ans) - 1;
		it.second &= (1u << ans) - 1;

		gr[it.first].emplace(it.second, pair{2 * i, 2 * i + 1});
		gr[it.second].emplace(it.first, pair{2 * i + 1, 2 * i});
	}

	vector<pair<int, int>> ord;
	ord.reserve(n);

	dfs(gr, ord, gr.begin()->first);

	assert(ord.size() == edges.size());

	vector<unsigned> xx;

	for (auto it : edges)
	{
		xx.push_back(it.first);
		xx.push_back(it.second);
	}

	for (int i = 0; i < ord.size(); i++)
		assert(((xx[ord[i].second] ^ xx[ord[(i + 1) % ord.size()].first]) & ((1u << ans) - 1)) == 0);

	for (auto it : ord)
		cout << it.first + 1 << ' ' << it.second + 1 << ' ';
	cout << endl;
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