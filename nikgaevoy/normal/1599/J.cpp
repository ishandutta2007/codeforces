#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr string_view yes = "YES", no = "NO";


namespace std
{
	template<>
	struct hash<pair<int, int>>
	{
		std::size_t operator()(pair<int, int> const &s) const noexcept
		{
			return std::hash<ll>{}(s.first * ll(1ull << 32u) + s.second);
		}
	};
}

auto gen_half(const vector<int> &arr, int l, int r)
{
	vector<pair<pair<int, int>, unsigned>> ans;

	auto n = r - l;
	unsigned bnd = 1;

	for (int j = 0; j < n; j++)
		bnd *= 3;

	int sum = 0, bal = 0;

	ans.reserve(bnd);
	ans.emplace_back();

	for (unsigned mask = 1; mask < bnd; mask++)
	{
		for (int q = 1, pos = l; q < bnd; q *= 3, pos++)
		{
			if (auto rem = mask / q % 3; rem == 0)
			{
				bal++;
				sum += arr[pos];
			}
			else if (rem == 1)
			{
				bal++;
				sum += arr[pos];

				break;
			}
			else if (rem == 2)
			{
				bal -= 2;
				sum -= 2 * arr[pos];

				break;
			}
		}

		ans.emplace_back(pair{bal, sum}, mask);
	}

	return ans;
}


vector<int> solve_odd(const vector<int> &arr)
{
	auto st = clock();

	auto le = gen_half(arr, 0, arr.size() / 2);
	auto ri = gen_half(arr, arr.size() / 2, arr.size());

	sort(ri.begin(),  ri.end());

	cerr << (clock() - st) / (double) CLOCKS_PER_SEC << endl;

	for (const auto &[ind, mask]: le)
	{
		auto[bal, sum] = ind;

		auto wh = lower_bound(ri.begin(), ri.end(), pair{pair{-bal, -sum}, 0u});

		if (wh != ri.end() && (wh + 1) != ri.end() && (wh + 1)->first == wh->first)
			++wh;

		if (wh != ri.end() && wh->first == pair{-bal, -sum} && (mask != 0 || wh->second != 0))
		{
			vector<int> pos, neg, neu;

			ull tot = wh->second;

			for (int j = 0; j < arr.size() / 2; j++)
				tot *= 3;
			tot += mask;

			for (ull q = 1, i = 0; i < arr.size(); q *= 3, i++)
			{
				switch (tot / q % 3)
				{
					case 0:
						neu.push_back(arr[i]);
						break;
					case 1:
						pos.push_back(arr[i]);
						break;
					case 2:
						neg.push_back(arr[i]);
						break;
				}
			}

			assert(!pos.empty() && !neg.empty());
			assert(pos.size() == neg.size());
			assert(pos.size() + neg.size() + neu.size() == arr.size());
			assert(accumulate(pos.begin(), pos.end(), 0) == accumulate(neg.begin(), neg.end(), 0));

			vector<int> ans = {0}, cycle;

			for (int i = 0; i < pos.size(); i++)
			{
				cycle.push_back(pos[i]);
				cycle.push_back(neg[i]);
			}

			for (int j = 0; j + 1 < cycle.size(); j++)
				ans.push_back(cycle[j] - ans[j]);
			assert(ans.front() + ans.back() == cycle.back());

			for (auto it: neu)
				ans.push_back(it - ans.front());

			return ans;
		}
	}

	return {};
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	sort(arr.begin(), arr.end());

	for (int i = 1; i < arr.size(); i++)
		if (arr[i] == arr[i - 1])
		{
			cout << yes << endl;

			cout << 0;

			for (int j = 0; j < arr.size(); j++)
				if (i != j)
					cout << ' ' << arr[j];
			cout << endl;

			return;
		}

	array<vector<int>, 2> m2{};

	for (auto it: arr)
		m2[it % 2].push_back(it);

	vector<int> q;

	if (m2[0].empty())
	{
		vector<int> st(arr.begin(), arr.begin() + min(26, (int) arr.size()));

		auto tst = clock();
		auto ans = solve_odd(st);
		cerr << (clock() - tst) / (double) CLOCKS_PER_SEC << endl;

		if (ans.empty())
		{
			cout << no << endl;

			return;
		}

		for (auto j = st.size(); j < arr.size(); j++)
			ans.push_back(arr[j] - ans.front());

		cout << yes << endl;

		for (auto it: ans)
			cout << it << ' ';
		cout << endl;

		return;
	}

	if (m2[0].size() >= 3)
	{
		q = vector(m2[0].begin(), m2[0].begin() + 3);
	}
	else if (m2[0].size() >= 1 && m2[1].size() >= 2)
	{
		q = vector(m2[1].begin(), m2[1].begin() + 2);
		q.push_back(m2[0].front());
	}

	if (q.empty())
	{
		cout << no << endl;

		return;
	}

	auto x = (q[0] + q[1] - q[2]) / 2;

	assert((q[0] - x) + (q[1] - x) == q[2]);

	cout << yes << endl;
	cout << x;

	for (auto it: arr)
		if (it != q[2])
			cout << ' ' << it - x;
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