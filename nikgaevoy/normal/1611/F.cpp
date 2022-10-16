#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
class sparse_table
{
	vector<vector<T>> arr;

public:
	template<class It>
	sparse_table(It be, It en) : arr(1, vector(be, en))
	{
		while (((size_t) 1u << arr.size()) <= arr.front().size())
		{
			auto sz = (size_t) 1u << arr.size();
			arr.emplace_back(arr.front().size() - sz + 1);

			for (size_t j = 0; j < arr.back().size(); j++)
				arr.back()[j] = min(arr[arr.size() - 2][j], arr[arr.size() - 2][j + sz / 2]);
		}
	}

	T operator()(size_t l, size_t r) const
	{
		if (r < l)
			return numeric_limits<T>::max();
		size_t ind = 0;

		while (((size_t) 2u << ind) <= r - l)
			ind++;

		return min(arr[ind].at(l), arr[ind].at(r - ((size_t) 1u << ind)));
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, s;

	cin >> n >> s;

	vector<ll> arr(n), ps(n + 1);

	for (auto &it: arr)
		cin >> it;

	partial_sum(arr.begin(), arr.end(), ps.begin() + 1);

	sparse_table<ll> st(ps.begin(), ps.end());

	size_t ans = 0;
	size_t bl = -1, br = -1;

	for (size_t j = 0; j < arr.size(); j++)
	{
		size_t l = j, r = ps.size() + 1;

		while (l + 1 < r)
		{
			auto t = midpoint(l, r);

			if (st(j, t) < ps[j] - s)
				r = t;
			else
				l = t;
		}

		if (l - j > ans)
		{
			ans = l - j;
			bl = j;
			br = l;
		}
	}

	if (ans > 1)
		cout << bl + 1 << ' ' << br - 1 << endl;
	else
		cout << -1 << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
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