#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


ll cuts(const vector<int> &arr, int x)
{
	ll ans = 0;

	for (auto it : arr)
		ans += (it + x - 1) / x;

	return ans;
}


template<class T>
auto sqr(T x)
{
	return x * x;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	vector<int> cnt(n);

	priority_queue<pair<ll, int>> pq;

	auto get_cur = [&](int q) -> ll
	{
		int b = arr[q] / (cnt[q] + 1);
		int add = arr[q] % (cnt[q] + 1);

		return sqr((ll) b) * (cnt[q] + 1 - add) + sqr(b + 1ll) * add;
	};

	auto get_diff = [&](int q)
	{
		cnt[q]++;
		auto nxt = get_cur(q);
		cnt[q]--;
		return get_cur(q) - nxt;
	};

	for (int i = 0; i < arr.size(); i++)
		pq.emplace(get_diff(i), i);

	for (int i = n; i < k; i++)
	{
		auto x = pq.top().second;
		pq.pop();
		cnt[x]++;
		pq.emplace(get_diff(x), x);
	}

	assert(accumulate(cnt.begin(), cnt.end(), n) == k);

	ll ans = 0;

	for (int i = 0; i < arr.size(); i++)
		ans += get_cur(i);

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