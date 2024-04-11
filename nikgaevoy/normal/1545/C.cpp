#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


const int mod = 998244353;


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> lines(2 * n, vector<int>(n));

	for (auto &row : lines)
		for (auto &it : row)
		{
			cin >> it;
			it--;
		}

	vector<vector<bool>> check(lines.size(), vector<bool>(lines.size()));

	for (int i = 0; i < lines.size(); i++)
		for (int j = 0; j < i; j++)
			for (int k = 0; k < lines[i].size(); k++)
				if (lines[i][k] == lines[j][k])
				{
					check[i][j] = check[j][i] = true;

					break;
				}

	int cnt = 1;
	vector<int> ans;
	ans.reserve(lines.size() / 2);

	auto cnts = vector(n, vector<vector<int>>(n));

	for (int col = 0; col < n; col++)
		for (int row = 0; row < lines.size(); row++)
			cnts[col][lines[row][col]].push_back(row);

	auto alive = vector(n, vector<int>(n));

	queue<int> uni;

	for (int col = 0; col < n; col++)
		for (int val = 0; val < n; val++)
		{
			alive[col][val] = (int) cnts[col][val].size();

			if (alive[col][val] == 1)
				uni.push(cnts[col][val].front());
		}

	vector<bool> good(lines.size(), true);

	auto kill = [&lines, &alive, &cnts, &good, &uni](int row, bool garbage = true)
	{
		if (!good[row])
			return;

		good[row] = false;

		for (int col = 0; col < lines[row].size(); col++)
			if (garbage && --alive[col][lines[row][col]] == 1)
			{
				for (auto it : cnts[col][lines[row][col]])
					if (good[it])
						uni.push(it);
			}
	};

	while (!uni.empty())
	{
		auto v = uni.front();
		uni.pop();

		if (good[v])
		{
			kill(v, false);
			ans.push_back(v);

			for (int i = 0; i < check[v].size(); i++)
				if (check[v][i])
					kill(i);
		}
	}

	function<void(int, int)> dfs = [&check, &ans, &good, &dfs](int v, bool garbage)
	{
		if (!good[v])
			return;
		good[v] = false;

		if (!garbage)
			ans.push_back(v);

		for (int i = 0; i < check[v].size(); i++)
			if (check[v][i])
				dfs(i, !garbage);
	};

	for (int i = 0; i < good.size(); i++)
		if (good[i])
		{
			cnt *= 2;
			cnt %= mod;

			dfs(i, false);
		}

	assert(2 * ans.size() == lines.size());

	sort(ans.begin(), ans.end());

	cout << cnt << endl;
	for (auto it : ans)
		cout << it + 1 << ' ';
	cout << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

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