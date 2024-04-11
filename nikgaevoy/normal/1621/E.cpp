#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


class sparse_table
{
	vector<vector<bool>> mem;

public:
	explicit sparse_table(const vector<bool> &arr) : mem(1, arr)
	{
		while (1u << mem.size() < mem.front().size())
		{
			auto sz = 1u << mem.size();
			mem.emplace_back();
			const auto &prev = mem[mem.size() - 2];

			for (int j = 0; j + sz <= mem.front().size(); j++)
				mem.back().push_back(prev[j] & prev[j + sz / 2]);
		}
	}


	bool operator()(int l, int r) const
	{
		if (r <= l)
			return true;

		int lvl = 0;

		while (l + (1u << lvl) <= r)
			lvl++;
		lvl--;

		mem.at(lvl);

		return mem[lvl].at(l) & mem[lvl].at(r - (1u << lvl));
	}


	bool operator()(int l = 0) const
	{
		return (*this)(l, mem.front().size());
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	sort(arr.begin(), arr.end(), greater());
	arr.resize(m);

	vector<vector<int>> groups(m);

	for (auto &row: groups)
	{
		int k;

		cin >> k;

		row.resize(k);

		for (auto &it: row)
			cin >> it;
	}

	vector<pair<ll, ll>> basic(groups.size());

	for (int j = 0; j < basic.size(); j++)
		basic[j] = {accumulate(groups[j].begin(), groups[j].end(), 0ll), ssize(groups[j])};

	auto cmp = [](const auto &a, const auto &b)
	{
		return a.first * (ll) b.second > a.second * (ll) b.first;
	};

	sort(basic.begin(), basic.end(), cmp);

	array<vector<bool>, 3> edges;

	for (int j = -1; j <= 1; j++)
	{
		auto &row = edges[j + 1];

		row.resize(arr.size());

		for (int i = 0; i < row.size(); i++)
			row[i] = 0 <= i + j && i + j < basic.size() && basic[i + j].first <= basic[i + j].second * (ll) arr[i];
	}

	array<sparse_table, 3> sts{sparse_table(edges[0]), sparse_table(edges[1]), sparse_table(edges[2])};

	string ans;

	for (const auto &row: groups)
	{
		ll acc = accumulate(row.begin(), row.end(), 0ll);
		ll cnt = ssize(row);

		auto pos = lower_bound(basic.begin(), basic.end(), pair{acc, cnt}, cmp) - basic.begin();

		auto check = [&](int it) -> bool
		{
			auto nacc = acc - it;
			auto ncnt = cnt - 1;
			auto npos = lower_bound(basic.begin(), basic.end(), pair{nacc, ncnt}, cmp) - basic.begin();

			if (npos > pos)
				npos--;

			if (nacc > ncnt * arr[npos])
				return false;

			if (pos == npos)
				return sts[1](0, pos) && sts[1](pos + 1);
			if (npos > pos)
				return sts[1](0, pos) && sts[2](pos, npos) && sts[1](npos + 1);
			assert(npos < pos);
			return sts[1](0, npos) && sts[0](npos + 1, pos + 1) && sts[1](pos + 1);
		};

		for (auto it: row)
			if (check(it))
				ans += '1';
			else
				ans += '0';
	}

	cout << ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
		solve_test(cin, cout);
}


void stress_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	sort(arr.begin(), arr.end(), greater());
	arr.resize(m);

	vector<vector<int>> groups(m);

	for (auto &row: groups)
	{
		int k;

		cin >> k;

		row.resize(k);

		for (auto &it: row)
			cin >> it;
	}

	string ans;

	vector<pair<ll, ll>> basic(groups.size());

	for (int j = 0; j < basic.size(); j++)
		basic[j] = {accumulate(groups[j].begin(), groups[j].end(), 0ll), ssize(groups[j])};

	for (int j = 0; j < groups.size(); j++)
	{
		for (int i = 0; i < groups[j].size(); i++)
		{
			auto tmp = basic;

			tmp[j].first -= groups[j][i];
			tmp[j].second--;

			sort(tmp.begin(), tmp.end(), [](auto a, auto b)
			{
				return a.first * b.second > b.first * a.second;
			});

			bool ok = true;

			for (int q = 0; ok && q < tmp.size(); q++)
				if (arr[q] * tmp[q].second < tmp[q].first)
					ok = false;

			ans += (ok ? '1' : '0');
		}
	}

	cout << ans << endl;
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
		stress_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	int t = 1;

	cout << t << endl;

	uniform_int_distribution<int> uid(1, 10);

	for (int test = 0; test < t; test++)
	{
		const int n = 15, m = 10;

		cout << n << ' ' << m << endl;

		for (int j = 0; j < n; j++)
			cout << uid(mt) << ' ';
		cout << endl;

		for (int j = 0; j < m; j++)
		{
			auto k = max(2, uid(mt));

			cout << k << endl;

			for (int q = 0; q < k; q++)
				cout << uid(mt) << ' ';
			cout << endl;
		}
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
		stringstream ss, in1, in2, out1, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail: " << cnt << endl;

			cout << ss.str() << endl;
			cout << "solve:" << endl;
			cout << out1.str() << endl;
			cout << "stress:" << endl;
			cout << out2.str() << endl;

			break;
		}
		else if (++cnt % 100 == 0)
			cout << "ok: " << cnt << endl;
	}

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}