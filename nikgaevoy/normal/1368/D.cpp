#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ull = unsigned long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<unsigned> arr(n);
	array<int, 20> cnt{};

	for (auto &it : arr)
	{
		cin >> it;

		for (unsigned i = 0; i < 20; i++)
			if (it & (1u << i))
				cnt[i]++;
	}

	vector<ull> ans(n);

	for (unsigned i = 0; i < 20; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
			ans[j] |= 1u << i;
	}

	ull sum = 0;

	for (auto it : ans)
		sum += it * it;

	cout << sum << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}