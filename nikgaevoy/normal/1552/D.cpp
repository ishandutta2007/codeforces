#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	sort(arr.begin(), arr.end());

	for (unsigned pos = 0; pos < (1u << arr.size()); pos++)
	{
		for (int neg = ((1u << arr.size()) - 1) & ~pos; neg > 0; neg = ((neg - 1) & ~pos))
		{
			int sum = 0;

			for (int j = 0; j < arr.size(); j++)
			{
				if ((1u << j) & pos)
					sum += arr[j];
				if ((1u << j) & neg)
					sum -= arr[j];
			}

			if (sum == 0)
			{
				cout << "YES" << endl;

//				vector<int> ans = {0};
//
//				for (int i = 0; i < arr.size(); i++)
//					if ((1u << i) & pos)
//						ans.push_back(ans.back() + arr[i]);
//				swap(ans.front(), ans.back());
//				for (int i = 0; i < arr.size(); i++)
//					if ((1u << i) & neg)
//						ans.push_back(ans.back() + arr[i]);
//
//				assert(count(ans.begin(), ans.end(), ans.back()) > 1);
//				ans.pop_back();
//
//				for (int i = 0; i < arr.size(); i++)
//					if (((1u << i) & (neg | pos)) == 0)
//						ans.push_back(arr[i]);
//
//				assert(ans.size() == arr.size());
//
//				sort(ans.begin(), ans.end());
//
//				for (auto it : ans)
//					cerr << it << ' ';
//				cerr << endl;

				return;
			}
		}
	}

	cout << "NO" << endl;
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