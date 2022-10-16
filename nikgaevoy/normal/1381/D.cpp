#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


bool gen_snacc(const vector<vector<int>> &gr, deque<int> &snacc, int v, int b)
{
	if (v == b)
	{
		snacc.push_back(v);

		return true;
	}

	for (auto it : gr[v])
		if (snacc.empty() || it != snacc.back())
		{
			snacc.push_back(v);

			if (gen_snacc(gr, snacc, it, b))
				return true;

			snacc.pop_back();
		}

	return false;
}


int gen_dep(const vector<vector<int>> &gr, vector<int> &dep, int v, int par = -1)
{
	dep[v] = 0;

	for (auto it : gr[v])
		if (it != par)
			dep[v] = max(dep[v], gen_dep(gr, dep, it, v) + 1);

	return dep[v];
}


void gen_dist(const vector<vector<int>> &gr, vector<int> &dist, int v, int par = -1, int val = 0)
{
	dist[v] = val;

	for (auto it : gr[v])
		if (it != par)
			gen_dist(gr, dist, it, v, val + 1);
}


bool on_snacc(deque<int> &snacc, int q)
{
	bool ans = true;

	auto a = snacc.front();
	snacc.pop_front();

	ans &= q != snacc.front();

	snacc.push_front(a);

	return !ans;
}


bool slv(const vector<vector<int>> &gr, const vector<bool> &good, vector<bool> &used,
         deque<int> &snacc, deque<int> &snacc_rev)
{
	assert(snacc.front() == snacc_rev.back());
	assert(snacc.back() == snacc_rev.front());
	assert(snacc.size() == snacc_rev.size());

	if (used[snacc.front()])
		return false;
	if (good[snacc.front()])
		return true;

	used[snacc.front()] = true;

	if (slv(gr, good, used, snacc_rev, snacc))
		return true;

	for (auto it : gr[snacc.front()])
		if (!on_snacc(snacc, it))
		{
			auto b = snacc.back();

			snacc.push_front(it);
			snacc.pop_back();
			snacc_rev.push_back(it);
			snacc_rev.pop_front();

			if (slv(gr, good, used, snacc, snacc_rev))
				return true;

			snacc_rev.push_front(b);
			snacc_rev.pop_back();
			snacc.push_back(b);
			snacc.pop_front();
		}

	return false;
}


void prop_cnt(const vector<vector<int>> &gr, const vector<int> &dep, vector<int> &cnt, int sl,
              int v, int par = -1, int len = 0)
{
	if (len >= sl)
		cnt[v]++;

	pair<int, int> md = {len, -1};

	for (auto it : gr[v])
		if (it != par)
			md = max(md, pair{dep[it] + 1, it});

	for (auto it : gr[v])
		if (it != par && it != md.second)
			prop_cnt(gr, dep, cnt, sl, it, v, md.first + 1);

	if (md.second != -1)
	{
		auto q = md.second;

		md = {len, -1};

		for (auto it : gr[v])
			if (it != par && it != q)
				md = max(md, pair{dep[it] + 1, it});

		prop_cnt(gr, dep, cnt, sl, q, v, md.first + 1);
	}
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, a, b;

	cin >> n >> a >> b;
	a--;
	b--;

	vector<vector<int>> gr(n);

	for (int i = 1; i < n; i++)
	{
		int q, w;

		cin >> q >> w;
		q--;
		w--;

		gr[q].push_back(w);
		gr[w].push_back(q);
	}

	deque<int> snacc;

	gen_snacc(gr, snacc, a, b);

	deque<int> snacc_rev(snacc.rbegin(), snacc.rend());

	vector<bool> used(gr.size()), good(gr.size());

	vector<int> dep(gr.size()), dist(gr.size());

	int st = 0;

	while (gr[st].size() != 1)
		st++;

	gen_dep(gr, dep, st);
	gen_dist(gr, dist, st);

	vector<int> cnt(gr.size());

	for (int i = 0; i < gr.size(); i++)
		for (auto it : gr[i])
			if (dist[it] > dist[i] && dep[it] >= (int) snacc.size() - 2)
				cnt[i]++;

	prop_cnt(gr, dep, cnt, (int)snacc.size() - 1, st);

	for (int i = 0; i < good.size(); i++)
		good[i] = cnt[i] >= 3;

	cout << (slv(gr, good, used, snacc, snacc_rev) ? "YES" : "NO") << endl;
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