#include <bits/stdc++.h>

using namespace std;

using ll = long long;


template<class T>
T sqr(T x)
{
	return x * x;
}


pair<double, double> U2(const pair<int, int> &a, const pair<int, int> &b)
{
	double q = (a.second - sqr((ll) a.first) - (b.second - sqr((ll) b.first))) / (double) (a.first - b.first);
	double w = a.second - sqr((ll) a.first) - q * a.first;

	return {q, w};
}


bool inside(const pair<int, int> &a, const pair<double, double> &u)
{
	return a.second >= sqr((ll) a.first) + u.first * a.first + u.second;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> arr(n);

	for (auto &it : arr)
	{
		cin >> it.first >> it.second;
		it.second *= -1;
	}

	sort(arr.begin(), arr.end());

	arr.resize(unique(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
		return a.first == b.first;
	}) - arr.begin());

	for (auto &it : arr)
		it.second *= -1;

#ifdef LOCAL
	for (auto it : arr)
		cout << it.first << ' ' << it.second << endl;
	cout << endl;
#endif

	vector<pair<int, int>> ans;

	for (auto it : arr)
	{
		while (ans.size() >= 2 && inside(ans[ans.size() - 2], U2(ans.back(), it)))
			ans.pop_back();

		ans.push_back(it);
	}

	cout << ans.size() - 1 << endl;

#ifdef LOCAL
	for (auto it : ans)
		cout << it.first << ' ' << it.second << endl;
	cout << endl;
#endif
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}