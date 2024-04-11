#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n), brr(n);

	for (auto &it: arr)
		cin >> it;
	for (auto &it: brr)
		cin >> it;

	ll sqsum = 0;

	for (auto it: arr)
		sqsum += it * it;
	for (auto it: brr)
		sqsum += it * it;

	auto sum = accumulate(arr.begin(), arr.end(), 0) + accumulate(brr.begin(), brr.end(), 0);

	vector<bool> ss(sum / 2 + 1);
	auto nxt = ss;
	ss.front() = true;

	for (auto i: ranges::iota_view(0, ssize(arr)))
	{
		fill(nxt.begin(), nxt.end(), false);

		for (auto j: ranges::iota_view(0, ssize(ss)))
			if (ss[j])
			{
				if (j + arr[i] < ssize(nxt))
					nxt[j + arr[i]] = true;
				if (j + brr[i] < ssize(nxt))
					nxt[j + brr[i]] = true;
			}

		ss.swap(nxt);
	}

	ll q = ll(ss.size() - 1);

	while (!ss[q])
		q--;

	auto w = sum - q;

	cout << (q * q) + (w * w) + (n - 2) * sqsum << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

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