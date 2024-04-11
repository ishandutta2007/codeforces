#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, d, m;

	cin >> n >> d >> m;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	sort(arr.begin(), arr.end());

	auto wh = lower_bound(arr.begin(), arr.end(), m + 1) - arr.begin();

	ll ans = accumulate(arr.begin(), arr.begin() + wh, 0ll);

	vector<ll> ps(arr.size() + 1);

	for (int i = 1; i < ps.size(); i++)
		ps[i] = ps[i - 1] + arr[i - 1];

	for (int bans = 1; bans <= arr.size() - wh; bans++)
	{
		ll tmp = ps.back() - ps[arr.size() - bans];

		auto wait = (bans - 1ll) * d + bans;

		if (wait <= arr.size())
		{
			auto add = min((ll)wh, ll(arr.size() - wait));

			tmp += ps[wh] - ps[wh - add];

			ans = max(ans, tmp);
		}
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