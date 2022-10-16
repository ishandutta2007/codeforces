#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	ssize_t n;

	cin >> n;

	vector<int> arr(n), brr(n);

	for (auto &it: arr)
		cin >> it;
	for (auto &it: brr)
		cin >> it;

	if (arr.front() != brr.front() || arr.back() != brr.back())
	{
		cout << "NO" << endl;

		return;
	}

	vector<pair<int, int>> ans;

	auto op = [&ans, &arr](int l, int r)
	{
		assert(0 <= l && l < r && r <= ssize(arr));
		assert(arr[l] == arr[r - 1]);
		ans.emplace_back(l, r);
		reverse(arr.begin() + l, arr.begin() + r);
	};

	for (int i = 0; i + 1 < arr.size(); i++)
	{
		assert(arr[i] == brr[i]);

		auto find_rev = [&]()
		{
			for (int j = i + 1; j + 1 < arr.size(); j++)
				if (arr[j] == brr[i + 1] && arr[j + 1] == brr[i])
				{
					op(i, j + 2);

					return true;
				}

			return false;
		};

		if (arr[i + 1] != brr[i + 1])
			find_rev();

		if (arr[i + 1] != brr[i + 1])
		{
			unordered_map<int, int> le;

			for (int j = i + 1; j + 1 < arr.size(); j++)
			{
				le[arr[j]] = j;

				if (arr[j] == brr[i] && arr[j + 1] == brr[i + 1])
				{
					for (int k = j + 1; k < arr.size(); k++)
						if (le.contains(arr[k]))
						{
							op(le.at(arr[k]), k + 1);

							find_rev();

							break;
						}

					break;
				}
			}
		}

		if (arr[i + 1] != brr[i + 1])
		{
			cout << "NO" << endl;

			return;
		}
	}

	assert(arr == brr);

	cout << "YES" << endl;

	cout << ans.size() << endl;

	for (auto [l, r]: ans)
		cout << l + 1 << ' ' << r << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto i: ranges::iota_view(0, t))
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