#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> a(n), b(n);

	for (auto &it : a)
		cin >> it;
	for (auto &it : b)
		cin >> it;

	map<ll, ll> ans, cnt;

	for (int i = 0; i < n; i++)
		cnt[a[i]]++;

	ll ret = 0;

	for (int i = 0; i < n; i++)
		for (auto it : cnt)
			if ((it.first & a[i]) == a[i] && it.second > 1)
			{
				ret += b[i];

				break;
			}

	cout << ret << endl;
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