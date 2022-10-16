#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
T &remax(T &x, const T &y)
{
	return x = max(x, y);
}


template<template<class, class...> class T, class U, class ...V>
istream &operator>>(istream &cin, T<U, V...> &arr)
{
	copy_n(istream_iterator<U>(cin), size(arr), begin(arr));

	return cin;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<unsigned> arr(n);

	cin >> arr;

	vector<pair<int, int>> vert;
	vector<vector<int>> gr;
	vector<int> ind;
	unordered_map<unsigned, int> mp;

	auto nxt = [](unsigned val)
	{
		return (val & (val - 1u)) == 0 ? 0 : (1u << (32 - __builtin_clz(val))) - val;
	};

	for (auto it: ranges::iota_view(0, ssize(arr)))
	{
		auto val = arr[it];

		pair<int, int> cur = {0, it};

		auto add = [&](int prev = -1)
		{
			if (!mp.contains(val))
			{
				mp[val] = vert.size();
				vert.emplace_back();
				gr.emplace_back();
				ind.push_back(-1);
			}

			remax(vert[mp[val]], cur);

			if (prev != -1)
				gr[mp[val]].push_back(prev);
		};

		add();
		ind[mp[val]] = it;

		while (val != 0)
		{
			auto p = val;

			val = nxt(val);
			cur.first++;

			add(mp[p]);
		}
	}

	int best = -1;
	int x = -1, y = -1;

	for (auto i: ranges::iota_view(0, ssize(gr)))
	{
		auto &it = gr[i];

		ranges::sort(it, [&](int a, int b)
		{
			return vert[a] > vert[b];
		});
		it.erase(unique(it.begin(), it.end()), it.end());

		if (it.size() > 1 && (vert[it[0]].first + 1 + vert[it[1]].first + 1 > best))
		{
			best = vert[it[0]].first + 1 + vert[it[1]].first + 1;
			x = vert[it[0]].second;
			y = vert[it[1]].second;
		}
		else if (it.size() == 1 && ind[i] != -1 && vert[it[0]].first + 1 > best)
		{
			best = vert[it[0]].first + 1;
			x = vert[it[0]].second;
			y = ind[i];
		}
	}

	cout << x + 1 << ' ' << y + 1 << ' ' << best << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
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