#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


ll cnt(const vector<bool> &arr)
{
	int ones = 0;
	ll ans = 0;

	for (auto it : arr)
		if (it)
			ones++;
		else
			ans += ones;

	return ans;
}


void slv(const vector<unsigned> &arr, vector<pair<ll, ll>> &q, int bit)
{
	if (bit < 0 || arr.size() < 2)
		return;

	auto x = 1u << (unsigned) bit;

	vector<bool> tmp(arr.size()), ntmp(arr.size());

	for (int j = 0; j < tmp.size(); j++)
		ntmp[j] = !(tmp[j] = (arr[j] & x) > 0);

	q[bit].first += cnt(tmp);
	q[bit].second += cnt(ntmp);

	vector<unsigned> ze, on;

	for (auto it : arr)
		(it & x ? on : ze).push_back(it);

	slv(ze, q, bit - 1);
	slv(on, q, bit - 1);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<unsigned> arr(n);

	for (auto &it : arr)
		cin >> it;

	vector<pair<ll, ll>> q(31);

	slv(arr, q, (int)q.size() - 1);

	ll ans = 0;
	unsigned x = 0;

	for (unsigned i = 0; i < q.size(); i++)
	{
		if (q[i].second < q[i].first)
		{
			x |= (1u << i);
		}

		ans += min(q[i].first, q[i].second);
	}

	cout << ans << ' ' << x << endl;
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