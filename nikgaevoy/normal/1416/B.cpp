#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> arr(n);

	for (auto &it : arr)
		cin >> it;

	auto mem = arr;

	ll sum = accumulate(arr.begin(), arr.end(), 0ll);

	if (sum % arr.size() != 0)
	{
		cout << -1 << endl;

		return;
	}

	auto dest = sum / arr.size();

	vector<tuple<int, int, int>> op;

	auto make_op = [&](tuple<int, int, int> &q)
	{
		int i, j, x;

		tie(i, j, x) = q;

		assert(0 <= x && x <= 1e9);

		arr[i] -= x * (i + 1);
		assert(arr[i] >= 0);
		arr[j] += x * (i + 1);
	};

	int st = (int) arr.size() - 1;

	while (arr[st] <= st)
		st--;

	op.emplace_back(st, 0, arr[st] / (st + 1));
	make_op(op.back());

	for (int i = 1; i < arr.size(); i++)
		if (arr[i] > 0)
		{
			int add = (i + 1) - (arr[i] % (i + 1));

			if (add != i + 1)
			{
				op.emplace_back(0, i, add);
				make_op(op.back());
			}

			assert(arr[i] % (i + 1) == 0);
			op.emplace_back(i, 0, arr[i] / (i + 1));
			make_op(op.back());
		}

	for (int i = 1; i < arr.size(); i++)
	{
		op.emplace_back(0, i, dest);
		make_op(op.back());
	}

	assert(count(arr.begin(), arr.end(), dest) == arr.size());
	assert(op.size() <= 3 * arr.size());

	swap(arr, mem);

	for (auto it : op)
		make_op(it);

	assert(count(arr.begin(), arr.end(), dest) == arr.size());

	cout << op.size() << endl;

	for (auto it : op)
	{
		int i, j, x;

		tie(i, j, x) = it;
		i++;
		j++;

		cout << i << ' ' << j << ' ' << x << '\n';
	}
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