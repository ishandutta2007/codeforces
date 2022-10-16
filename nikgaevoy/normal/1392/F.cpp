#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> arr(n);

	for (auto &it : arr)
		cin >> it;

	ll last = arr.front();

	stack<int> zeros;
	int sz = 0;

	for (int last_empty = -1, i = 1; i < arr.size(); i++)
	{
		auto it = arr[i];

		while (it > last + 1)
		{
			if (!zeros.empty())
			{
				auto wh = zeros.top();
				zeros.pop();

				auto add = min((ll) sz - wh, it - (last + 1));

				wh += add;
				it -= add;

				if (wh == sz)
					last++;
				else
					zeros.push(wh);
			}
			else
			{
				assert(last_empty != i);
				last_empty = i;
				auto layers = (it - last) / (sz + 2);

				last += layers;
				it -= layers * (sz + 1);

				if (it > last + 1)
				{
					if (sz == 0)
						last++;
					else
						zeros.push(0);
					it--;
				}
			}
		}

		assert(last == it || last + 1 == it);

		if (last == it)
			zeros.push(sz);
		last = it;

		sz++;
	}

	vector<ll> ans(arr.size());

	ans.back() = last;

	for (int i = (int) ans.size() - 2; i >= 0; i--)
		if (!zeros.empty() && zeros.top() == i)
			ans[i] = ans[i + 1];
		else
			ans[i] = ans[i + 1] - 1;

	assert(accumulate(arr.begin(), arr.end(), 0ll) == accumulate(ans.begin(), ans.end(), 0ll));

	for (auto it : ans)
		cout << it << ' ';
	cout << endl;
}


void gen(ostream &cout)
{
	const int n = 1e6;

	cout << n << endl;

	uniform_int_distribution<ll> uid(0, (ll) 1e12 - (n - 1));

	vector<ll> arr(n);

	for (auto &it : arr)
		it = uid(mt);

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] + i << ' ';
	cout << endl;
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

	int cnt = 0;

	while (true)
	{
		stringstream ss, out;

		gen(ss);

		solve(ss, out);

		cout << cnt++ << endl;
	}

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}