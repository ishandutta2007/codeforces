#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	map<int, int> ord;
	vector<int> perm(n);

	for (int i = 0; i < n; i++)
	{
		int a;

		cin >> a;

		ord[a] = i;
	}

	for (auto &it : perm)
	{
		cin >> it;
		it = ord[it];
	}

	vector<bool> pref(n + 1);

	int mex = 0, ans = 0;

	for (auto it : perm)
	{
		if (mex < it)
			ans++;
		pref[it] = true;

		while (pref[mex])
			mex++;
	}

	cout << ans << endl;
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