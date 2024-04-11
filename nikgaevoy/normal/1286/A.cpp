#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);

template<class T>
T remin(T &x, const T &y)
{
	return x = min(x, y);
}


template<class T>
int foo(T &dp, const vector<int> &arr, int pos, int odd, int even, int last)
{
	if (pos == -1)
		return 0;

	auto &ans = dp[last][pos][odd][even];

	if (ans == -1)
	{
		ans = numeric_limits<int>::max();

		if (arr[pos] == -1)
		{
			if (even > 0)
				remin(ans, foo(dp, arr, pos - 1, odd, even - 1, 0) + (0 + last) % 2);
			if (odd > 0)
				remin(ans, foo(dp, arr, pos - 1, odd - 1, even, 1) + (1 + last) % 2);
		}

		if (arr[pos] != -1)
			remin(ans, foo(dp, arr, pos - 1, odd, even, arr[pos] % 2) + (arr[pos] + last) % 2);
	}

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);
	vector<bool> used(n);

	for (auto &it : arr)
	{
		cin >> it;
		it--;

		if (it != -1)
			used[it] = true;
	}

	int odd = 0, even = 0;

	for (int i = 0; i < n; i++)
		if (!used[i])
			(i % 2 == 0 ? even : odd)++;

	vector<vector<vector<vector<int>>>> dp(2, vector<vector<vector<int>>>(arr.size() + 1, vector<vector<int>>(odd + 1,
	                                                                                                          vector<int>(
			                                                                                                          even +
			                                                                                                          1,
			                                                                                                          -1))));
	auto tmp = dp;

	auto ans = foo(dp, arr, arr.size() - 1, odd, even, 0);

	tmp.swap(dp);
	tmp.clear();

	remin(ans, foo(dp, arr, arr.size() - 1, odd, even, 1));

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