#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


int get_ans(const array<int, 26> &cnt)
{
	return max(*max_element(cnt.begin(), cnt.end()), accumulate(cnt.begin(), cnt.end(), 1) / 2);
}


vector<pair<int, int>> foo(string str)
{
	array<int, 26> cnt{};

	for (auto &it : str)
		cnt[it - 'a']++;

	vector<pair<int, int>> ans;
	ans.reserve(get_ans(cnt));

	array<array<vector<pair<int, int>>, 26>, 26> prs;

	set<int> alive;

	for (int i = 0; i < str.size(); i++)
		alive.insert(i);

	for (int i = 1; i < str.size(); i++)
		if (str[i - 1] != str[i])
		{
			prs[str[i - 1] - 'a'][str[i] - 'a'].emplace_back(i - 1, i);
			prs[str[i] - 'a'][str[i - 1] - 'a'].emplace_back(i - 1, i);
		}

	int ga;

	while ((ga = get_ans(cnt)) < alive.size())
	{
		auto q = max_element(cnt.begin(), cnt.end()) - cnt.begin();

		for (auto &it : prs[q])
		{
			while (!it.empty() && (str[it.back().first] == ' ' || str[it.back().second] == ' '))
				it.pop_back();

			if (!it.empty())
			{
				cnt[str[it.back().first] - 'a']--;
				cnt[str[it.back().second] - 'a']--;

				if (get_ans(cnt) + 1 == ga)
				{
					alive.erase(it.back().first);
					alive.erase(it.back().second);

					str[it.back().first] = ' ';
					str[it.back().second] = ' ';

					ans.push_back(it.back());
					ans.back().second++;

					auto wh = alive.lower_bound(it.back().first);

					if (wh != alive.begin() && wh != alive.end())
					{
						auto le = wh, ri = wh;
						--le;

						if (str[*le] != str[*ri])
						{
							prs[str[*le] - 'a'][str[*ri] - 'a'].emplace_back(*le, *ri);
							prs[str[*ri] - 'a'][str[*le] - 'a'].emplace_back(*le, *ri);
						}
					}

					break;
				}
				else
				{
					cnt[str[it.back().first] - 'a']++;
					cnt[str[it.back().second] - 'a']++;
				}
			}
		}
	}

	for (int i = 0; i < str.size(); i++)
		if (str[i] != ' ')
		{
			alive.erase(i);
			ans.emplace_back(i, i + 1);
		}

	assert(alive.empty());

	return ans;
}


int up(int n)
{
	int r = 1;

	while (r < n)
		r *= 2;

	return r;
}


class segtree
{
	vector<int> arr;

	[[nodiscard]] int sum(int l, int r, int cl, int cr, int v) const
	{
		if (r <= cl || cr <= l)
			return 0;
		if (l <= cl && cr <= r)
			return arr[v];

		int ct = (cl + cr) / 2;

		return sum(l, r, cl, ct, 2 * v) + sum(l, r, ct, cr, 2 * v + 1);
	}

public:
	segtree(int n) : arr(2 * up(n))
	{}


	void add(int wh, int x)
	{
		for (wh += arr.size() / 2; wh > 0; wh /= 2)
			arr[wh] += x;
	}


	[[nodiscard]] int sum(int l, int r) const
	{
		return sum(l, r, 0, arr.size() / 2, 1);
	}


	[[nodiscard]] int sum(int l = 0) const
	{
		return sum(l, arr.size() / 2, 0, arr.size() / 2, 1);
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	string nw;
	vector<int> pos;

	for (int i = 1; i < str.size(); i++)
		if (str[i - 1] == str[i])
		{
			pos.emplace_back(i);
			nw += str[i];
		}

	auto ans = foo(nw);

	segtree st(str.size());

	for (int i = 0; i < str.size(); i++)
		st.add(i, 1);

	cout << ans.size() + 1 << '\n';

	set<int> alive;

	for (int i = 0; i < str.size(); i++)
		alive.insert(i);

	for (auto it : ans)
	{
		int l = pos[it.first], r = pos[it.second - 1];

		if (l == r)
			l--;

		cout << st.sum(0, l) + 1 << ' ' << st.sum(0, r) << '\n';

		while (true)
		{
			auto wh = alive.lower_bound(l);

			if (wh == alive.end() || *wh >= r)
				break;

			st.add(*wh, -1);
			alive.erase(wh);
		}
	}

	cout << 1 << ' ' << st.sum() << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		solve_test(cin, cout);

#ifdef LOCAL
		cout << flush;
#endif
	}
}


void gen(ostream &cout = std::cout)
{
	const int t = 1;

	cout << t << endl;

	cout << string(int(1e5), 'z') << string(int(1e5), 'y') << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	stringstream ss, out;

	gen(ss);

	solve(ss, out);

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}