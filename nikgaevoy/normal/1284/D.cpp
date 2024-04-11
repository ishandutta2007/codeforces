#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ull = unsigned long long;


mt19937 mt(736);


template<class F, class S>
istream &operator>>(istream &cin, pair<F, S> &a)
{
	cin >> a.first >> a.second;

	return cin;
}


vector<ull> hs(vector<pair<int, int>> &arr, const vector<ull> &rnd)
{
	vector<pair<int, int>> l (arr.size()), r(arr.size());
	
	for (int i = 0; i < arr.size (); i++)
	{
		l[i] = {arr[i].first, i};
		r[i] = {arr[i].second, i};
	}
	
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	
	vector<ull> pl(l.size () + 1), pr(r.size () + 1);
	
	for (int i = 1; i < pl.size (); i++)
		pl[i] = pl[i - 1] ^ rnd[l[i - 1].second];
	for (int i = 1; i < pr.size (); i++)
		pr[i] = pr[i - 1] ^ rnd[r[i - 1].second];

	vector<ull> ans(arr.size());

	for (int i = 0; i < arr.size (); i++)
	{
		const auto &it = arr[i];

		auto xl = pl.back() ^ pl[lower_bound(l.begin(), l.end(), pair<int, int>{it.second, 0}) - l.begin()];
		auto xr = pr[lower_bound(r.begin(), r.end(), pair<int, int>{it.first, arr.size()}) - r.begin()];

		ans[i] = xl ^ xr;
	}

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> a(n), b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		a[i].first--;
		b[i].first--;
	}

	vector<ull> rnd(n);
	uniform_int_distribution<ull> uid;

	for (auto &it : rnd)
		it = uid(mt);

	auto ha = hs(a, rnd);
	auto hb = hs(b, rnd);

	cout << (ha == hb ? "YES" : "NO") << endl;
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