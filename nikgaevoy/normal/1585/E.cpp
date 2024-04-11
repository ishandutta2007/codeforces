#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


class srt
{
	vector<int> ord, wh, cnt, split;

	void swap_elements(int a, int b)
	{
		swap(ord[wh[a]], ord[wh[b]]);
		swap(wh[a], wh[b]);
	}

public:
	explicit srt(int n = 0) : ord(n), wh(n), cnt(n), split(n + 1, n)
	{
		iota(ord.begin(), ord.end(), 0);
		iota(wh.begin(), wh.end(), 0);
		split.front() = 0;
	}

	void inc(int val)
	{
		auto to = ord[split[cnt[val] + 1] - 1];

		swap_elements(val, to);

		split[cnt[val] + 1]--;
		cnt[val]++;
	}

	void dec(int val)
	{
		auto to = ord[split[cnt[val]]];

		swap_elements(val, to);

		split[cnt[val]]++;
		cnt[val]--;
	}

	int operator()(int l, int k) const noexcept
	{
		auto st = split[l];

		if (st + k >= ssize(ord))
			return -1;
		return ord[st + k];
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;

	cin >> n >> q;

	vector<int> arr(n);

	copy_n(istream_iterator<decltype(arr)::value_type>(cin), arr.size(), arr.begin());

	vector<vector<int>> gr(n);

	for (auto v: ranges::iota_view(1, n))
	{
		int p;

		cin >> p;
		p--;

		gr[p].push_back(v);
	}

	vector<int> ans(q, -2);
	vector<vector<tuple<int, int, int>>> quer(n);

	for (auto ind: ranges::iota_view(0, q))
	{
		int v, l, k;

		cin >> v >> l >> k;
		v--;
		k--;

		quer[v].emplace_back(ind, l, k);
	}

	{
		vector<int> cnt(n + 1);
		map<int, int> cnt_cnt;
		vector<set<int>> trans(n + 1);

		for (auto it: ranges::iota_view(0, n))
			trans.front().insert(it);

		auto inc = [&](int val)
		{
			auto &it = cnt[val];

			trans[it].erase(val);

			if (it > 0 && --cnt_cnt[it] == 0)
				cnt_cnt.erase(it);

			cnt_cnt[++it]++;

			trans[it].insert(val);
		};

		auto dec = [&](int val)
		{
			auto &it = cnt[val];

			trans[it].erase(val);

			if (--cnt_cnt[it] == 0)
				cnt_cnt.erase(it);

			if (--it > 0)
				cnt_cnt[it]++;

			trans[it].insert(val);
		};

		srt slv(n + 1);

		function<void(int)> foo = [&](int v)
		{
			slv.inc(arr[v]);

			for (auto it: gr[v])
				foo(it);

			for (const auto &[ind, l, k]: quer[v])
				ans[ind] = slv(l, k);

			slv.dec(arr[v]);
		};

		foo(0);
	}

	assert(ranges::count(ans, -2) == 0);

	ranges::copy(ans, ostream_iterator<decltype(ans)::value_type>(cout, " "));
	cout << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	constexpr int t = 1, n = 1e6, q = 1e6;

	uniform_int_distribution<int> uid(1, n);

	cout << t << endl;

	for (auto test: ranges::iota_view(0, t))
	{
		cout << n << ' ' << q << endl;

		for (auto it: ranges::iota_view(0, n))
			cout << uid(mt) << ' ';
		cout << endl;

		for (auto v: ranges::iota_view(1, n))
			cout << uniform_int_distribution<int>{1, v}(mt) << ' ';
		cout << endl;

		for (auto it: ranges::iota_view(0, q))
		{
			for (auto i: ranges::iota_view(0, 3))
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

//	for (auto cnt: ranges::iota_view(0))
	if (false)
	{
		stringstream ss, out;

		gen(ss);

		solve(ss, out);
	}

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}